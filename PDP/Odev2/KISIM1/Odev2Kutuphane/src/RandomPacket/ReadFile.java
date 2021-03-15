/**
*
* @author Melih Ensar BARIŞIK ensar.barisik@ogr.sakarya.edu.tr / Ömer Can ÇALIŞIR omer.calisir@ogr.sakarya.edu.tr
* @since  25.04.2020
* <p>
*  Dosya okuma işlemini yapan kısım
* </p>
*/
package RandomPacket;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author bar_i
 */
public class ReadFile {
     
    
    
 
       
       private ArrayList<String> informationsLinebyLine = new ArrayList<String>();
       private ArrayList <String[]> informationsWordsbyWords = new ArrayList<String[]>();
       
       
       public ArrayList<String> getInformationsLinebyLine() {
        return informationsLinebyLine;
    }
       public ArrayList<String[]> getInformationsWordsbyWords() {
        return informationsWordsbyWords;
    }
       
        public void ReadFile(String fileName) {
        try {
           
            FileInputStream fStream = new FileInputStream(fileName);
            DataInputStream dStream = new DataInputStream(fStream);
            BufferedReader bReader = new BufferedReader(new InputStreamReader(dStream));
            
            String data = "";
            String line = "";
            String KelimeDizisi[] = null;

               //Dosya sonuna kadar dönen ve satır satır veri çeken döngü
            while (((line = bReader.readLine()) != null)) {
                //Her bir satırın sonuna daha sonra satırları bölebilmek için \n yazılıyor. 
                data = data + line + "\n";
            }
            data = data + ' ';
            //Çekilen bilgiyi satır satır bölüyor
            KelimeDizisi = data.split("\n");
            
            //Bilgileri satır satır depolayan ArrayListin oluşturulması
            for (int i = 0; i < KelimeDizisi.length; i++) {
                informationsLinebyLine.add(KelimeDizisi[i]);
            }
            
            
          
            //Bilgileri kelime kelime depolayan ArrayList dizisinin oluşturulması
            for (int k = 0; k < informationsLinebyLine.size()-1; k++) {        
                informationsWordsbyWords.add(informationsLinebyLine.get(k).split(" "));
            } 
            
            dStream.close();
            


        } catch (Exception e) {
            System.err.println("Hata Dosya Bulunmadı : " + e.getMessage());
        }

    }

    /**
     * @return the informationsLinebyLine
     */
    
       
    
    
}
