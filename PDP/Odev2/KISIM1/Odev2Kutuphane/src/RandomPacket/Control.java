/**
*
* @author Melih Ensar BARIŞIK ensar.barisik@ogr.sakarya.edu.tr / Ömer Can ÇALIŞIR omer.calisir@ogr.sakarya.edu.tr
* @since  25.04.2020
* <p>
*  Dosyaya yazılan bilgilerden imei numarası ve kimlik numarasını kontrol eder.
* </p>
*/
package RandomPacket;

import java.io.File;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author bar_i
 */
public class Control {
    
    
    
     private ArrayList<String> identityNumbers =  new ArrayList<String>();
     private ArrayList<String> imeiNumbers = new ArrayList<String>();
    
     
     
     public void chooseInformationToCheck()
     {          
         //Dosya işlemlerinde oluşabilecek hataları yakalamak için kullanılıyor.
         try{        
             //Kişiler dosyası okuma işlemi yapılıyor.
            ReadFile readFile = new ReadFile();
            readFile.ReadFile("Kisiler.txt");          
           
            ArrayList <String[]> words = new ArrayList<String[]>();         
            words = readFile.getInformationsWordsbyWords();
                   
          
            
           //Okunan bilgiler içinden kimlik numaraları ArrayList dizisinde depolanıyor.
            for (int i = 0; i < words.size(); i++) {               
                identityNumbers.add(words.get(i)[0]);               
            }
            
            //Okunan bilgiler içinden imei numaraları ArrayList dizisinde depolanıyor.
             for (int i = 0; i < words.size(); i++) {
                int boyut = words.get(i)[5].length();
                //Imei değerinin başında ve sonunda bulunan parantez işaretleri ayıklanıyor.
                 String gecici = words.get(i)[5].substring(1,boyut-1);  
               
               
                imeiNumbers.add(gecici);
             }
                      
         }
                
         catch (Exception e) {
            System.err.println("Hata : " + e.getMessage());
        }
          
         
            
       
            
          
            
       }
     
     //Kimlik numaralarını kontrol eden fonksiyon
     public void controlIdentityNumber()     
     {
         System.out.println("T.C. Kimlik Kontrol ");
        
         //Elde edilen kimlik numaraları sırası ile döndürülüyor.
        for(int i =0; i<identityNumbers.size(); i++)
        {
          // Elde edilen kimlik numaraları sırası ile ekrana yazdırılıyor..
           System.out.print(identityNumbers.get(i)+"  ");
       
           //Elde edilen kimlik numaraları sırası ile kontrol ediliyor.
           System.out.println(KimlikNo.controlIdentityNumber(identityNumbers.get(i)));
           
           
        }
     }
     
     //İmei numaralarını kontrol eden fonksiyon
      public void controlImeıNumber()     
     {
         
         System.out.println("IMEI  Kontrol");
        
         //Elde edilen İmei numaraları sırası ile döndürülüyor.
        for(int i =0; i<imeiNumbers.size(); i++)
        {
            // Elde edilen İmei numaraları sırası ile ekrana yazdırılıyor..
           System.out.print(imeiNumbers.get(i)+"  ");
           //Elde edilen İmei numaraları sırası ile kontrol ediliyor.
           System.out.println(IMEINo.controlIMEI(imeiNumbers.get(i)));
           
           
        }
     }
     
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
    
}
