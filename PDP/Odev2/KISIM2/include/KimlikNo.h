/**
*
* @author Melih Ensar BARIŞIK ensar.barisik@ogr.sakarya.edu.tr / Ömer Can ÇALIŞIR omer.calisir@ogr.sakarya.edu.tr
* @since  25.04.2020
* <p>
*   Kimlik numarası oluşturulan kısım
* </p>
*/
#ifndef KimlikNo_H
#define	KimlikNo_H
#include <stdbool.h>
#include "Rastgele.h"


// nesne benzetimli kullanmak üzere tanımlanan yapı
struct KIMLIKNO
{

	int* identityNumbers;
	
	
	// fonksiyon göstericileri
	void (*firstStepControlAndConstitute)(struct KIMLIKNO*,Rastgele);
	void (*constituteIdentityNumber)(struct KIMLIKNO*,Rastgele);
	void (*calculateTenthStep)(struct KIMLIKNO*);
	void (*calculateEleventhNumber)(struct KIMLIKNO*);
	void (*createIdentityNumber)(struct KIMLIKNO*,Rastgele);
	void (*yokediciKimlikNo)(struct KIMLIKNO*);
	
};

// kullanımı kolaylaştırmak üzere oluşturulan yapı
typedef struct KIMLIKNO* KimlikNo;

// sözde kurucu fonksiyon
KimlikNo KimlikNoUret(); 


// ilk hanenin 0 olmaması durumu için atama ve kontrol işlemini yapan fonksiyon
void _firstStepControlAndConstitute(const KimlikNo,Rastgele);

// kimlik numarasındaki diğer 8 hanenin atanması işlemi
void _constituteIdentityNumber(const KimlikNo,Rastgele);

// 10. basamağın kimlik no algoritması prensipleri uyarınca
// bulunması işlemi
void _calculateTenthStep(const KimlikNo);

// 11. basamağın kimlik no algoritması prensipleri uyarınca
// bulunması işlemi
void _calculateEleventhNumber(const KimlikNo);

// verilen kimlik numarasının kontrolünü yapan fonksiyon
bool  controlIdentityNumber(long long int);

// kimlik oluşturma fonksiyonlarının senkronize çalışmasını sağlayan fonkisyon
void _createIdentityNumber(const KimlikNo,Rastgele);

// bellekten alınan yerin geri teslimi için yıkıcı fonksiyon
void _yokediciKimlikNo(KimlikNo);









#endif