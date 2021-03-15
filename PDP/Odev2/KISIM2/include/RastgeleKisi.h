/**
*
* @author Melih Ensar BARIŞIK ensar.barisik@ogr.sakarya.edu.tr / Ömer Can ÇALIŞIR omer.calisir@ogr.sakarya.edu.tr
* @since  25.04.2020
* <p>
*   Rastgele kişi oluşturulan kısım
* </p>
*/
#ifndef RASTGELEKISI_H
#define	RASTGELEKISI_H

#include "Rastgele.h"
#include "KISI.h"
// nesne benzetimli kullanmak üzere tanımlanan yapı
struct RASTGELEKISI
{
	//Oluşturulan kişileri tutan Kisi işaretçisi
	Kisi* kisi;
    int uretilecekKisiSayisi;
	
	// fonksiyon göstericileri
	void (*kisiUret)(struct RASTGELEKISI*,Rastgele);
	void (*yokediciRastgeleKisi)(struct RASTGELEKISI*);
	
	
	
};
// kullanımı kolaylaştırmak üzere oluşturulan yapı
typedef struct RASTGELEKISI* RastgeleKisi;

// sözde kurucu fonksiyon
RastgeleKisi RastgeleKisiOlustur(int);

//İstenilen sayıda kişi üreten fonksiyon
void _kisiUret(const RastgeleKisi,Rastgele);

// bellekten alınan yerin geri teslimi için yıkıcı fonksiyon
void _yokediciRastgeleKisi(RastgeleKisi);
// bellekten alınan yerin geri teslimi için yıkıcı fonksiyon
void yokediciKisileriSil(RastgeleKisi);

#endif