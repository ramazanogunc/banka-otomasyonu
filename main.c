#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ProgramAcilis();
void MusteriEkle();
int MusteriListele();
int MusteriIndisBul(int musteriNo);
void MusteriSil(int mSirasi);
void HesapAc(int mSirasi);
int HesapListele(int mSirasi);
int HesapIndisBul(int mSirasi, int hesapNo);
void HesapSil(int mSirasi, int hSirasi);
void ParaYatir(int mSirasi, int hSirasi,float para);
void ParaCek(int mSirasi, int hSirasi,float para, int tarih);
void TumunuListele();
int *HavaleHesapIndisBul(int hesapNo);
void Havale(int mSirasi, int hSirasi, int gmSirasi, int ghSirasi, float para);
void BankaRaporuAl();
void HesapOzeti(int temp, int temp2 ,int mSirasi ,int hSirasi);
void BankaRaporaYaz();
void structDosyaYaz();

enum MusteriTipi
{
	bireysel = 0,
	ticari = 1
};
typedef struct
{
	int numarasi;
	float bakiye;
}Hesap;
typedef struct
{
	char adi[30];
	int numarasi;
	enum MusteriTipi tipi;
	int hesapSayisi;
	Hesap hesap[10];
}Musteri;

typedef struct
{
	int tarih;
	int hesapNo;
	int gidenHesapNo;
	char islem[20];
	float tutar;
}Rapor;

Rapor rapor;
Musteri musteriler[1000], *mp = musteriler;
FILE *fp, *fp2;

float para;
char sayiKontrol, tarih[8], tarih2[8] ,*tp1 = tarih, *tp2 = tarih2;
int i, j, secim, mSirasi, hSirasi, temp, temp2, temp3, musteriSayisi=0, raporSayisi=0;
int main()
{    
    ProgramAcilis();
    while(1)
    {
        printf("------------------------BANKA MENUSU------------------------\n");
        printf("1-Musteri Ekle\n");
        printf("2-Musteri Sil\n");
        printf("3-Musteri Sec\n");
        printf("4-Banka Raporu Al\n");
        printf("0-Cikis.\n");
        printf("Seciminizi giriniz:");
        scanf("%d",&secim);

        switch ( secim )
        {
        case 1:
            MusteriEkle();
            break;
        case 2:
            if(MusteriListele() == 0) break;
            printf("!!!ONEMLI UYARI!!!\nMusteriyi sildiginizde Tum Hesaplari ve Bakiyeleri de silinir.\n");
            printf("Silinecek musteri numaranizi giriniz:");
            scanf("%d",&temp);
            while(1)
            {
                mSirasi=MusteriIndisBul(temp);
                if(mSirasi == -1)
                {
                    printf("Hatali musteri no girdiniz. Lutfen Tekrar girin:");
                    scanf("%d",&temp);
                    mSirasi=MusteriIndisBul(temp);
                }
                else break;
            }
            MusteriSil(mSirasi);
            break;
        case 3:
            system("CLS");
            printf("------------------------MUSTERI SEC------------------------\n");
            if(MusteriListele() == 0) break;
            printf("Musteri numaranizi giriniz:");
            scanf("%d",&temp);
            while(1)
            {
                mSirasi=MusteriIndisBul(temp);
                if(mSirasi == -1)
                {
                    printf("Hatali musteri no girdiniz. Lutfen Tekrar girin:");
                    scanf("%d",&temp);
                    mSirasi=MusteriIndisBul(temp);
                }
                else break;
            }

            while(1)
            {
                printf("\n--------------------MUSTERI ISLEM MENU-------------------\n");
                printf("1-Hesap Ekle\n");
                printf("2-Hesap Sil\n");
                printf("3-Hesap Sec\n\n");
                printf("9-Ust Menu\n");
                printf("0-Cikis\n");
                printf("\n------------------------------------------------------------\n");
                printf("Sayin %s Hos Geldiniz. \nIslem Yapilan Musteri Numaraniz %d"
                , (mp+mSirasi)->adi, (mp+mSirasi)->numarasi);
                printf("\n------------------------------------------------------------\n");

               while(1)
               {
                    fflush(stdin);
                    printf("Seciminizi giriniz:");
                    scanf("%c",&sayiKontrol);
                    if(sayiKontrol >= 48 && sayiKontrol <= 57)
                    {
                        secim = atoi(&sayiKontrol);
                        break;
                    }
                    else
                    {
                        printf("LUTEN SAYI GIR!!!!!!\n");
                    }
                }

                if ( secim == 9 )
                {
                    system("CLS");
                    break;
                }

                switch ( secim )
                {
                case 1:
                    HesapAc(mSirasi);
                    break;
                case 2:
                    printf("\n------------------------HESAP SILME------------------------\n");
                    if(HesapListele(mSirasi) == 0) break;
                    printf("!!!ONEMLI UYARI!!!\nHesabi sildiginizde Bakiyesi de silinir.\n");
                    printf("Silinecek HESAP numaranizi giriniz:");
                    scanf("%d",&temp);
                    while(1)
                    {
                        hSirasi=HesapIndisBul(mSirasi,temp);
                        if(hSirasi == -1)
                        {
                            printf("Hatali HESAP no girdiniz. Lutfen Tekrar girin:");
                            scanf("%d",&temp);
                            hSirasi=HesapIndisBul(mSirasi,temp);
                        }
                        else break;
                    }
                    HesapSil(mSirasi,hSirasi);


                    break;
                case 3:
                    system("CLS");
                    printf("------------------------HESAP SEC------------------------\n");
                    if(HesapListele(mSirasi) == 0) break;
                    printf("Hesap numaranizi giriniz:");
                    scanf("%d",&temp);
                    while(1)
                    {
                        hSirasi=HesapIndisBul(mSirasi,temp);
                        if(hSirasi == -1)
                        {
                            printf("Hatali HESAP no girdiniz. Lutfen Tekrar girin:");
                            scanf("%d",&temp);
                            hSirasi=HesapIndisBul(mSirasi,temp);
                        }
                        else break;
                    }
                    while(1)
                    {
                        printf("\n-------------------HESAP ILSEM MENU-------------------\n");
                        printf("1-Para Cek\n");
                        printf("2-Para Yatir\n");
                        printf("3-Havale\n");
                        printf("4-Hesap Raporu Al\n\n");
                        printf("9-Ust Menu\n");
                        printf("0-Cikis\n");
                        printf("\n------------------------------------------------------------\n");
                        printf("Sayin %s Hos Geldiniz. \nIslem Yapilan Hesap Numaraniz %d \nHesap Bakiyeniz %.2f"
                        ,(mp+mSirasi)->adi, (mp+mSirasi)->hesap[hSirasi].numarasi , (mp+mSirasi)->hesap[hSirasi].bakiye);
                        printf("\n------------------------------------------------------------\n");

                        while(1)
                        {
                            fflush(stdin);
                            printf("Seciminizi giriniz:");
                            scanf("%c",&sayiKontrol);
                            if(sayiKontrol >= 48 && sayiKontrol <= 57)
                            {
                                secim = atoi(&sayiKontrol);
                                break;
                            }
                            else
                            {
                                printf("LUTEN SAYI GIR!!!!!!\n");
                            }
                        }

                        if ( secim == 9 )
                        {
                            system("CLS");
                            break;
                        }
                        switch ( secim )
                        {
                        case 1:
                            printf("\n--------------------PARA CEKME--------------------\n");
                            fflush(stdin);
						    printf("Cekme tarhini giriniz(01012000 - formatinda giriniz): ");
    					    //scanf("%d",&rapor.tarih);
						    gets(tarih);
                            while(1)
						    {
							    for(i=0; i<8 ;i++)
							    {
								    if(*(tp1 + i) < 48 || *(tp1 + i) > 57)
								    {
									    break;
								    }
							    }
							    if(i==8)
							    {
								    temp = atoi(tarih);
								    break;
							    }
							    else
							    {
								    printf("Girdiginiz deger tarih sayi degildir.\n");
								    fflush(stdin);
								    printf("Cekme tarhini giriniz: ");
								    gets(tarih);
							    }
						    }

                            while (1)
                            {
                            printf("Cekeceginiz miktari giriniz : ");
						    scanf("%f",&para);
                                if ( (mp+mSirasi)->tipi == bireysel)
                                {
                                    if( para <= 750)
                                    {
                                        ParaCek(mSirasi, hSirasi, para, temp);
                                        break;
                                    }
                                    else
                                    {
                                        printf("\nGunuk para cekme limiti 750 TL dir \n");
                                        printf("Yeniden miktar girin (istemiyorsaniz 0 girin) ");
                                        scanf("%f",&para);
                                        if (para == 0) break;
                                        else
                                        {
                                            ParaCek(mSirasi, hSirasi, para, temp);
                                            break;
                                        }


                                    }
                                }
                                if ( (mp+mSirasi)->tipi == ticari)
                                {
                                    if( para <= 1500)
                                    {
                                        ParaCek(mSirasi, hSirasi, para, temp);
                                        break;
                                    }
                                    else
                                    {
                                        printf("\nGunuk para cekme limiti 1500 TL dir\n");
                                        printf("Yeniden miktar girin (istemiyorsaniz 0 girin) ");
                                        scanf("%f",&para);
                                        if (para == 0) break;
                                        else
                                        {
                                            ParaCek(mSirasi, hSirasi, para, temp);
                                            break;
                                        }
                                    }
                                }
                            }
                            break;
                        case 2:
                            printf("\n--------------------PARA YATIRMA--------------------\n");
                            fflush(stdin);
						    printf("Yatirma tarhini giriniz(01012000 - formatinda giriniz): ");
    					    //scanf("%d",&rapor.tarih);
						    gets(tarih);
                            while(1)
						    {
							    for(i=0; i<8 ;i++)
							    {
								    if(*(tp1 + i) < 48 || *(tp1 + i) > 57)
								    {
									    break;
								    }
							    }
							    if(i==8)
							    {
								    rapor.tarih = atoi(tarih);
								    break;
							    }
							    else
							    {
								    printf("Girdiginiz deger tarih sayi degildir.\n");
								    fflush(stdin);
								    printf("Yatirma tarhini giriniz: ");
								    gets(tarih);
							    }
						    }

                            printf("Yatiracaginiz miktari giriniz : ");
						    scanf("%f",&para);
                            ParaYatir(mSirasi,hSirasi,para);
                            break;
                        case 3:
                            printf("\n--------------------HAVALE--------------------\n");
                            TumunuListele();
                            printf("\nPara Gondereceginiz Hesap numarasini giriniz:");
	                        scanf("%d",&temp);
	                        int *p;
                            while(1)
                            {
                                p=HavaleHesapIndisBul(temp);
                                if(*p == -1)
                                {
                                    printf("Hatali HESAP no girdiniz. Lutfen Tekrar girin:");
                                    scanf("%d",&temp);
                                    p=HavaleHesapIndisBul(temp);
                                }
                                else break;
                            }
                            temp2=(*p);
                            temp3=(*(p+1));
                            fflush(stdin);
						    printf("Havale tarhini giriniz(01012000 - formatinda giriniz): ");
    					    //scanf("%d",&rapor.tarih);
						    gets(tarih);
                            while(1)
						    {
							    for(i=0; i<8 ;i++)
							    {
								    if(*(tp1 + i) < 48 || *(tp1 + i) > 57)
								    {
									    break;
								    }
							    }
							    if(i==8)
							    {
								    rapor.tarih = atoi(tarih);
								    break;
							    }
							    else
							    {
								    printf("Girdiginiz deger tarih sayi degildir.\n");
								    fflush(stdin);
								    printf("Havale tarhini giriniz: ");
								    gets(tarih);
							    }
						    }

                            printf("Gondereceginiz miktari giriniz");
						    scanf("%f",&para);
                            Havale(mSirasi, hSirasi, temp2, temp3, para);
                            break;
                        case 4:
                            printf("\n--------------------HESAP OZETI--------------------\n");
                            fflush(stdin);
						    printf("Baslangic tarhini giriniz(01012000 - formatinda giriniz): ");
    					    //scanf("%d",&rapor.tarih);
						    gets(tarih);
                            while(1)
						    {
							    for(i=0; i<8 ;i++)
							    {
								    if(*(tp1 + i) < 48 || *(tp1 + i) > 57)
								    {
									    break;
								    }
							    }
							    if(i==8)
							    {
								    temp = atoi(tarih);
								    break;
							    }
							    else
							    {
								    printf("Girdiginiz deger tarih sayi degildir.\n");
								    fflush(stdin);
								    printf("Baslangic tarhini giriniz: ");
								    gets(tarih);
							    }
						    }

                            printf("Bitis tarhini giriniz(01012000 - formatinda giriniz): ");
    					    //scanf("%d",&rapor.tarih);
						    gets(tarih2);
                            while(1)
						    {
							    for(i=0; i<8 ;i++)
							    {
								    if(*(tp2 + i) < 48 || *(tp2 + i) > 57)
								    {
									    break;
								    }
							    }
							    if(i==8)
							    {
								    temp2 = atoi(tarih2);
								    break;
							    }
							    else
							    {
								    printf("Girdiginiz deger tarih sayi degildir.\n");
								    fflush(stdin);
								    printf("Bitis tarhini giriniz: ");
								    gets(tarih2);
							    }
						    }

                            HesapOzeti(temp, temp2, mSirasi, hSirasi);
                            break;

                        case 0:
                            return 0;;
                            break;
                        default:
                            printf("Hatali secim Yaptiniz!!!\n");
                            break;
                        }
                    }
                    break;
                case 0:
                    return 0;;
                    break;
                default:
                    printf("Hatali secim Yaptiniz!!!\n");
                    break;
                }
            }
            break;
        case 4:
             printf("\n------------------------BANKA RAPORU------------------------\n");
            BankaRaporuAl();
            break;
        case 0:
            return 0;;
            break;
        default:
            printf("Hatali secim Yaptiniz!!!\n");
            break;
        }
    }
    return 0;
}

void ProgramAcilis()
{
	fp = fopen("bireysel.txt","r");
	if(fp != NULL)
	{
		while(fread((mp+musteriSayisi), sizeof(Musteri), 1, fp))
		{
			musteriSayisi++;
		}
        printf("bireysel musteri sayisi %d\n",musteriSayisi);
    }
    fclose(fp);
    fp = fopen("ticari.txt","r");
    if(fp != NULL)
    {
    	while(fread((mp+musteriSayisi), sizeof(Musteri), 1, fp))
    	{
    		musteriSayisi++;
    	}
    	printf("Tum Musteri sayisi %d\n",musteriSayisi);
    }
    fclose(fp);
}

void MusteriEkle()
{
	printf("\n----------------MUSTERI  EKLEME----------------\n");
	fflush(stdin);
	printf("Isminizi giriniz:");
	scanf("%s",(mp+musteriSayisi)->adi);
    //gets((mp+musteriSayisi)->adi);
	fflush(stdin);
	printf("Musteri tipini giriniz (bireysel->0 -- ticari->1):");
	scanf("%d",&(mp+musteriSayisi)->tipi);

	srand(time(NULL));
	temp=rand()%1000;
	printf(" %d uretilen\n",temp);
	for(i=0; i<musteriSayisi; i++)
	{
		if(temp == (mp+i)->numarasi)
		{
			temp=rand()%1000;
			printf("Ayni hesap no bulundu tekrar hesap no uretiliyor %d yeni uretilen",temp);
			i=0;
		}
	}
	(mp+musteriSayisi)->numarasi = temp;
	(mp+musteriSayisi)->hesapSayisi=0;
	if((mp+musteriSayisi)->tipi==bireysel)
	{
		fp= fopen("bireysel.txt","a");
		fwrite((mp+musteriSayisi), sizeof(Musteri), 1, fp);
		fclose(fp);
	}
	else
	{
		fp= fopen("ticari.txt","a");
		fwrite((mp+musteriSayisi), sizeof(Musteri), 1, fp);
		fclose(fp);
	}
	musteriSayisi++;
	fflush(stdin);
	printf("Bankmiza HOS GELDINIZ\nMUSTERI NUMARANIZ %d \nLuten musteri numranizi saklayiniz.\n",(mp+musteriSayisi-1)->numarasi);
}

int MusteriListele()
{
    if( musteriSayisi == 0)
    {
        printf("\nHic Musteri Kaydi Bulunamadi!!!\n\n");
        return 0;
    }
    printf("\n----------Musteri Listesi----------\n");
    for (i = 0; i < musteriSayisi; i++)
    {
        if ((mp+i)->tipi == bireysel)
        {
            printf("%d - %s - bireysel\n",
            (mp+i)->numarasi, (mp+i)->adi);
        }
        else
        {
            printf("%d - %s - ticari\n",
            (mp+i)->numarasi, (mp+i)->adi);
        }
    }
    return 1;
}
int MusteriIndisBul(int musteriNo)
{
    for (i = 0; i < musteriSayisi; i++)
    {
        if((mp+i)->numarasi == musteriNo)
        {
            return i;
        }
    }
    return -1;

}

void MusteriSil(int mSirasi)
{
    for (i = mSirasi; i < musteriSayisi; i++)
    {
        if (musteriSayisi<999)
        {
            *(mp+i)=*(mp+i+1);
        }
        else
        {
            strcpy((mp+i)->adi,"-1");
            (mp+i)->hesapSayisi-1;
            (mp+i)->numarasi=-1;
        }
    }
    musteriSayisi--;
    structDosyaYaz();
    printf("Musteri Silme isleminiz gerceklesmisitir.\n");
}

void HesapAc(int mSirasi)
{
    if((mp+mSirasi)->hesapSayisi==10)
	{
		printf("\nToptam 10 adet hesabiniz bulunmaktadir. Daha fazla Hesap acamazsiniz.");

	}
    else
    {
        temp=rand()%10000;
	    for(i=0; i<musteriSayisi; i++)
	    {
		    for(j=0;j<(mp+i)->hesapSayisi; j++)
		    {
			    if((mp+i)->hesap[j].numarasi == temp)
			    {
				    temp=rand()%10000;
				    i=0;
				    break;
			    }
		    }
	    }
        (mp+mSirasi)->hesap[(mp+mSirasi)->hesapSayisi].numarasi = temp;
	    (mp+mSirasi)->hesap[(mp+mSirasi)->hesapSayisi].bakiye=0.0;
	    (mp+mSirasi)->hesapSayisi++;
        structDosyaYaz();
        printf("\nSayin %s . Hesabiniz acilmistir. Yeni Hesap Numaraniz %d \nHesap bakiyeniz 0.0 TL'dir. \nLutfen hesap numaranizi kaybetmeyin!!!\n"
		,(mp+mSirasi)->adi, (mp+mSirasi)->hesap[(mp+mSirasi)->hesapSayisi-1].numarasi);
    }
}

int HesapListele(int mSirasi)
{
    printf("\n----------Hesap Listesi----------\n");
    if( (mp+mSirasi)->hesapSayisi == 0)
    {
        printf("\nHic Hesap Kaydi Bulunamadi!!!\n\n");
        return 0;
    }
    for (i = 0; i < (mp+mSirasi)->hesapSayisi; i++)
    {
        printf("Hesap no: %d -> %.2f\n"
        ,(mp+mSirasi)->hesap[i].numarasi, (mp+mSirasi)->hesap[i].bakiye);
    }
    return 1;

}

int HesapIndisBul(int mSirasi, int hesapNo)
{
    for (i = 0; i < (mp+mSirasi)->hesapSayisi ; i++)
    {
        if((mp+mSirasi)->hesap[i].numarasi == hesapNo)
        {
            return i;
        }
    }
    return -1;
}

void HesapSil(int mSirasi, int hSirasi)
{
    for (i = hSirasi; i < (mp+mSirasi)->hesapSayisi; i++)
    {
        if ((mp+mSirasi)->hesapSayisi<9)
        {
            (mp+mSirasi)->hesap[i]=(mp+mSirasi)->hesap[i+1];
        }
        else
        {

            (mp+mSirasi)->hesap[i].numarasi=-1;
            (mp+mSirasi)->hesap[i].bakiye=-1;
        }
    }
    (mp+mSirasi)->hesapSayisi--;
    structDosyaYaz();
    printf("Hesap Silme isleminiz gerceklesmisitir.\n");
}

void ParaYatir(int mSirasi,int hSirasi,float para)
{
    (mp+mSirasi)->hesap[hSirasi].bakiye+=para;
    rapor.hesapNo=(mp+mSirasi)->hesap[hSirasi].numarasi;
    rapor.tutar=para;
    rapor.gidenHesapNo=0;
    strcpy(rapor.islem,"Para Yatirma");
    structDosyaYaz();
    BankaRaporaYaz();
    printf("Para yatirma isleminiz gereceklesmistir. Yeni bakiyeniz %.2f \n"
    , (mp+mSirasi)->hesap[hSirasi].bakiye);

}

void ParaCek(int mSirasi, int hSirasi,float para, int tarih)
{
    char a='E';
    
    float toplam=0.0;
    temp3=0;

    if ((mp+mSirasi)->hesap[hSirasi].bakiye < para)
    {

        fflush(stdin);
        printf("\nYetersiz Bakiye. Ek Hesaptan cekilsin mi?(e,h) ");
        scanf("%c",&a);
        temp3 = -1;
    }
    if (toupper(a) == 'E')
    {
        temp3=0;
        fp = fopen("log.txt","r");
        while (fread(&rapor, sizeof(Rapor),1,fp))
        {
            if(rapor.hesapNo == (mp+mSirasi)->hesap[hSirasi].numarasi && temp == rapor.tarih)
            {
                if (strcmp(rapor.islem,"Para Cekme") == 0)
                {
                    toplam+=rapor.tutar;
                    if ((mp+mSirasi)->tipi == bireysel)
                    {
                        if (toplam+para > 750)
                        {
                            printf("\nGunluk para cekme limitini astiniz. %.2f \n",toplam+para);
                            temp3=-1;
                        }
                    }
                    else
                    {
                        if (toplam+para > 1500)
                        {
                            printf("\nGunluk para cekme limitini astiniz. %.2f \n",toplam+para);
                            temp3=-1;
                        }
                    }
                }
            }
        }
        fclose(fp);
    }
    else
    {
        temp3=-1;
    }
    
    if(temp3 != -1)
    {
        (mp+mSirasi)->hesap[hSirasi].bakiye-=para;
        rapor.tarih=tarih;
        rapor.hesapNo=(mp+mSirasi)->hesap[hSirasi].numarasi;
        strcpy(rapor.islem,"Para Cekme");
        rapor.gidenHesapNo=0;
        rapor.tutar=para;
        BankaRaporaYaz();
        structDosyaYaz();
        printf("\nPara Cekme isleminiz gereceklesmistir. Yeni bakiyeniz %.2f \n"
        , (mp+mSirasi)->hesap[hSirasi].bakiye);
    }
}

void TumunuListele()
{
    printf("\n----------Tum Musteriler ve Hesap Listesi----------\n");
    for(i=0; i < musteriSayisi; i++)
	{
		for ( j = 0; j < (mp+i)->hesapSayisi; j++)
        {
            printf("Hesap Sahibi %s Hesap No %d\n",(mp+i)->adi, (mp+i)->hesap[j].numarasi);
        }
	}
}

int *HavaleHesapIndisBul(int hesapNo)
{
    int indisler[2],p;
    p=indisler;
    int gecici=-1;
    for (i = 0; i < musteriSayisi; i++)
    {
        for( j = 0; j < (mp+i)->hesapSayisi ; j++)
        {
            if ( (mp+i)->hesap[j].numarasi == hesapNo)
            {
                indisler[0]=i;
                indisler[1]=j;
                return p;
            }
        }
    }
    p=&gecici;
    return p;

}
void Havale(int mSirasi, int hSirasi, int gmSirasi, int ghSirasi, float para)
{
    if( (mp+mSirasi)->hesap[hSirasi].bakiye >= para )
    {
        (mp+mSirasi)->hesap[hSirasi].bakiye-=para;
        rapor.hesapNo=(mp+mSirasi)->hesap[hSirasi].numarasi;
        rapor.gidenHesapNo= (mp+gmSirasi)->hesap[ghSirasi].numarasi;

        if ((mp+mSirasi)->tipi == bireysel)
        {
            (mp+gmSirasi)->hesap[ghSirasi].bakiye+=(para-(para*0.02));
            rapor.tutar=(para-(para*0.02));
        }

        else
        {
            (mp+gmSirasi)->hesap[ghSirasi].bakiye+=para;
            rapor.tutar=para;
        }

        strcpy(rapor.islem,"Havale");
        structDosyaYaz();
        BankaRaporaYaz();
        printf("\nHavale isleminiz basariyla gerceklesmistir.\n");
        printf("%s kisinin %d nolu hesabinda kalan bakiye %.2f\n"
        ,(mp+mSirasi)->adi, (mp+mSirasi)->hesap[hSirasi].numarasi,(mp+mSirasi)->hesap[hSirasi].bakiye);
        printf("%s kisinin %d nolu hesabinda kalan bakiye %.2f\n"
        ,(mp+gmSirasi)->adi, (mp+gmSirasi)->hesap[ghSirasi].numarasi,(mp+gmSirasi)->hesap[ghSirasi].bakiye);
    }
    else
    {
        printf("\n!!Yetersiz Bakiyeden Dolayi isleminiz gerceklesememiztir!!!\n");
    }

}

void BankaRaporuAl()
{
	double toplam=0.0 , gelen=0.0, giden=0.0;;
	for(i=0;i<musteriSayisi;i++)
	{
		for( j = 0; j<(mp+i)->hesapSayisi; j++ )
		{
			toplam+=(mp+i)->hesap[j].bakiye;
		}
	}
	fp= fopen("log.txt","r");
	printf("  TARIH       ISLEM       HESAP NO    GIDEN HESAP NO       TUTARI\n");
	while(fread(&rapor,sizeof(Rapor),1,fp)==1)
	{
        if (strcmp(rapor.islem,"Para Cekme") == 0)
        {
            giden+=rapor.tutar;
        }
        if (strcmp(rapor.islem,"Para Yatirma") == 0)
        {
            gelen+=rapor.tutar;
        }

		printf("%8d%15s     %4d        %4d               %.2f\n"
			,rapor.tarih, rapor.islem, rapor.hesapNo, rapor.gidenHesapNo, rapor.tutar);
	}

    fclose(fp);
	printf("------------------------------------------\nBankada bulunana toplam para miktari %.2lf\n",toplam);
	printf("Bankadan giden para miktari %.2lf\n", giden);
	printf("Bankaya gelen para miktari %.2lf\n\n", gelen);
    fclose(fp);
    fp2 = fopen("rapor.txt","w"); 
    fprintf(fp2,"-------------------BANKA RAPORU-----------------------\nBankada bulunana toplam para miktari %.2lf\n",toplam);
	fprintf(fp2,"Bankadan giden para miktari %.2lf\n", giden);
	fprintf(fp2,"Bankaya gelen para miktari %.2lf\n\n", gelen);
	fclose(fp2);
}
void HesapOzeti(int temp, int temp2 ,int mSirasi ,int hSirasi)
{
    fp = fopen("log.txt","r");
    fp2 = fopen("dekont.txt","w");
    fprintf(fp2,"-----------------------------DEKONT---------------------------\n");
    fprintf(fp2,"  TARIH       ISLEM       HESAP NO    GIDEN HESAP NO       TUTARI\n");
    printf("\n-----------------------------DEKONT---------------------------\n");
    printf("  TARIH       ISLEM       HESAP NO    GIDEN HESAP NO       TUTARI\n");
    while (fread(&rapor, sizeof(Rapor),1,fp))
    {
        if(rapor.hesapNo == (mp+mSirasi)->hesap[hSirasi].numarasi || rapor.gidenHesapNo == (mp+mSirasi)->hesap[hSirasi].numarasi)
        {
            if(rapor.tarih >= temp && rapor.tarih <= temp2)
            {
                printf("%8d%15s     %4d        %4d               %.2f\n"
			    ,rapor.tarih, rapor.islem, rapor.hesapNo, rapor.gidenHesapNo, rapor.tutar);
                fprintf(fp2,"%8d%15s     %4d        %4d               %.2f\n"
			    ,rapor.tarih, rapor.islem, rapor.hesapNo, rapor.gidenHesapNo, rapor.tutar);
            }
        }
    }
    fclose(fp);
    fclose(fp2);
}



void BankaRaporaYaz()
{
	fp=fopen("log.txt","a");
	fwrite(&rapor,sizeof(Rapor),1,fp);
	fclose(fp);
}
structDosyaYaz(){
	fp = fopen("bireysel.txt","w");
	fp2 = fopen("ticari.txt","w");
	for(i=0;i<musteriSayisi;i++)
	{
		if((mp+i)->tipi == bireysel)
		{
			fwrite((mp+i), sizeof(Musteri),1,fp);
		}
		else
		{
			fwrite((mp+i), sizeof(Musteri),1,fp2);
		}
	}
	fclose(fp);
	fclose(fp2);
}
