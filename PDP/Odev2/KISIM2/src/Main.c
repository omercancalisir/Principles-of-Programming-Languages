/**
*
* @author Melih Ensar BARIŞIK ensar.barisik@ogr.sakarya.edu.tr / Ömer Can ÇALIŞIR oomer.calisir@ogr.sakarya.edu.tr
* @since  25.04.2020
* <p>
*  Ödevin çalıştırıldığı ana kısım
* </p>
*/
#include "Rastgele.h"
#include <stdio.h>
#include "KimlikNo.h"
#include "IMEINo.h"
#include "Telefon.h"
#include "RastgeleKisi.h"
#include "ReadFile.h"
#include "WriteFile.h"
#include "Control.h"
#include<time.h>

int main(){
	
	
	Rastgele Rast = RastgeleOlustur();
                   
	char cevap=' ';
    do {
		printf("1. Rastgele Kisi Uret   2. Uretilmis Dosyayi Kontrol Et   3. Cikis");
		printf("\n");
        scanf("%s",&cevap);
            
            
        if (cevap=='1') 
		{
                 
            printf("Uretilecek Kisi Sayisi :");
            int sayi;
            scanf("%d",&sayi);
               
            RastgeleKisi RK = RastgeleKisiOlustur(sayi);
            RK->kisiUret(RK,Rast);
            RK->yokediciRastgeleKisi(RK);
                

        } 
			
		else if (cevap=='2') 
		{
            Control C = ControlOlustur();
			C->chooseInformationToCheck(C);
			C->yokediciControl(C);
                
        }
		else if(cevap =='3')
		{
			Rast->yokediciRastgele(Rast);
			
		}

   	} while (!(cevap=='3')); 




    return 0;
}