/**
*
* @author Melih Ensar BARIŞIK ensar.barisik@ogr.sakarya.edu.tr / Ömer Can ÇALIŞIR omer.calisir@ogr.sakarya.edu.tr
* @since  25.04.2020
* <p>
*  Rastgele sayı üretme kısmı 
* </p>
*/
package RandomPacket;

/**
 *
 * @author bar_i
 */
public class Rastgele {
    
    //Sıfırdan, aldığı limit parametresinin değerine kadar bir rastgele sayı üretir.
     public static int produceRandomDigit(int limit)
    {
        
     long preserver;
     //Rastgele sayı elde etmek için sistemden nano time ı alıp yüze bölüyoruz.
     preserver = System.nanoTime()/100;
     
     return (int)(preserver%(limit));
    }    
    
     //İstenen basamakta sayı üreten fonksiyon
    public static String produceRandomNumber(int decimalPlaces) 
    {
       String number ="";
       
       for(int i =0; i<decimalPlaces; i++)
       {
           //Her bir basamak için produceRandomDigit kullanarak rakam alır ve bu rakamaları birleştirir.
           number = number + produceRandomDigit(9);
       }
     
        return number;
    }
    
    
}
