/**
*
* @author Melih Ensar BARIŞIK ensar.barisik@ogr.sakarya.edu.tr / Ömer Can ÇALIŞIR omer.calisir@ogr.sakarya.edu.tr
* @since  25.04.2020
* <p>
*   Dosyadan okunan bilgilerin kimlik ve imei numaralarının kontrol edildiği kısım
* </p>
*/
#ifndef CONTROL_H
#define	CONTROL_H

// nesne benzetimli kullanmak üzere tanımlanan yapı
struct CONTROL
{

	// fonksiyon göstericileri
	void (*chooseInformationToCheck)(struct CONTROL*);
	void (*controlIdentity)(struct CONTROL*,long long int*,int);
	void (*controlImeiNumber)(struct CONTROL*,char[][20],int);
	void (*yokediciControl)(struct CONTROL*);
};

// kullanımı kolaylaştırmak üzere oluşturulan yapı
typedef struct CONTROL* Control;

// sözde kurucu fonksiyon
Control ControlOlustur();

// bilgilerin kontrolünün yapılabilmesi için dosyadan çekilmesi işlemi
void _chooseInformationToCheck(const Control);

// dosyadan okunan kimlik numarasının kontrol edilip ekrana bastırılması işlemi
void _controlIdentity(const Control,long long int*,int);

// dosyadan okunan imei numarasının kontrol edilip ekrana bastırılması işlemi
void _controlImeiNumber(const Control,char[][20],int);

// bellekten alınan yerin geri teslimi için yıkıcı fonksiyon
void _yokediciControl(Control);
	

#endif