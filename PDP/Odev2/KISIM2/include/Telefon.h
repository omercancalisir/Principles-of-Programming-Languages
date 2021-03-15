/**
*
* @author Melih Ensar BARIŞIK ensar.barisik@ogr.sakarya.edu.tr / Ömer Can ÇALIŞIR omer.calisir@ogr.sakarya.edu.tr
* @since  25.04.2020
* <p>
*   Telefon numarası oluşturulan kısım
* </p>
*/
#ifndef TELEFON_H
#define	TELEFON_H
#include "IMEINo.h"

// nesne benzetimli kullanmak üzere tanımlanan yapı
struct TELEFON 
{
	
	int telefonNumber[9];
	// sözde imeinin nesne referansı
	IMEINo IN; 

	// fonksiyon göstericileri
	void(*telefonVeIMEINoUret)(struct TELEFON*, Rastgele);
	void(*createImei)(struct TELEFON*,Rastgele);
	void(*yokediciTelefon)(struct TELEFON*);
			
};

// kullanımı kolaylaştırmak üzere oluşturulan yapı
typedef struct TELEFON* Telefon;

// sözde kurucu fonksiyon
Telefon telefonOlustur();

// telefon ve imeino üreten fonksiyon
void _telefonVeIMEINoUret(const Telefon, Rastgele);

// imei oluşturmak için sözde imeino nesnesinin imei oluşturma fonksiyonunun çağrılması
void _createImei(const Telefon,Rastgele);

// bellekten alınan yerin geri teslimi için yıkıcı fonksiyon
void _yokediciTelefon(Telefon);

#endif