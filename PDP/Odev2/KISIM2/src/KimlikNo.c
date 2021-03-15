/**
*
* @author Melih Ensar BARIŞIK ensar.barisik@ogr.sakarya.edu.tr / Ömer Can ÇALIŞIR omer.calisir@ogr.sakarya.edu.tr
* @since  25.04.2020
* <p>
*   Kimlik numarası oluşturulan kısım
* </p>
*/
#include "KimlikNo.h"
#include "Rastgele.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// nesne yönelimli benzetme için sözde kurucu fonksiyonu
KimlikNo KimlikNoUret()
{
	KimlikNo this;
	// struct için bellekte yer ayırma işlemi
	this=(KimlikNo)malloc(sizeof(struct KIMLIKNO));

	int length=11;

	// kimlik numarası değişkeni için bellekten yer ayırma işlemi
	this->identityNumbers=(int*)malloc(sizeof(int)*11);
	
	int i;
	for(i=0; i<length; i++) {this->identityNumbers[i] =0;}
	
	// fonksiyon göstericilerine oluşturulan
    // fonksiyonların adreslerinin verilmesi işlemi
	this->firstStepControlAndConstitute =&_firstStepControlAndConstitute;
	this->constituteIdentityNumber = &_constituteIdentityNumber;
	this->calculateTenthStep=&_calculateTenthStep;
	this->calculateEleventhNumber=&_calculateEleventhNumber;
	this->createIdentityNumber=&_createIdentityNumber;
	this->yokediciKimlikNo=&_yokediciKimlikNo;
	
	return this;
}


// ilk hanenin 0 olmaması durumu için atama ve kontrol işlemi
void _firstStepControlAndConstitute(const KimlikNo this,Rastgele R)
{
	int protector = 0;
	

	// random rakam üretimi
	protector = R->randomRakamUret(R,0,10);

		
	// üretilen rakamın 0 olmamasını sağlama işlemi
	// (kimlik no 0 ile başlayamaz)
	while(protector == 0)
	{
		
		protector = R->randomRakamUret(R,0,10);
	}
	// 0 olmadığı kesinleşen hanenin atanması
	this->identityNumbers[0]=protector;
	
	
	
}

// kimlik numarasındaki diğer 8 hanenin atanması işlemi
void _constituteIdentityNumber(const KimlikNo this,Rastgele R)
{
		
	int i;

    for(i=1; i<9; i++)
	{			
		this->identityNumbers[i]=R->randomRakamUret(R,0,10); 			
	}
              
}
	
// 10. basamağın kimlik no algoritması prensipleri uyarınca
// bulunması işlemi
void _calculateTenthStep(const KimlikNo this)
{
	int sumOddNumbers = 0;
    int sumEvenNumbers = 0;
        
	int i;
	// ilk 9 hane içinde dolaşmayı sağlayan for döngüsü
    for(i =0; i<9; i++)
    {
      	// tek basamakların toplamlarının bulunması
        if(i%2 == 0)
        {
        	sumOddNumbers+= this->identityNumbers[i];             
        }
        // çift basamakların toplamlarının bulunması
        else
        {
            sumEvenNumbers+=this->identityNumbers[i];           
        }
    }
    // teklerin 7 ile çarpılıp çiftlerden çıkarılması,
    // elde edilen sonucun 10 ile modunun onuncu basamağa atanması işlemi
   	sumOddNumbers=sumOddNumbers*7;
    this->identityNumbers[9] =(sumOddNumbers-sumEvenNumbers)%10;
      
}

// 11. basamağın kimlik no algoritması prensipleri uyarınca
// bulunması işlemi
void _calculateEleventhNumber(const KimlikNo this)
{
	int sumNumbers = 0;
	 
    int i;
    // ilk 10 hane içinde dolaşmayı sağlayan for döngüsü
    for(i =0; i<10; i++)
    {
    	// ilk 10 basamağın toplanması işlemi
    	sumNumbers+=this->identityNumbers[i];
		  
         
    }
	// toplamın 10 ile modunun onuncu basamağa atanması işlemi
	this->identityNumbers[10]=(sumNumbers%10);
	 
}

// verilen kimlik numarasının kontrolünü yapan fonksiyon
bool controlIdentityNumber(long long int identityNumbers)
{
	
	
	int sumOddNumbers =0;
    int sumEvenNumbers =0;
    int sumTopTenNumber =0;
        
		
	long long int kullanilanKimlikNo[11];
	int s;
	// int bir sayi olarak alınan kimlik numarasının
	// aynı tipte bir diziye atanması işlemi
	for(s=10; s>=0; s--)
	{
		kullanilanKimlikNo[s] = identityNumbers%10;
		identityNumbers=identityNumbers/10;
	}
	  
 
    // ilk basamağın sıfır olup olmadığının kontrolü
    if(kullanilanKimlikNo[0]!=0)
    {
		// son basamağın çift olup olmadığının kontrolü
        if(kullanilanKimlikNo[10]%2 == 0)				
        { 
	
			// ilk 9 basamakta dolaşmak için for döngüsü
			int i;
            for(i =0; i<9; i++) 
            {	
                // tek basamakların toplanması          
                if(i%2 ==0) 
                {
                	sumOddNumbers=sumOddNumbers + kullanilanKimlikNo[i];	 
				}
				// çift basamakların toplanması
                else
                {
                    sumEvenNumbers+=kullanilanKimlikNo[i];
                }                 
            }

            sumTopTenNumber = sumOddNumbers+sumEvenNumbers+kullanilanKimlikNo[9];
          	// teklerin toplamının 7 ile çarpımının çiftlerden çıkarılması işlemi
            int corollary = ((sumOddNumbers*7)-sumEvenNumbers);
            	
			
           
         	// kontrolde hesaplanan onuncu basamağın verilen kimlikle uyuşup uyuşmadığının kontrolü
        	if(corollary %10 == kullanilanKimlikNo[9])
        	{ 
        		// kontrolde hesaplanan onbirinci basamağın verilen kimlikle uyuşup uyuşmadığının kontrolü
            	if(sumTopTenNumber % 10 == kullanilanKimlikNo[10])
            	{        				                    
                	return true;
            	}
        	}
    	}
	}      
    
    return false;   
		
}


// kimlik oluşturma fonksiyonlarının senkronize çalışmasını sağlayan fonkisyon
void _createIdentityNumber(const KimlikNo this,Rastgele R) 
{
	this->firstStepControlAndConstitute(this,R);
    this->constituteIdentityNumber(this,R);
    this->calculateTenthStep(this);
    this->calculateEleventhNumber(this);
}

// bellekten alınan yerin geri teslimi için yıkıcı fonksiyon
void _yokediciKimlikNo(KimlikNo this)
{
	if(this==NULL) return;
	free(this->identityNumbers);
	free(this);	
}