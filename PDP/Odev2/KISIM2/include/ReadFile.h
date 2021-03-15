/**
*
* @author Melih Ensar BARIŞIK ensar.barisik@ogr.sakarya.edu.tr / Ömer Can ÇALIŞIR omer.calisir@ogr.sakarya.edu.tr
* @since  25.04.2020
* <p>
*   Dosya okunan kısım
* </p>
*/
#ifndef Readfile_H
#define	Readfile_H
#include "Rastgele.h"

// nesne benzetimli kullanmak üzere tanımlanan yapı
struct READFILE
{
	
	
	char selectedNameSurname [100000][35];
	
	// fonksiyon göstericileri
	void  (*DosyaOku)(struct READFILE*);
	char* (*getSelectedNameSurname)(struct READFILE*,Rastgele);
	void (*yokediciReadFile)(struct READFILE*);
};
// kullanımı kolaylaştırmak üzere oluşturulan yapı
typedef struct READFILE* ReadFile;


// sözde kurucu fonksiyon
ReadFile ReadFileOlustur();

//Dosya okuyan fonksiyon
void _DosyaOku(const ReadFile);

//Seçilen isim ve soyisimi geri döndüren fonksiyon
char* _getSelectedNameSurname(const ReadFile,Rastgele);

// bellekten alınan yerin geri teslimi için yıkıcı fonksiyon
void _yokediciReadFile(ReadFile);


#endif