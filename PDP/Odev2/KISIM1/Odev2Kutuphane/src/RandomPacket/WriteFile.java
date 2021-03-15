/**
*
* @author Melih Ensar BARIŞIK ensar.barisik@ogr.sakarya.edu.tr / Ömer Can ÇALIŞIR omer.calisir@ogr.sakarya.edu.tr
* @since  25.04.2020
* <p>
*  Dosya yazmaya yarayan kısım
* </p>
*/
package RandomPacket;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;

/**
 *
 * @author bar_i
 */
public class WriteFile {
    
    //Yazma işlemini yapan fonksiyon dışarıdan dosya adını ve kişler ArrayListini alıyor.
    public static void usingPrintWriter(String filename, List<Kisi> kisiler) throws IOException 
{
    
    FileWriter fileWriter = new FileWriter(filename);
    PrintWriter printWriter = new PrintWriter(fileWriter);
    //Elde edilen kişilerin sayısı kadar dönen bir döngü
    for (int i = 0; i < kisiler.size(); i++) {
            
            //Depolanan kişiler içinden sırası ile kişiler alınıyor.
            Kisi kisi = kisiler.get(i);
            //Bilgilerin hepsi tek bir stringde toplanıyor.
            String bilgiler = "" + kisi.getKimlikNo().getKimlikNo() + " " + kisi.getIsim_soyisim() + " " + kisi.getYas() + " " + kisi.getTelefonNo().getTelefonNo() + " " + "(" + kisi.getTelefonNo().getIMEINo().getIMEINo() + ")";

            //Toplanan bilgiler istenen dosyaya yazılıyor.
            printWriter.println(bilgiler);
           
           
        }
    //Dosya kapanıyor.
     printWriter.close();
   
    }
}
