/**
*
* @author Melih Ensar BARIŞIK ensar.barisik@ogr.sakarya.edu.tr / Ömer Can ÇALIŞIR omer.calisir@ogr.sakarya.edu.tr
* @since  25.04.2020
* <p>
*   Kişi oluşturulan kısım 
* </p>
*/
package RandomPacket;


/**
 *
 * @author bar_i
 */
public class Kisi {
    
  
    private KimlikNo kimlikNo;
    private String isim_soyisim;
    private int yas;
    private Telefon telefonNo;

    public KimlikNo getKimlikNo() {
        return kimlikNo;
    }

    public void setKimlikNo(KimlikNo kimlikNo) {
        this.kimlikNo = kimlikNo;
    }

    public String getIsim_soyisim() {
        return isim_soyisim;
    }

    public void setIsim_soyisim(String isim_soyisim) {
        this.isim_soyisim = isim_soyisim;
    }

    public int getYas() {
        return yas;
    }

    public void setYas(int yas) {
        this.yas = yas;
    }

    public Telefon getTelefonNo() {
        return telefonNo;
    }

    public void setTelefonNo(Telefon telefonNo) {
        this.telefonNo = telefonNo;
    }

    //Dışarıdan alınan nesneleri ve değişkenleri nesne referanslarına ve diğer değişkenlere atama yapan kurucu fonksiyon
    public Kisi(KimlikNo kimlikNo, String isim, int yas, Telefon telefonNo) {
        this.kimlikNo = kimlikNo;
        this.isim_soyisim = isim;
        this.yas = yas;
        this.telefonNo = telefonNo;
    }


    
    
}
