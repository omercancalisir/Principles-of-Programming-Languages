/**
*
* @author Ömer Can ÇALIŞIR - omercancalisir@hotmail.com / Melih Ensar BARIŞIK - barisik.melih@gmail.com
* @since 08.03.2020
* <p>
*   icerik.txt dosyasından verileri çekmeye yarayan metodun bulunduğu sınıf yapısı
* </p>
*/
package regexassignment;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.InputStreamReader;


public class ReadFile {
    
    
      private String data;
      private String line;
      private String KelimeDizisi[];
      private int diziUzunlugu;
      
      
      ReadFile() 
      { 
          data = " "; 
          line =" ";
          KelimeDizisi=null;
          diziUzunlugu=0;
         }
      
      public int getDiziUzunlugu()
      {
          return diziUzunlugu;
      }
      
      public String[] getKelimeDizisi()
      {   
         return KelimeDizisi;
      }
      
      public void ReadFile() // Dosyadan data cümle cümle alınıyor.
      {
        try
        {
            FileInputStream fStream = new FileInputStream("icerik.txt");
            DataInputStream dStream = new DataInputStream(fStream);
            BufferedReader bReader = new BufferedReader(new InputStreamReader(dStream));
            
            
            while(((line = bReader.readLine()) != null))
            {
              data = data+' '+ line; 
             
            }
            data = data+' ';
            KelimeDizisi = data.split(" ");
        
            dStream.close();
            diziUzunlugu=KelimeDizisi.length;
          
          
           
            
        }catch(Exception e)
        {
            System.err.println("Hata : " + e.getMessage());
        }       
          
      }
      
}
