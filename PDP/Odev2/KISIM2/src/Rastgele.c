/**
*
* @author Melih Ensar BARIŞIK ensar.barisik@ogr.sakarya.edu.tr / Ömer Can ÇALIŞIR omer.calisir@ogr.sakarya.edu.tr
* @since  25.04.2020
* <p>
*  Rastgele sayı üretme kısmı 
* </p>
*/
#include "Rastgele.h"
#include<stdio.h>
#include<stdlib.h>
#include <time.h>


// nesne yönelimli benzetme için sözde kurucu fonksiyonu
Rastgele RastgeleOlustur()
{
	Rastgele this;
	// struct için bellekte yer ayırma işlemi
	this=(Rastgele)malloc(sizeof(struct RASTGELE));
	
	// saniye çekme işlemi
	this->next=time(NULL);
	
	// fonksiyon göstericilerine oluşturulan
    // fonksiyonların adreslerinin verilmesi işlemi
	this->randomRakamUret=&_randomRakamUret;
	this->yokediciRastgele=&_yokediciRastgele;
	
	return this;
}


// istenilen aralıkta random bir sayi üreten fonksiyon
long int _randomRakamUret(const Rastgele this,long int ilk,long int son){

	this->next = this->next * 1103515245 + 12345;
	long int fark = son-ilk;
	// üretilen sayının istenilen aralığın dışında olmaması için
	// fark ile modunun alınması ve alt sınırla toplanması işlemi
	long int mod = (unsigned int)(this->next/65536)%fark;
	long int randomSayi = ilk + mod;
	return randomSayi;
}

// bellekten alınan yerin geri teslimi için yıkıcı fonksiyon
void _yokediciRastgele(Rastgele this)
{
	if(this==NULL) return;
	free(this);
}