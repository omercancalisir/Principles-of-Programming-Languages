/**
*
* @author Ömer Can ÇALIŞIR - omercancalisir@hotmail.com / Melih Ensar BARIŞIK - barisik.melih@gmail.com
* @since 08.03.2020
* <p>
*   Verilen verideki sesli harf sayisi, cümle sayisi, kelime sayisi, mail sayısı ve web sitesi sayısını 
* hesaplamaya yarayan metodların bulunduğu sınıf yapısı
* </p>
*/
package regexassignment;

import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class Counter {
    
    private int diziUzunlugu;
    private String Kelimeler[];
    private int sesliHarfSayisi;
    private int cumleSayisi;
    private int kelimeSayisi;
    private int mailSayisi;
    private int webSitesiSayisi;
  
    Counter(int diziUzunlugu)
    {
        setDiziUzunlugu(diziUzunlugu);
        Kelimeler = new String[diziUzunlugu];
        sesliHarfSayisi =0;
        cumleSayisi=0;
        kelimeSayisi =0;
        mailSayisi=0;
        webSitesiSayisi=0;
    }
    
    public void setKelimeler(String[] gelenDizi)
    {
        for(int i =0; i<diziUzunlugu; i++)
        {
            Kelimeler[i] = gelenDizi[i];
        }
    }
    
   public void setDiziUzunlugu(int dizininUzunlugu)
   {
       this.diziUzunlugu = dizininUzunlugu;
   }
    
    
    
    
    public void sesliHarfSayisiHesapla()
    {
        
        for(int i =0; i<diziUzunlugu; i++)
        {
            Pattern sesliHarfPattern = Pattern.compile("[aeıioöuüAEIİOÖUÜ]");
            Matcher sesliHarfMatcher = sesliHarfPattern.matcher(Kelimeler[i]);
            
            while(sesliHarfMatcher.find())
            {
                sesliHarfSayisi++;
            }
            
        }
       

      
    }
    
    public void CumleSayisiHesapla()
    {
          for(int i =0; i<diziUzunlugu; i++)
        {
          Pattern cumlePattern = Pattern.compile("[a-zA-Z0-9]+(\\.|\\?|\\!)$");
            Matcher cumleMatcher = cumlePattern.matcher(Kelimeler[i]);
            
            while(cumleMatcher.find())
            {
                cumleSayisi++;
            }
       }
        
    }
    
    public void KelimeSayisiHesapla()
    {
        
        for(int i =0; i<diziUzunlugu; i++)
        {
            if(Kelimeler[i].length()>0)
            {
                kelimeSayisi++;
            }
        }
         
        
    }
    
    public void mailSayisi()
    {
          for(int i =0; i<diziUzunlugu; i++)
        {                                         
            Pattern mailPattern = Pattern.compile("^[a-zA-Z0-9_\\.\\-\\%\\+[^ığüçşöIŞĞÜÇÖ]]+@[a-zA-Z0-9_\\.-[^ığüçşöIŞĞÜÇÖ]]+\\.(com|edu|net|org)?(\\.tr)?$");
            
            
            Matcher mailMatcher = mailPattern.matcher(Kelimeler[i]);
            
            while(mailMatcher.find())
            {
                mailSayisi++;
            }
            
        }
        
    }
    
    public void webSiteSayisi()
    {
          for(int i =0; i<diziUzunlugu; i++)
        {
            Pattern sitePattern = Pattern.compile("^[a-zA-Z0-9+[^@]]+\\.(com|edu|tr|org|com\\.tr|net\\.tr|org\\.tr|edu\\.tr)$");
            Matcher siteMatcher = sitePattern.matcher(Kelimeler[i]);
            
            while(siteMatcher.find())
            {
                webSitesiSayisi++;
                
            }
            
        }
        
    }
    
    public void sonuclariYaz()
    {
        
            System.out.println("Toplam Sesli Harf Sayısı :"+sesliHarfSayisi);
            System.out.println("Toplam Kelime Sayısı     :"+kelimeSayisi);
            System.out.println("Toplam Cümle Sayısı      :"+cumleSayisi);
            System.out.println("Toplam Mail Sayısı       :"+mailSayisi);
            System.out.println("Toplam Web Sitesi Sayısı :"+webSitesiSayisi);
            
        
    }
    
}
