/**
*
* @author Melih Ensar BARIŞIK ensar.barisik@ogr.sakarya.edu.tr / Ömer Can ÇALIŞIR omer.calisir@ogr.sakarya.edu.tr
* @since  25.04.2020
* <p>
*   Rastgele sayı oluşturulan kısım
* </p>
*/
#ifndef Rastgele_H
#define	Rastgele_H


// nesne benzetimli kullanmak üzere tanımlanan yapı
struct RASTGELE
{
	// time değerinin atanacağı pozitif değişken
	unsigned int next;
	
	// fonksiyon göstericileri
	long int (*randomRakamUret)(struct RASTGELE*,long int,long int);
	void (*yokediciRastgele)(struct RASTGELE*);
	
	
};

// kullanımı kolaylaştırmak üzere oluşturulan yapı
typedef struct RASTGELE* Rastgele;

// sözde kurucu fonksiyon
Rastgele RastgeleOlustur();


// istenilen aralıkta random sayı üreten fonksiyon
long int _randomRakamUret(const Rastgele,long int,long int);

// bellekten alınan yerin geri teslimi için yıkıcı fonksiyon
void _yokediciRastgele(Rastgele);



#endif