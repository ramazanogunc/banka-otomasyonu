#include <stdio.h>
#include <stdlib.h>

void ProgramAcilis();
void MusteriEkle();
void MusteriListele();
int MusteriIndisBul(int musteriNo);
void MusteriSil(int mSirasi);
void HesapAc(int mSirasi);
void HesapListele(int mSirasi);
int HesapIndisBul(int mSirasi, int hesapNo);
void HesapSil(int mSirasi, int hSirasi);
void ParaYatir(int mSirasi, int hSirasi,float para);
void TumunuListele();
int *HavaleHesapIndisBul(int hesapNo);
void Havale(int mSirasi, int hSirasi, int gmSirasi, int ghSirasi, float para);



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
Musteri musteriler[1000],okunan;
FILE *fp, *fp2;

float para;
char sayiKontrol, tarih[8];
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
            MusteriListele();
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
            MusteriListele();
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
                printf("Sayin %s Hos Geldiniz. Islem Yapilan Musteri Numaraniz %d\n"
                , musteriler[mSirasi].adi, musteriler[mSirasi].numarasi);//

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
                    HesapListele(mSirasi);
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
                    HesapListele(mSirasi);
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
                        printf("2-Para Yatir.\n");
                        printf("3-Havale\n");
                        printf("4-Hesap Raporu Al\n\n");
                        printf("9-Ust Menu\n");
                        printf("0-Cikis\n");
                        printf("Sayin %s Hos Geldiniz. Islem Yapilan Hesap Numaraniz %d\n"
                        ,musteriler[mSirasi].adi, musteriler[mSirasi].hesap[hSirasi].numarasi);//

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
                            //para cekme islemlerii

                            break;
                        case 2:
                            fflush(stdin);
						    printf("Yatirma tarhini giriniz(01012000 - formatinda giriniz): ");
    					    //scanf("%d",&rapor.tarih);
						    gets(tarih);
                            while(1)
						    {
							    for(i=0; i<8 ;i++)
							    {
								    if(tarih[i] < 48 || tarih[i] > 57)
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

                            printf("Yatiracaginiz miktari giriniz");
						    scanf("%f",&para);
                            ParaYatir(mSirasi,hSirasi,para);
                            break;
                        case 3:
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
								    if(tarih[i] < 48 || tarih[i] > 57)
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
                            //havale tarihi
                            //havale tutar�
                            //havale
                            break;
                        case 0:
                            exit(0);
                            break;
                        default:
                            printf("Hatali secim Yaptiniz!!!\n");
                            break;
                        }
                    }
                    break;
                case 0:
                    exit(0);
                    break;
                default:
                    printf("Hatali secim Yaptiniz!!!\n");
                    break;
                }
            }
            break;
        case 4:
             printf("\n------------------------BANKA RAPORU------------------------\n");
            //banka raporu alma fonksiyonu cag�rma
            break;
        case 0:
            exit(0);
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
		while(fread(&musteriler[musteriSayisi], sizeof(Musteri), 1, fp))
		{
			musteriSayisi++;
		}
        printf("bireysel musteri sayisi %d\n",musteriSayisi);
    }
    fclose(fp);
    fp = fopen("ticari.txt","r");
    if(fp != NULL)
    {
    	while(fread(&musteriler[musteriSayisi], sizeof(Musteri), 1, fp))
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
	scanf("%s",musteriler[musteriSayisi].adi);
    //gets(musteriler[musteriSayisi].adi);
	fflush(stdin);
	printf("Musteri tipini giriniz (bireysel->0 -- ticari->1):");
	scanf("%d",&musteriler[musteriSayisi].tipi);

	srand(time(NULL));
	temp=rand()%1000;
	printf(" %d uretilen\n",temp);
	for(i=0; i<musteriSayisi; i++)
	{
		if(temp == musteriler[i].numarasi)
		{
			temp=rand()%1000;
			printf("Ayni hesap no bulundu tekrar hesap no uretiliyor %d yeni uretilen",temp);
			i=0;
		}
	}
	musteriler[musteriSayisi].numarasi = temp;
	musteriler[musteriSayisi].hesapSayisi=0;
	if(musteriler[musteriSayisi].tipi==bireysel)
	{
		fp= fopen("bireysel.txt","a");
		fwrite(&musteriler[musteriSayisi], sizeof(Musteri), 1, fp);
		fclose(fp);
	}
	else
	{
		fp= fopen("ticari.txt","a");
		fwrite(&musteriler[musteriSayisi], sizeof(Musteri), 1, fp);
		fclose(fp);
	}
	musteriSayisi++;
	fflush(stdin);
	printf("Bankmiza HOS GELDINIZ\nMUSTERI NUMARANIZ %d \nLuten musteri numranizi saklayiniz.\n",musteriler[musteriSayisi-1].numarasi);
}

void MusteriListele()
{
    printf("\n----------Musteri Listesi----------\n");
    for (i = 0; i < musteriSayisi; i++)
    {
        if (musteriler[i].tipi == bireysel)
        {
            printf("%d - %s - bireysel\n",
            musteriler[i].numarasi, musteriler[i].adi);
        }
        else
        {
            printf("%d - %s - ticari\n",
            musteriler[i].numarasi, musteriler[i].adi);
        }
    }
}
int MusteriIndisBul(int musteriNo)
{
    for (i = 0; i < musteriSayisi; i++)
    {
        if(musteriler[i].numarasi == musteriNo)
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
            musteriler[i]=musteriler[i+1];
        }
        else
        {
            strcpy(musteriler[i].adi,"-1");
            musteriler[i].hesapSayisi-1;
            musteriler[i].numarasi=-1;
        }
    }
    musteriSayisi--;
    structDosyaYaz();
    printf("Musteri Silme isleminiz gerceklesmisitir.\n");
}

void HesapAc(int mSirasi)
{
    if(musteriler[mSirasi].hesapSayisi==10)
	{
		printf("\nToptam 10 adet hesabiniz bulunmaktadir. Daha fazla Hesap acamazsiniz.");

	}
    else
    {
        temp=rand()%10000;
	    for(i=0; i<musteriSayisi; i++)
	    {
		    for(j=0;j<musteriler[i].hesapSayisi; j++)
		    {
			    if(musteriler[i].hesap[j].numarasi == temp)
			    {
				    temp=rand()%10000;
				    i=0;
				    break;
			    }
		    }
	    }
        musteriler[mSirasi].hesap[musteriler[mSirasi].hesapSayisi].numarasi = temp;
	    musteriler[mSirasi].hesap[musteriler[mSirasi].hesapSayisi].bakiye=0.0;
	    musteriler[mSirasi].hesapSayisi++;
        structDosyaYaz();
        printf("\nSayin %s . Hesabiniz acilmistir. Yeni Hesap Numaraniz %d \nHesap bakiyeniz 0.0 TL'dir. \nLutfen hesap numaranizi kaybetmeyin!!!\n"
		,musteriler[mSirasi].adi, musteriler[mSirasi].hesap[musteriler[mSirasi].hesapSayisi-1].numarasi);
    }
}

void HesapListele(int mSirasi)
{
    printf("\n----------Hesap Listesi----------\n");
    for (i = 0; i < musteriler[mSirasi].hesapSayisi; i++)
    {
        printf("Hesap no: %d -> %.2f\n"
        ,musteriler[mSirasi].hesap[i].numarasi, musteriler[mSirasi].hesap[i].bakiye);
    }
}

int HesapIndisBul(int mSirasi, int hesapNo)
{
    for (i = 0; i < musteriler[mSirasi].hesapSayisi ; i++)
    {
        if(musteriler[mSirasi].hesap[i].numarasi == hesapNo)
        {
            return i;
        }
    }
    return -1;
}

void HesapSil(int mSirasi, int hSirasi)
{
    for (i = hSirasi; i < musteriler[mSirasi].hesapSayisi; i++)
    {
        if (musteriler[mSirasi].hesapSayisi<9)
        {
            musteriler[mSirasi].hesap[i]=musteriler[mSirasi].hesap[i+1];
        }
        else
        {

            musteriler[mSirasi].hesap[i].numarasi=-1;
            musteriler[mSirasi].hesap[i].bakiye=-1;
        }
    }
    musteriler[mSirasi].hesapSayisi--;
    structDosyaYaz();
    printf("Hesap Silme isleminiz gerceklesmisitir.\n");
}

void ParaYatir(int mSirasi,int hSirasi,float para)
{
    musteriler[mSirasi].hesap[hSirasi].bakiye+=para;
    rapor.hesapNo=musteriler[mSirasi].hesap[hSirasi].numarasi;
    rapor.tutar=para;
    rapor.gidenHesapNo=0;
    strcpy(rapor.islem,"Para Yatirma");
    structDosyaYaz();
    BankaRaporaYaz();
    printf("Para yatirma isleminiz gereceklesmistir. Yeni bakiyeniz %.2f \n"
    , musteriler[mSirasi].hesap[hSirasi].bakiye);

}

void TumunuListele()
{
    printf("\n----------Tum Musteriler ve Hesap Listesi----------\n");
    for(i=0; i < musteriSayisi; i++)
	{
		for ( j = 0; j < musteriler[i].hesapSayisi; j++)
        {
            printf("Hesap Sahibi %s Hesap No %d\n",musteriler[i].adi, musteriler[i].hesap[j].numarasi);
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
        for( j = 0; j < musteriler[i].hesapSayisi ; j++)
        {
            if ( musteriler[i].hesap[j].numarasi == hesapNo)
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
    if( musteriler[mSirasi].hesap[hSirasi].bakiye >= para )
    {
        musteriler[mSirasi].hesap[hSirasi].bakiye-=para;
        musteriler[gmSirasi].hesap[ghSirasi].bakiye+=para;
        rapor.hesapNo=musteriler[mSirasi].hesap[hSirasi].numarasi;
        rapor.gidenHesapNo= musteriler[gmSirasi].hesap[ghSirasi].numarasi;
        rapor.tutar=para;
        strcpy(rapor.islem,"Havale");
        structDosyaYaz();
        BankaRaporaYaz();
        printf("\nHavale isleminiz basariyla gerceklesmistir.\n");
        printf("%s kisinin %d nolu hesabinda kalan bakiye %.2f\n"
        ,musteriler[mSirasi].adi, musteriler[mSirasi].hesap[hSirasi].numarasi,musteriler[mSirasi].hesap[hSirasi].bakiye);
        printf("%s kisinin %d nolu hesabinda kalan bakiye %.2f\n"
        ,musteriler[gmSirasi].adi, musteriler[gmSirasi].hesap[ghSirasi].numarasi,musteriler[gmSirasi].hesap[ghSirasi].bakiye);
    }
    else
    {
        printf("\n!!Yetersiz Bakiyeden Dolayı isleminiz gerceklesememiztir!!!\n");
    }

}




void BankaRaporaYaz()
{
	fp=fopen("rapor.txt","a");
	fwrite(&rapor,sizeof(Rapor),1,fp);
	fclose(fp);
}
structDosyaYaz(){
	fp = fopen("bireysel.txt","w");
	fp2 = fopen("ticari.txt","w");
	for(i=0;i<musteriSayisi;i++)
	{
		if(musteriler[i].tipi == bireysel)
		{
			fwrite(&musteriler[i], sizeof(Musteri),1,fp);
		}
		else
		{
			fwrite(&musteriler[i], sizeof(Musteri),1,fp2);
		}
	}
	fclose(fp);
	fclose(fp2);
}
