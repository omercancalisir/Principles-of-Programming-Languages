/**
*
* @author Melih Ensar BARIŞIK ensar.barisik@ogr.sakarya.edu.tr / Ömer Can ÇALIŞIR omer.calisir@ogr.sakarya.edu.tr
* @since  25.04.2020
* <p>
*  Dosyaya yazılan bilgilerden imei numarası ve kimlik numarasını kontrol eder.
* </p>
*/
#include "Control.h"
#include "KimlikNo.h"
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <string.h>
#include "IMEINo.h"
#include <stdbool.h>

// nesne yönelimli benzetme için sözde kurucu fonksiyonu
Control ControlOlustur()
{
	Control this;
	// struct için bellekte yer ayırma işlemi
	this=(Control)malloc(sizeof(struct CONTROL));
	
	// fonksiyon göstericilerine oluşturulan
    // fonksiyonların adreslerinin verilmesi işlemi
	this->chooseInformationToCheck = &_chooseInformationToCheck;
	this->controlIdentity= &_controlIdentity;
	this->controlImeiNumber=&_controlImeiNumber;
	this->yokediciControl=&_yokediciControl;
	
	return this;
}

// bilgilerin kontrolünün yapılabilmesi için dosyadan çekilmesi işlemi
void _chooseInformationToCheck(const Control this)
{
	long long int identityNumbers[10000]; char name[10000][20]; char surname[10000][20]; char age[10000][20]; char telefonNumarasi[10000][20]; char imeiNumarasi[10000][20];
	int i=0;
	               
	
	FILE *dosya;
	dosya = fopen("Kisiler.txt","r");
	
	// dosyanın olup olmadığının kontrolü
	if(dosya != NULL)
	{
		// dosyanın son satırına kadar dönen while döngüsü	 				
		while(!feof(dosya)) 
		{
			// dosyadaki bilgileri çekme işlemi
			fscanf(dosya,"%lld %s %s %s %s %s",&identityNumbers[i],&name[i],&surname[i],&age[i],&telefonNumarasi[i],&imeiNumarasi[i]);
			i++;
				
		}	
		// kimlik ve imei numaralarının kontrole yollanması
		this->controlIdentity(this,identityNumbers,i-1);
		this->controlImeiNumber(this,imeiNumarasi,i-1);
	}
	
	else
	{	
		printf("Dosya Bulunamadi.");
	}
	
	fclose(dosya);
	
}
// dosyadan okunan imei numarasının kontrol edilip ekrana bastırılması işlemi
void _controlImeiNumber(const Control this,char imeiNumarasi[][20],int satirSayisi)
{
	
	printf("%s \n","IMEI Kontrol");
	int s =0;
	// dosyadaki satır sayısı kadar dönen for döngüsü
	for ( s = 0; s < satirSayisi; s++)
	{

		// gelen string yapıdaki imei numarasının char dizisi haline dönüştürülmesi işlemi
		char arrayImei[20];
		strcpy (arrayImei,imeiNumarasi[s]);
	
		
		// imei numarasının başında ve sonunda bulunan parantezlerin ayıklanması işlemi
		char * pch;
  		pch = strtok (arrayImei,"()");

		// oluşturulan char dizisinin işlem yapılabilmesi adına int dizisine dönüştürülmesi işlemi
		int intArray[20];
		int i;
		for (i = 0; i < strlen(imeiNumarasi[s])-2; i++)
		{
			intArray[i] = pch[i] - '0';
			printf("%d",intArray[i]);
		}

		
		// elde edilen int dizinin kontrol amacıyla imeino yapısında bulunan 
		// kontrol fonksiyonuna gönderilmesi ve sonucun ekrana bastırılması işlemi
	
		printf("%c", ' ');
		bool kontrol = controlIMEI(intArray,strlen(imeiNumarasi[s])-2);
		printf(kontrol ? "true" : "false");
		printf("%c \n",' ');

	}
	
}


// dosyadan okunan kimlik numarasının kontrol edilip ekrana bastırılması işlemi
void _controlIdentity(const Control this,long long int *identityNumbers, int sayi)
{
	
	// parametre olarak gelen kimlik numarasının kontrol amacıyla kimlik no yapısında bulunan
	// kontrol fonksiyonuna gönderilmesi ve sonucun ekrana bastırılması işlemi
	int s;
	printf("%s \n","T.C. Kimlik Kontrol");
	for(s=0; s<sayi; s++)
	{
		printf("%lld",identityNumbers[s]);
		printf("%c", ' ');
		bool kontrol = controlIdentityNumber(identityNumbers[s]);
		printf(kontrol ? "true" : "false");
		printf("%c \n",' ');
	}

}

// bellekten alınan yerin geri teslimi için yıkıcı fonksiyon
void _yokediciControl(Control this)
{
	if(this==NULL);
	free(this);
}