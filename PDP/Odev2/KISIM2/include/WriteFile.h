/**
*
* @author Melih Ensar BARIŞIK ensar.barisik@ogr.sakarya.edu.tr / Ömer Can ÇALIŞIR omer.calisir@ogr.sakarya.edu.tr
* @since  25.04.2020
* <p>
*  Dosya okuma kısmı
* </p>
*/
#ifndef WriteFile_H
#define	WriteFile_H


#include "Kisi.h"

struct WRITEFILE
{
	
	// fonksiyon göstericileri
	void (*writeKisiFile)(struct WRITEFILE*,Kisi,FILE*);
	void (*yokediciWriteFile)(struct WRITEFILE*);
	
};
// kullanımı kolaylaştırmak üzere oluşturulan yapı
typedef struct WRITEFILE* WriteFile;


// sözde kurucu fonksiyon
WriteFile olusturWriteFile();

//Dosyaya yazma işlemi
void _writeKisiFile(const WriteFile,Kisi,FILE*);
// bellekten alınan yerin geri teslimi için yıkıcı fonksiyon
void _yokediciWriteFile(WriteFile);



#endif