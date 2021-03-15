/**
*
* @author Melih Ensar BARIŞIK ensar.barisik@ogr.sakarya.edu.tr / Ömer Can ÇALIŞIR omer.calisir@ogr.sakarya.edu.tr
* @since  25.04.2020
* <p>
*   İmei numarası oluşturulan kısım
* </p>
*/
#ifndef IMEINo_H
#define	IMEINo_H
#include <stdbool.h>
#include <Rastgele.h>
#include <string.h>
#include "IMEINo.h"

// nesne benzetimli kullanmak üzere tanımlanan yapı
struct IMEINO
{
	
	int IMEIS[15];

	int length;


	// fonksiyon göstericileri
	void (*assignRandomDigits)(struct IMEINO*, Rastgele);
	void (*calculateRecentDigit)(struct IMEINO*);
	int* (*getImeiNo)(struct IMEINO*);
	void (*createImeiNo)(struct IMEINO*,Rastgele);
	void (*yokediciIMEINo)(struct IMEINO*);
				
};
// kullanımı kolaylaştırmak üzere oluşturulan yapı
typedef struct IMEINO* IMEINo;

	

    // sözde kurucu fonksiyon
    IMEINo IMEINoUret(); 
    
    
  

    // imeinonun ilk 14 hanesinin random oluşturulması işlemini gerçekleyen fonksiyon
	void _assignRandomDigits(const IMEINo,Rastgele);
	 // imei numarasının son basamağını algoritmaya uygun olarak
     // hesaplama işlemini gerçekleyen fonksiyon
	void _calculateRecentDigit(const IMEINo);
    // verilen sayının basamakları toplamını döndürmeye yarayan fonksiyon
	int collectNumbers(const IMEINo);
	// imeino yu oluşturan fonksiyonların senkronize çalışmasını sağlayan fonksiyon
	void _createImeiNo(const IMEINo,Rastgele);
	// imeino dizisini döndüren get fonksiyonu
    int* _getImeiNo(const IMEINo);
	// imeino nun doğruluğunu kontrol eden fonksiyon
	bool controlIMEI(int* kontrolEdilecekNumara,int uzunluk);
	// bellekten alınan yerin geri teslimi için yıkıcı fonksiyon
	void _yokediciIMEINo(IMEINo);

#endif