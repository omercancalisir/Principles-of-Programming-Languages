/**
*
* @author Melih Ensar BARIŞIK ensar.barisik@ogr.sakarya.edu.tr / Ömer Can ÇALIŞIR omer.calisir@ogr.sakarya.edu.tr
* @since  25.04.2020
* <p>
*  Rastgele kişi üretilen kısım
* </p>
*/
package RandomPacket;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author bar_i
 */
public class RastgeleKisi {
    
    //Oluşturulan kişileri depolayan ArrayList
  private  List<Kisi> kisiler = new ArrayList<Kisi>();
    
  //Verilen sayıda kişi üreten fonksiyon
     public void kisiUret(int uretilecekKisiSayisi) throws IOException
     {        
         //İsimlerin çekileceği dosyayı okumak için ReadFile sınıfından oluşturulan nesne
              ReadFile  RF = new ReadFile(); 
              RF.ReadFile("random_isimler.txt");
              
              //Üretilecek kişi sayısı kadar dönecek döngü
         for(int i  = 0; i<uretilecekKisiSayisi; i++)
         {
             //KimlikNo sınıfından yeni nesne üretiliyor.
            KimlikNo kimlikNo = new KimlikNo();
            //Üretilen nesnenin gerekli fonksiyonunu çağırıyor.
            kimlikNo.createIdentityNumber();          
            
              
            
              ArrayList<String[]> words = new ArrayList<String[]>();
            //Dosyadan kelime kelime çekilen isim ve soy isimleri depolayan string ArrayList dizisi 
              words=RF.getInformationsWordsbyWords();
              
              //dosyadan okunana değerler arasından random bir isim soyisim seçiliyor seçiliyor
              int randomKisi= Rastgele.produceRandomDigit(words.size());
              //seçilen isim ve soy isim tek bir yerde toplanıyor.
              String nameSurname = words.get(randomKisi)[0]+" "+ words.get(randomKisi)[1];
              
              
             
              
               //Kişi için sıfır ile yüz arasında random bir yaş seçiliyor.
              int age = Rastgele.produceRandomDigit(100); 
             
              //Telefon sınıfından yeni nesne üretiliyor.
              Telefon telefon = new Telefon();
               //Üretilen nesnenin gerekli fonksiyonunu çağırıyor.
              telefon.telefonVeIMEINoUret();
           
              //Elde edilen veriler kişi sınıfının kurucusuna verilerek yeni kişi oluşturuluyor
              Kisi kisi = new Kisi(kimlikNo, nameSurname, age, telefon);

             //Oluşturulan kişiler ArrayList'e ekleniyor.
             kisiler.add(kisi);
          
            
                          
            
         }
        
        
     }
     //Oluşturulan kişileri dosyaya yazan fonksiyon
      public void dosyaYaz() throws IOException {

          //Yazma işlem için WriteFile sınıfından nesne oluşturuluyor.
        WriteFile writeFile = new WriteFile();

        //Yazılacak dosya adı ve elde ettiğimiz kişiler bu fonksiyona veriliyor.
        writeFile.usingPrintWriter("Kisiler.txt", getKisiler());


    }

    /**
     * @return the kisiler
     */
    public List<Kisi> getKisiler() {
        return kisiler;
    }
      
      
    
}
