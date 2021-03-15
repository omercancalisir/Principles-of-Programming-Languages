/**
*
* @author Melih Ensar BARIŞIK ensar.barisik@ogr.sakarya.edu.tr / Ömer Can ÇALIŞIR omer.calisir@ogr.sakarya.edu.tr
* @since  25.04.2020
* <p>
*   Kişi oluşturulan kısım
* </p>
*/
#ifndef Kisi_H
#define Kisi_H

#include "stdio.h"
#include "stdlib.h"
#include "KimlikNo.h"
#include "Telefon.h"

// nesne benzetimli kullanmak üzere tanımlanan yapı
struct KISI
{
	// kişi oluşturan özellikler
	 KimlikNo kimlikNo;
     char* isim_soyisim;
     int yas;
     Telefon telefonNo;
	 
	// fonksiyon göstericisi
	void (*yokediciKisi)(struct KISI*);
};

// kullanımı kolaylaştırmak üzere oluşturulan yapı
typedef struct KISI* Kisi;

// sözde kurucu fonksiyon
Kisi KisiOlustur(KimlikNo ,char* ,int ,Telefon );

// bellekten alınan yerin geri teslimi için yıkıcı fonksiyon
void _yokediciKisi(Kisi);


#endif