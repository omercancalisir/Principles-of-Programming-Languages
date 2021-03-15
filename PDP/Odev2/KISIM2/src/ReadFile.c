/**
*
* @author Melih Ensar BARIŞIK ensar.barisik@ogr.sakarya.edu.tr / Ömer Can ÇALIŞIR omer.calisir@ogr.sakarya.edu.tr
* @since  25.04.2020
* <p>
*  Dosya okuma işlemini yapan kısım
* </p>
*/
#include <stdlib.h>
#include <stdio.h>

#include "ReadFile.h"
#include "Rastgele.h"

// nesne yönelimli benzetme için sözde kurucu fonksiyonu
ReadFile ReadFileOlustur()
{
	ReadFile this;
	// struct için bellekte yer ayırma işlemi
	this =(ReadFile)malloc(sizeof(struct READFILE));
	
	// fonksiyon göstericilerine oluşturulan
    // fonksiyonların adreslerinin verilmesi işlemi
	this->DosyaOku=&_DosyaOku;
	this->getSelectedNameSurname=&_getSelectedNameSurname;
	this->yokediciReadFile=&_yokediciReadFile;
	return this;
}

//Dosya okuyan fonksiyon
void _DosyaOku(const ReadFile this)
{
	FILE *dosya;
	
	
	dosya = fopen("random_isimler.txt","r");
	
	
	int i=0;
	
	if(dosya != NULL)
	{	
			//Dosyanın sonuna kadar dönen dögü
			while(!feof(dosya))
			{
				//Dosyadan satır satır okuma işlemi
		    fgets(this->selectedNameSurname[i],35,dosya);
		    i++;
			}
			
			
			
	}
	
	else
	{
		printf("Dosya Bulunamadi.");
	}
		fclose(dosya);
}

//Seçilen ismi ve soyismi döndüren fonksiyon
char* _getSelectedNameSurname(const ReadFile this,Rastgele Rast)
{
	return this->selectedNameSurname[Rast->randomRakamUret(Rast,0,2999)];
}

// bellekten alınan yerin geri teslimi için yıkıcı fonksiyon
void _yokediciReadFile(ReadFile this)
{
	if(this==NULL);
	free(this);
}