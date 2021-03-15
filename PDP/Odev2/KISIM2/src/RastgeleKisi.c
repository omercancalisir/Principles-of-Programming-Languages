/**
*
* @author Melih Ensar BARIŞIK ensar.barisik@ogr.sakarya.edu.tr / Ömer Can ÇALIŞIR omer.calisir@ogr.sakarya.edu.tr
* @since  25.04.2020
* <p>
*  Rastgele kişi üretilen kısım
* </p>
*/

#include "RastgeleKisi.h"
#include "KimlikNo.h"
#include "Rastgele.h"
#include "Telefon.h"
#include "ReadFile.h"
#include "WriteFile.h"
#include "Kisi.h"
#include<stdio.h>
#include<stdlib.h>

// nesne yönelimli benzetme için sözde kurucu fonksiyonu
RastgeleKisi RastgeleKisiOlustur(int sayi)
{
	RastgeleKisi this;
	// struct için bellekte yer ayırma işlemi
	this = (RastgeleKisi)malloc(sizeof(struct RASTGELEKISI));
	//Kullanıcının üretmek istediği kişi sayısı için bellekten yer açma işlemi
	this->kisi=(Kisi*)malloc(sizeof(struct KISI)*sayi);
	this->uretilecekKisiSayisi = sayi;
	
	// fonksiyon göstericilerine oluşturulan
    // fonksiyonların adreslerinin verilmesi işlemi
	this->kisiUret=&_kisiUret;
	this->yokediciRastgeleKisi=&_yokediciRastgeleKisi;
	
	return this;
}


//İstenilen sayıda kişi üreten fonksiyon
void _kisiUret(const RastgeleKisi this,Rastgele Rast)
{
	
	//İsimlerin çekileceği dosyayı okumak için ReadFile sınıfından oluşturulan nesne
	ReadFile RF = ReadFileOlustur();
	RF->DosyaOku(RF);
	WriteFile WF = olusturWriteFile();
	FILE *dosya;
	dosya = fopen("Kisiler.txt","w");
		 
    //Üretilecek kişi sayısı kadar dönecek döngü
	int i;
	for(i  = 0; i<this->uretilecekKisiSayisi; i++)
    {
	    //KimlikNo yapısından yeni sözde nesne üretiliyor.
    	KimlikNo kimlikNo = KimlikNoUret();      
		 //Üretilen sözde nesnenin gerekli fonksiyonu çağırıyor.
		kimlikNo->createIdentityNumber(kimlikNo,Rast);
              		  
		//Kişi için sıfır ile yüz arasında random bir yaş seçiliyor.	  
		int age;
    	age = Rast->randomRakamUret(Rast,0,100); //CHECK
						  
		//Telefon yapısından yeni sözde nesne üretiliyor.
		Telefon telefon = telefonOlustur(); 
		//Üretilen sözde nesnenin gerekli fonksiyonunu çağırıyor.
		telefon->telefonVeIMEINoUret(telefon,Rast);
			  
			 		 
		char* secilenKisi; 
		//Okunan dosyadan rastgele seçilen kişi alınıyor.
		secilenKisi = RF->getSelectedNameSurname(RF,Rast);
			 		  	
		//Elde edilen veriler kişi sınıfının kurucusuna verilerek yeni kişi oluşturuluyor	  
		Kisi kisi = KisiOlustur(kimlikNo,secilenKisi,age,telefon);
		
		//Oluşturulan kişiler ekleniyor.		
		this->kisi[i]=kisi;

            
    }
		 
	//Kişileri dosyaya yazmak için kişi sayısı kadar dönen döngü	 
	int j;
	for(j=0; j<this->uretilecekKisiSayisi; j++)
	{
		//Kişileri sırası ile dosyaya yazma işlemi
		WF->writeKisiFile(WF,this->kisi[j],dosya);
	}
		  
	yokediciKisileriSil(this);		 
	RF->yokediciReadFile(RF);
	fclose(dosya);
	WF->yokediciWriteFile(WF);
		
}

void _yokediciRastgeleKisi(RastgeleKisi this)
{
	if(this==NULL) return;
	
	free(this);
}
void yokediciKisileriSil(RastgeleKisi this)
{
	//Sırası ile oluşturulan sözde nesnelerin bulunduğu adresleri temizliyor.
	  int m;
		 for(m=0; m<this->uretilecekKisiSayisi; m++)
		 {
		      this->kisi[m]->kimlikNo->yokediciKimlikNo(this->kisi[m]->kimlikNo);
			  this->kisi[m]->telefonNo->yokediciTelefon(this->kisi[m]->telefonNo);
			  this->kisi[m]->yokediciKisi( this->kisi[m]);
		 }
		 
}



