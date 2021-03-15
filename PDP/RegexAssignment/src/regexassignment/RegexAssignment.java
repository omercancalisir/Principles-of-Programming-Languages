/**
*
* @author Ömer Can ÇALIŞIR - omercancalisir@hotmail.com / Melih Ensar BARIŞIK - barisik.melih@gmail.com
* @since 08.03.2020
* <p>
*   Uygulamanın gerçeklemesini sağlayan main metodunun bulunduğu sınıf yapısı
* </p>
*/
package regexassignment;


public class RegexAssignment {

    
    public static void main(String[] args) {
       ReadFile RF = new ReadFile();
       RF.ReadFile();
     
     
       
      Counter C = new Counter(RF.getDiziUzunlugu()); 
      C.setKelimeler(RF.getKelimeDizisi());
      C.sesliHarfSayisiHesapla();
      C.CumleSayisiHesapla();
      C.KelimeSayisiHesapla();
      C.mailSayisi();
      C.webSiteSayisi();
      C.sonuclariYaz();
    }
    
}
