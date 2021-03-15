/**
*
* @author Melih Ensar BARIŞIK ensar.barisik@ogr.sakarya.edu.tr / Ömer Can ÇALIŞIR oomer.calisir@ogr.sakarya.edu.tr
* @since  25.04.2020
* <p>
*  Ödevin çalıştırıldığı ana kısım
* </p>
*/
package test;

import RandomPacket.Control;
import RandomPacket.RastgeleKisi;
import java.io.IOException;
import java.util.Scanner;

/**
 *
 * @author bar_i
 */
public class Test {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
           Scanner scanner = new Scanner(System.in);
        String cevap = "";
      
        do {
            System.out.println("1. Rastgele Kişi Üret " + "2. Üretilmiş Dosyayı Kontrol Et " + "3. Çıkış");

            cevap = scanner.nextLine();
                    
            
            if (cevap.equals("1")) {
                 
                RastgeleKisi rastgeleKisi = new RastgeleKisi();
                System.out.println("Üretilecek Kişi Sayısı :");
                int sayi = scanner.nextInt();
                scanner.nextLine();
                
                
                    
                rastgeleKisi.kisiUret(sayi);
                rastgeleKisi.dosyaYaz();
                    
                
              

            } else if (cevap.equals("2")) {

                Control C = new Control();
                C.chooseInformationToCheck();
                C.controlIdentityNumber();
                C.controlImeıNumber();
                
            }


        } while (!cevap.equals("3"));
        
        
    }
    
}
