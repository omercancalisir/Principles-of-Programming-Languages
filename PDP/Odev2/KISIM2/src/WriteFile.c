/**
*
* @author Melih Ensar BARIŞIK ensar.barisik@ogr.sakarya.edu.tr / Ömer Can ÇALIŞIR omer.calisir@ogr.sakarya.edu.tr
* @since  25.04.2020
* <p>
*  Dosya yazmaya yarayan kısım
* </p>
*/
#include "WriteFile.h"
#include "Kisi.h"
#include<stdio.h>
#include<stdlib.h>

// nesne yönelimli benzetme için sözde kurucu fonksiyonu
WriteFile olusturWriteFile()
{
	WriteFile this;
	// struct için bellekte yer ayırma işlemi
	this =(WriteFile)malloc(sizeof(struct WRITEFILE));
	
	// fonksiyon göstericilerine oluşturulan
    // fonksiyonların adreslerinin verilmesi işlemi
	this->writeKisiFile = &_writeKisiFile;
	this->yokediciWriteFile = &_yokediciWriteFile;
	return this;
}

//Dosyaya yazma işlemi
void _writeKisiFile(const WriteFile this, Kisi kisi,FILE *dosya)
{
	
	//Dosyanın olup olmadığını kontrol eden yapı
	if(dosya != NULL)
	{
	
		int i;
		//Kimlik numarası boyutu kadar dönen döngü 
		for(i=0; i<11; i++)
		{
			//Parametre olarak alınan kişi sözde nesnesinin kimlik bilgisini dosyaya yazma işlemi
			fprintf(dosya,"%d",kisi->kimlikNo->identityNumbers[i]);   
		} 
	
		fprintf(dosya,"%c",' ');

	
	
		int p;
		int uzunluk=0;
		//İsim ve soyismin uzunluğunu hesaplayan döngü
		for(p=0; kisi->isim_soyisim[p]!='\0'; p++)  
    	{
        	uzunluk++;
   	 	}
	
	
	
		char tempNameSurname[uzunluk];	
		int m;
		//İsmi soyismi diziye atayan döngü
		for(m=0; m<uzunluk; m++)  
    	{
        	tempNameSurname[m]=kisi->isim_soyisim[m];    
    	}
	
		
		int s;
		//İsim soyisim uzunluğunun boyutu kadar dönen döngü 
		for(s=0; s<uzunluk-1; s++)
		{
			//Parametre olarak alınan kişi sözde nesnesinin isim ve soyisim bilgisini dosyaya yazma işlemi
			fprintf(dosya,"%c", tempNameSurname[s]);    
		} 
	
		fprintf(dosya,"%c",' ');
	
	    //Parametre olarak alınan kişi sözde nesnesinin yaş bilgisini dosyaya yazma işlemi
		fprintf(dosya,"%d",kisi->yas); 
	
		
		fprintf(dosya,"%c",' ');
		
		
		int j;
		//Telefon numarası boyutu kadar dönen döngü 
		for(j=0; j<9; j++)
		{
			//Parametre olarak alınan kişi sözde nesnesinin telefon bilgisini dosyaya yazma işlemi
			fprintf(dosya,"%d",kisi->telefonNo->telefonNumber[j]); 
		}
	  
	
		fprintf(dosya,"%c",' ');
		
	
		int l;
		fprintf(dosya,"%c",'(');
		//Imei numarası boyutu kadar dönen döngü 
		for(l=0; l<15; l++)
		{	
			//Parametre olarak alınan kişi sözde nesnesinin imei bilgisini dosyaya yazma işlemi				  
			fprintf(dosya,"%d",kisi->telefonNo->IN->IMEIS[l]); 		
		} 


		fprintf(dosya,"%c",')');
		
		fprintf(dosya,"%c",'\n');
	
		
	}


	else
	{
		printf("Dosya Bulunamadi.");
	}
	
	
}

// bellekten alınan yerin geri teslimi için yıkıcı fonksiyon
void _yokediciWriteFile(WriteFile this)
{
	if(this==NULL) return;
	free(this);
}