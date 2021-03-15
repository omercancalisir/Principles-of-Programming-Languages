/**
*
* @author Melih Ensar BARIŞIK ensar.barisik@ogr.sakarya.edu.tr / Ömer Can ÇALIŞIR omer.calisir@ogr.sakarya.edu.tr
* @since  25.04.2020
* <p>
*   Kişi oluşturulan kısım 
* </p>
*/
#include "Kisi.h"
#include "stdio.h"
#include "stdlib.h"

// nesne yönelimli benzetme için sözde kurucu fonksiyonu
Kisi KisiOlustur(KimlikNo kimlikNo,char* isim_soyisim,int yas,Telefon telefonNo)
{
	Kisi this;
	// struct için bellekte yer ayırma işlemi
	this=(Kisi)malloc(sizeof(struct KISI));
	
	// dışarıdan alınan, kişiyi oluşturan parametrelerin
	// atanması işlemi
	this->kimlikNo=kimlikNo;
	this->isim_soyisim=isim_soyisim;
	this->yas=yas;
	this->telefonNo=telefonNo;



	// fonksiyon göstericisine oluşturulan
    // fonksiyonun adresinin verilmesi işlemi
	this->yokediciKisi=&_yokediciKisi;


	return this;
	
}

// bellekten alınan yerin geri teslimi için yıkıcı fonksiyon
void _yokediciKisi(Kisi this)
{
	if(this==NULL) return;
	free(this);
}
