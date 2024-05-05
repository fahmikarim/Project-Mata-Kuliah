package projectpbo;

import projectpbo.BendaGeometri.G2D. *;
import projectpbo.BendaGeometri.G3D. *;


public class Main {
    
    public static void main(String[] args) {
        //BENDA DUA DIMENSI
        Segitiga segitiga = new Segitiga(10,20);
        System.out.println("Luas Segitiga\t\t\t: " + segitiga.hitungLuas());
        
        Persegi persegi = new Persegi(5);
        System.out.println("Luas Persegi\t\t\t: " + persegi.hitungLuas());
        
        JajarGenjang jajarGenjang = new JajarGenjang(8,7);
        System.out.println("Luas Jajar Genjang\t\t: " + jajarGenjang.hitungLuas());
        
        Trapesium trapesium = new Trapesium(10,20,5);
        System.out.println("Luas Trapesium\t\t\t: " + trapesium.hitungLuas());
        
        PersegiPanjang persegiPanjang = new PersegiPanjang(6,9);
        System.out.println("Luas Persegi Panjang\t\t: " + persegiPanjang.hitungLuas());
        
        LayangLayang layangLayang = new LayangLayang(6,2);
        System.out.println("Luas Layang-Layang\t\t: " + layangLayang.hitungLuas());
        
        BelahKetupat belahKetupat = new BelahKetupat(6,4);
        System.out.println("Luas Belah Ketupat\t\t: " + belahKetupat.hitungLuas());
        
        Lingkaran lingkaran = new Lingkaran(7);
        System.out.println("Luas Lingkaran\t\t\t: " + lingkaran.hitungLuas());
        
        Juring juring = new Juring(90,7);
        System.out.println("Luas Juring\t\t\t: " + juring.hitungLuas());
        
        Tembereng tembereng = new Tembereng(90,7);
        System.out.println("Luas Tembereng\t\t\t: " + tembereng.hitungLuas());
        
        //BENDA TIGA DIMENSI
        LimasSegitiga limasSegitiga = new LimasSegitiga(7,4,10);
        System.out.println("Volume Limas Segitiga\t\t: " + limasSegitiga.hitungVolume());
        
        PrismaSegitiga prismaSegitiga = new PrismaSegitiga(7,4,10);
        System.out.println("Volume Prisma Segitiga\t\t: " + prismaSegitiga.hitungVolume());
        
        LimasPersegi limasPersegi = new LimasPersegi(10,9);
        System.out.println("Volume Limas Persegi\t\t: " + limasPersegi.hitungVolume());
        
        BalokPersegi  balokPersegi = new BalokPersegi(10,20);
        System.out.println("Volume Balok Persegi\t\t: " + balokPersegi.hitungVolume());
        
        LimasPersegiPanjang limasPersegiPanjang = new LimasPersegiPanjang(5,8,7);
        System.out.println("Volume Limas Persegi Panjang\t: " + limasPersegiPanjang.hitungVolume());
        
        BalokPersegiPanjang balokPersegiPanjang = new BalokPersegiPanjang(9,4,5);
        System.out.println("Volume Balok PersegiPanjang\t: " + balokPersegiPanjang.hitungVolume());
        
        Tabung tabung = new Tabung(7,10);
        System.out.println("Volume Tabung\t\t\t: " + tabung.hitungVolume());
        
        Kerucut kerucut = new Kerucut(7,10);
        System.out.println("Volume Kerucut\t\t\t: " + kerucut.hitungVolume());
        
        Bola bola = new Bola(7);
        System.out.println("Volume Bola\t\t\t: " + bola.hitungVolume());
                
    }
    
}
