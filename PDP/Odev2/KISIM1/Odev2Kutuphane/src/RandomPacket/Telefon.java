/**
*
* @author Melih Ensar BARIŞIK ensar.barisik@ogr.sakarya.edu.tr / Ömer Can ÇALIŞIR omer.calisir@ogr.sakarya.edu.tr
* @since  25.04.2020
* <p>
*  Telefon oluşturulan kısım
* </p>
*/
package RandomPacket;

/**
 *
 * @author bar_i
 */
public class Telefon {
    
        private String telefonNo;
       
        //Telefon numarasının sahip olduğu imei nesnesi
        private IMEINo IMEINo1;
        
        //Operatorlerin sahip olduğu alan kodları
    private String[] operatorler = {"501", "505", "506", "507", "551", "552",
            "553", "554", "555", "559",
            "530", "531", "532", "533", "534", "535", "536", "537", "538", "539", "561",
            "540", "541", "542", "543", "544", "545", "546", "547", "548", "549"};

     public Telefon()
    {
            IMEINo1 = new IMEINo();
    }
        
    public String getTelefonNo() {
        return telefonNo;
    }

    public void setTelefonNo(String telefonNo) {
        this.telefonNo = telefonNo;
    }

    public IMEINo getIMEINo() {
        return IMEINo1;
    }

   

  
    
    public void telefonVeIMEINoUret() {
       //Telefon numarasının ilk hanesine sıfır değeri veriliyor.
        telefonNo = "0";
        //Operatorlerden alan kodu rastgele seçilip üzerine ekleniyor.
        telefonNo += operatorler[Rastgele.produceRandomDigit(operatorler.length-1)];
        //Kalan yedi sayı randım şekilde üretilip oluşan telefon numarasına ekleniyor.
        telefonNo +=Rastgele.produceRandomNumber(7);

     
        //Imei üretmek için gerekli fonksiyonu çağırıyor.
         IMEINo1.createImei();

    }


 
    
    
    
}
