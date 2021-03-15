/**
*
* @author Melih Ensar BARIŞIK ensar.barisik@ogr.sakarya.edu.tr / Ömer Can ÇALIŞIR omer.calisir@ogr.sakarya.edu.tr
* @since  25.04.2020
* <p>
*   İmei numarası oluşturulan kısım
* </p>
*/
package RandomPacket;

/**
 *
 * @author bar_i
 */
public class IMEINo {
    
    
    private String IMEIS;
    
    public IMEINo()
    {
        
        IMEIS = "";
    }
    
     public String getIMEINo() {
        return IMEIS;
    }
     
     //Imei nuamrasının ilk on dört hanesini rastgele oluşturan fonksiyon
     public void constituteImeıNoPart1()
    {
        //Imei numarasının 14 rakamını random şekilde veriyoruz.
        IMEIS+= Rastgele.produceRandomNumber(14);
        
    }
     //verilen sayının rakamlarını toplama işlemi
     public static int collectNumbers(int data)
    {
        int total =0;
        
        while(data != 0)
        {
            // Gelen datanın basamaklarını toplamak için on ile modunu alıp son karakteri toplama ekliyoruz. 
            total+=(data%10);
            //Sayıyı on ile bölüp bir sonraki rakama geçiyoruz.
            data = data/10;
        }
        
       return total;
      
        
    }
     
     //İmei numarasının son hanesi hesaplanıyor.
    public  void calculateRecentDigit()
    {
        int control =0;
        int sum = 0;
       
        for(int i = 0; i<IMEIS.length(); i++)
        {
            if(i%2 ==0)
            {
                //Tek basamağa denk gelen haneler toplanıyor.
            int value = Character.getNumericValue(IMEIS.charAt(i));
            sum+=value;      
            }

            else
            {   //Çift basamağa denk gelen hanelerin ise iki ile çarpılıp oluşan sayının basamakları toplanıyor.
                int value = Character.getNumericValue(IMEIS.charAt(i));
                sum+=collectNumbers(value*2);
            }
        }
           
        // son hanenin atanması işlemi (son mod alma parantez içinin 10 çıkması olasılığına karşı yapıldı)
        String kontrolHanesi = String.valueOf((10-(sum % 10 ))%10);
        IMEIS+=kontrolHanesi;
       
        
  
    }
    
    //Oluşturma fonksiyonları tek tek çağırılarak işlemi sıralı yapamya yarıyor.
    public void createImei()
    {
        
       constituteImeıNoPart1();
       calculateRecentDigit();
      
    }
    
    //Verilen imei numarasını kontrol ediyor.
    public static boolean controlIMEI(String kontrolEdilecekIMEINo)
    {
        int toplam = 0;
       
        //İlk 14 hanenin rakamlarını toplama işlemini yapıyor.
        for (int i = 0; i < kontrolEdilecekIMEINo.length() - 1; i++) {
            if (i % 2 == 0) {
                //Tek basamağa denk gelen rakamalar toplanıyor.
                toplam+=Character.getNumericValue(kontrolEdilecekIMEINo.charAt(i));
            } else {
                 //Çift basamağa denk gelen rakamlar ise iki le çarpılıp oluşan sayının basamakları toplanıyor.
                 toplam+=collectNumbers(Character.getNumericValue(kontrolEdilecekIMEINo.charAt(i))*2);
            }
            
    }
         // son hanenin atanması işlemi (son mod alma parantez içinin 10 çıkması olasılığına karşı yapıldı)
        String kontrolHanesi = String.valueOf((10 - (toplam % 10)) % 10);
       
        //İmei numarası 15 rakamdan oluşmalı bunu kontrol ediyor.
        if(kontrolEdilecekIMEINo.length() != 15)
        {
            return false;
        }
        //Son hane olan kontrol hanesinni doğru hesaplanıp hesaplanmadğını kontrol ediyor.
        if (kontrolHanesi.equals(String.valueOf(kontrolEdilecekIMEINo.charAt(14)))){
            return true;
        }
        
        return false;
         }
   }
    
    

