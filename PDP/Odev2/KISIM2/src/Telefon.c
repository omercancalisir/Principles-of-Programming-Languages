/**
*
* @author Melih Ensar BARIŞIK ensar.barisik@ogr.sakarya.edu.tr / Ömer Can ÇALIŞIR omer.calisir@ogr.sakarya.edu.tr
* @since  25.04.2020
* <p>
*  Telefon oluşturulan kısım
* </p>
*/

#include "Rastgele.h"
#include "Telefon.h"
#include "IMEINo.h"
#include <stdlib.h>
#include <stdio.h>

// nesne yönelimli benzetme için sözde kurucu fonksiyonu
Telefon telefonOlustur()
{
	Telefon this;
	// struct için bellekte yer ayırma işlemi
	this = (Telefon)malloc(sizeof(struct TELEFON));
	int length=9;
	
	// sözde imeino referansına, sözde imeino nesnesi atama işlemi
	this->IN=IMEINoUret();
	
	// ilk değer atamaları için for döngüsü
	int i;
	for(i=0; i<length; i++) {this->telefonNumber[i] =0;}
	
	// fonksiyon göstericilerine oluşturulan
    // fonksiyonların adreslerinin verilmesi işlemi 
	this->telefonVeIMEINoUret=&_telefonVeIMEINoUret;
	this->createImei=&_createImei;
	this->yokediciTelefon=&_yokediciTelefon;
	
	
	return this;
}

// telefon ve imeino üreten fonksiyon
void _telefonVeIMEINoUret(const Telefon this, Rastgele R)
{      
	// Türkiye'de tanımlı operatorlerin alan kodları
    int operatorler[31]={501, 505, 506, 507, 551, 552,
    					 553, 554, 555, 559,
    					 530, 531, 532, 533, 534, 535, 536, 537, 538, 539, 561,
		                 540, 541, 542, 543, 544, 545, 546, 547, 548, 549};
 
    
    int firstDigit = 0;
	  
	// telefon numarasının ilk hanesine sıfır atanması
	this->telefonNumber[0]=firstDigit;
	  
	// rastgele seçilen bir operatörün alan kodunun atanması işlemi
	this->telefonNumber[1]=operatorler[R->randomRakamUret(R,0,31)];
	  
	  
	// telefon numarasının geri kalan 7 hanesinin oluşturulması için for döngüsü
	int i;
	for(i=2; i<9; i++)
	{
		this->telefonNumber[i]=R->randomRakamUret(R,0,10);
	}
	
    this->createImei(this,R);
	
}

// imei oluşturmak için sözde imeino nesnesinin imei oluşturma fonksiyonunun çağrılması
void _createImei(const Telefon this,Rastgele R)
{

	this->IN->createImeiNo(this->IN,R);

}

// bellekten alınan yerin geri teslimi için yıkıcı fonksiyon
void _yokediciTelefon(Telefon this)
{

	if(this==NULL) return;
	// telefonun yapısının içinde oluşturulan sözde imei nesnesi için
	// bellekten ayrılan yerin geri iadesi için imei yıkıcısının çağrılması
	this->IN->yokediciIMEINo(this->IN);
	free(this);
	 
}