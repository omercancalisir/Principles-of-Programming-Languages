/**
*
* @author Melih Ensar BARIŞIK ensar.barisik@ogr.sakarya.edu.tr / Ömer Can ÇALIŞIR omer.calisir@ogr.sakarya.edu.tr
* @since  25.04.2020
* <p>
*   İmei numarası oluşturulan kısım
* </p>
*/
#include "IMEINo.h"
#include "Rastgele.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>


// nesne yönelimli benzetme için sözde kurucu fonksiyonu
IMEINo IMEINoUret()
{
	IMEINo this;
    // struct için bellekte yer ayırma işlemi
	this=(IMEINo)malloc(sizeof(struct IMEINO));

	
	int i;
	
    // ilk değer ataması yapma işlemi
	for(i=0; i<this->length; i++) {this->IMEIS[i] =0;}
	

	// fonksiyon göstericilerine oluşturulan
    // fonksiyonların adreslerinin verilmesi işlemi
	this->calculateRecentDigit=&_calculateRecentDigit;
	this->assignRandomDigits=&_assignRandomDigits;
	this->createImeiNo=&_createImeiNo;
	this->getImeiNo = &_getImeiNo;
	this->yokediciIMEINo=&_yokediciIMEINo;


	return this;
}


// imeinonun ilk 14 hanesinin random oluşturulması işlemini gerçekleyen fonksiyon
void _assignRandomDigits(const IMEINo this, Rastgele R)
{
	
	
	int i;
	for(i=0; i<14; i++)
	{
		// üretilen random rakamların atanması işlemi
		this->IMEIS[i]= R->randomRakamUret(R,0,10);
	}
}

// verilen sayının basamakları toplamını döndürmeye yarayan fonksiyon
int _collectNumbers(int data)
    {
        int total =0;
        
        while(data != 0)
        {   
            // ilk basamağı toplama ekleyip bir sonraki basamak için sayıyı küçültme işlemi
            total+=(data%10);
            data = data/10;
        }
        
       return total;
      
        
    }
 // imei numarasının son basamağını algoritmaya uygun olarak
 // hesaplama işlemini gerçekleyen fonksiyon
 void _calculateRecentDigit(const IMEINo this)
 {
	  int control =0;
      int sum = 0;
       
		int i;
        // imei numarasının ilk 14 hanesinde dolaşmaya yarayan for döngüsü
        for(i = 0; i<14; i++)
        {
			
			
            if(i%2 ==0)
            {
            // imei numarasındaki tek basamakların toplanması işlemi
            int value = this->IMEIS[i];
            sum+=value;      
            }

            else
            {   
                // imei numarasındaki çift basamakların 2 ile çarpılarak toplanması işlemi
                int value = this->IMEIS[i];
                sum+=_collectNumbers(value*2);
            }
        }
        
	   // son hanenin atanması işlemi (son mod alma parantez içinin 10 çıkması olasılığına karşı yapıldı)
		this->IMEIS[14]=(10-(sum % 10 ))%10;
	
       
 }
 
// imeino yu oluşturan fonksiyonların senkronize çalışmasını sağlayan fonksiyon
void _createImeiNo(const IMEINo this, Rastgele R){
	this->assignRandomDigits(this,R);
	this->calculateRecentDigit(this);
}

// imeino dizisini döndüren get fonksiyonu
int* _getImeiNo(const IMEINo this)
{
	return this->IMEIS;
}
 
// imeino nun doğruluğunu kontrol eden fonksiyon
bool controlIMEI(int *kontrolEdilecekNumara,int uzunluk)
 {
         // imei numarasının 15 haneli olup olmadığının kontrolü
         if(uzunluk != 15)
        {
            return false;
        }


        // basamakların kurala uygun olarak toplamının bulunması işlemleri
        int toplam = 0;
        for (int i = 0; i < uzunluk - 1; i++)
        {
            if (i % 2 == 0) {
                toplam+=kontrolEdilecekNumara[i];
            } else {

                 toplam+=_collectNumbers(kontrolEdilecekNumara[i]*2);
            }
        }
        


        // kontrol hanesinin bulunmasına yarayan matematik işlemi
        int kontrolHanesi = (10 - (toplam % 10)) % 10;

       
       // son hanenin kontrolünün yapılması işlemi
        if (kontrolHanesi==kontrolEdilecekNumara[14]){
            return true;
        }

        return false; 
     
    }

// bellekten alınan yerin geri teslimi için yıkıcı fonksiyon
void _yokediciIMEINo(IMEINo this)
{
	if(this==NULL);
	free(this);
}	