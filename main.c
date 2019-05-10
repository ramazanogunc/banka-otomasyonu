#include <stdio.h>
#include <stdlib.h>

char sayiKontrol;
int secim, mSirasi, hSirasi, temp, temp2, temp3;
int main()
{
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
            //Musteri Ekleme fonksiyonu cagrilacak.
            break;
        case 2:
            //Musteri silme fonksiyonu cagirilacak.
            break;
        case 3:
            system("CLS");
            printf("------------------------MUSTERI SEC------------------------\n");
            // musrteriler siralanacak ve musteri secimi olacak vsvs.
            printf("Musteri numaranizi giriniz:");
            while(1)
            {
                printf("--------------------MUSTERI ISLEM MENU-------------------\n");
                printf("1-Hesap Ekle\n");
                printf("2-Hesap Sil\n");
                printf("3-Hesap Sec\n\n");
                printf("9-Ust Menu\n");
                printf("0-Cikis\n");
                printf("Sayin ...... Hos Geldiniz. Islem Yapilan Musteri Numaraniz .......\n");//

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
                    break;
                case 2:
                     printf("------------------------HESAAP SÝLME------------------------\n");
                    break;
                case 3:
                    system("CLS");
                    printf("------------------------HESAP SEC------------------------\n");
                    // Hesaplar siralanacak.
                    printf("Hesap numaranizi giriniz:");
                    //scanf("%d",&temp);
                    //musteri aranacak ve indis numarasý hSirasi ye. bulunamazsa tekrar soracak.
                    while(1)
                    {
                        printf("-------------------HESAP ILSEM MENU-------------------\n");
                        printf("1-Para Cek\n");
                        printf("2-Para Yatir.\n");
                        printf("3-Havale\n");
                        printf("4-Hesap Raporu Al\n\n");
                        printf("9-Ust Menu\n");
                        printf("0-Cikis\n");
                        printf("Sayin .... Hos Geldiniz. Islem Yapilan Hesap Numaraniz .......\n");//

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
                            //tarih girisi
                            //cekme tutari
                            //para cekme fonksiyonu
                            break;
                        case 2:
                            //tarih girisi
                            //yatýrma tutarý girisi
                            //para yatýrma fonksiyonu
                            break;
                        case 3:
                            //tum hesap nolar ve isimleri listelenecek.
                            //hesap no girilmesi
                            //hesap no kontrolu
                            //havale tarihi
                            //havale tutarý
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
             printf("------------------------BANKA RAPORU------------------------\n");
            //banka raporu alma fonksiyonu cagýrma
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
