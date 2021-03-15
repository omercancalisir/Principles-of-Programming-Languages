/**
*
* @author Melih Ensar BARIŞIK ensar.barisik@ogr.sakarya.edu.tr / Ömer Can ÇALIŞIR omer.calisir@ogr.sakarya.edu.tr
* @since  25.04.2020
* <p>
*   Kimlik numarası oluşturulan kısım
* </p>
*/
package RandomPacket;

/**
 *
 * @author bar_i
 */
public class KimlikNo {
     
    private String identityNumberS; 
    final int limit;
    
    public KimlikNo()
    {
        identityNumberS="";
        limit=10;
    }
     
    //Kimlik numarasının ilk hanesini hesaplar
    public void firstStepControlAndConstitute()
    {     
        int protector=0;
        
            protector = Rastgele.produceRandomDigit(limit);
            //İlk hane sıfır olamaz bunu kontrol ediyor.
            while(protector ==0)
            { 
                protector = Rastgele.produceRandomDigit(limit);
            }
            
            identityNumberS+=String.valueOf(protector);
           
           
    }
    //Kimlik numarasının sonraki sekiz hanesine rastgele sayılar atıyor.
    public void constituteIdentityNumber()
    {
   
            identityNumberS+= Rastgele.produceRandomNumber(8); 
              
    }
    //Atanan ilk dokuz haneyi kullanarak onuncu haneyi hesaplıyor.
    public void calculateTenthStep()
    {
        int sumOddNumbers = 0;
        int sumEvenNumbers = 0;
        

      for(int i =0; i<9; i++)
      {
          if(i%2 == 0) 
          {
              //Tek basamkların toplanması işlemi
              sumOddNumbers+= Character.getNumericValue(identityNumberS.charAt(i));
              
          }
           else
          { //Çift basamkların toplanması işlemi
              sumEvenNumbers+=Character.getNumericValue(identityNumberS.charAt(i));
            
          }
      }
      
      //Tek basamaklar yedi ile çarpılıyor.
     sumOddNumbers=sumOddNumbers*7;
     //Yedi ile çarpılan tek basamaklardan çiftler çıkarılıyor. Daha sonra on ile mod alınarak onuncu basamak hesaplanıyor.
     identityNumberS+=String.valueOf((sumOddNumbers-sumEvenNumbers)%10);
    
      
      
    
      
  
      
    }
    //Kimlik numarasını on birinci basamağını hesaplayan fonksiyon
    public void calculateEleventhNumber()
    {
        int sumNumbers = 0;
       
        //ilk on hane toplanıyor.
      for(int i =0; i<10; i++)
      {
          sumNumbers+=(int)identityNumberS.charAt(i);
         
      }
      //İlk on hane toplanıp on ile mod alınarak on birinci hane bulunuyor.
      identityNumberS+= String.valueOf(sumNumbers%10);
       
    }
    
   //Verilen kimlik numarasını kontrol eden fonksiyon
  static boolean controlIdentityNumber(String kontrolEdilecekKimlik)
    {
        int sumOddNumbers =0;
        int sumEvenNumbers =0;
        int sumTopTenNumber =0;
        
      //Kimlik numarasının uzunluğu on bir olmalı
        if(kontrolEdilecekKimlik.length() ==11)
        {
          
            //Kimlik numarasının ilk basamağı sıfır olmamalı
             if(Character.getNumericValue(kontrolEdilecekKimlik.charAt(0))!=0)
         {

                //Kimlik numarasının son basamağı çift sayı olmalı
                 if(Character.getNumericValue(kontrolEdilecekKimlik.charAt(kontrolEdilecekKimlik.length()-1))%2 == 0)
         { 
         
                    for(int i =0; i<9; i++) 
                        {
                                if(i%2 ==0) 
                                    //Tek basamaklar toplanıyor
                                   sumOddNumbers+=Character.getNumericValue(kontrolEdilecekKimlik.charAt(i));
                 
              
                                else
                                   {
                                       //Çift basamaklar toplanıyor
                                   sumEvenNumbers+=Character.getNumericValue(kontrolEdilecekKimlik.charAt(i));
                                   }
                 
                        }
                    //İlk on hanenin toplamı
                    sumTopTenNumber = sumOddNumbers+sumEvenNumbers+Integer.valueOf(kontrolEdilecekKimlik.substring(9,10));
          
                    //Tek haneleri yedi ile çarpıp çiftlerden çıkarıyoruz.Toplam elde ediyoruz
            int corollary = ((sumOddNumbers*7)-sumEvenNumbers);
            
           
         //Elde edilen toplamın on ile mod alınca son basamağa eşit olmalı bunu kontrol ediyoruz.
         if((corollary %10) == Character.getNumericValue(kontrolEdilecekKimlik.charAt(9)));
        { 
                 
                 //İlk on hanenin toplamının on ile mod alınması on birinic haneyi vermeli bunu kontrol ediyoruz.
                 if((sumTopTenNumber % 10) == Character.getNumericValue(kontrolEdilecekKimlik.charAt(10)))
                 {       
                     
                             return true;
   
      
        
                    }
                }
            }
        }      
    }
        return false;   
    }
    
  //Kimlik değerinin hesaplamak için fonksiyonları sıralı bir şekilde çağırma fonksiyonu
    public void createIdentityNumber()
    {
        
         firstStepControlAndConstitute();
         constituteIdentityNumber();
         calculateTenthStep();
         calculateEleventhNumber();
        
    }
    
    public String getKimlikNo()
    {
        return identityNumberS;
    }
      
}
