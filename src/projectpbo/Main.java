package projectpbo;

import projectpbo.BendaGeometri.G2D. *;
import projectpbo.BendaGeometri.G3D. *;


public class Main {
    
    public static void main(String[] args) {
        //BENDA DUA DIMENSI
        SegitigaSikuSiku segitiga = new SegitigaSikuSiku(3,4);
        System.out.println("Keliling Segitiga\t\t: " + segitiga.hitungKeliling());
        System.out.println("Luas Segitiga\t\t\t: " + segitiga.hitungLuas());
        
        Persegi persegi = new Persegi(5);
        System.out.println("Keliling Persegi\t\t: " + persegi.hitungKeliling());
        System.out.println("Luas Persegi\t\t\t: " + persegi.hitungLuas());
        
        JajarGenjang jajarGenjang = new JajarGenjang(8,7);
        System.out.println("Keliling Jajar Genjang\t\t: " + jajarGenjang.hitungKeliling());
        System.out.println("Luas Jajar Genjang\t\t: " + jajarGenjang.hitungLuas());
        
        TrapesiumSikuSiku trapesium = new TrapesiumSikuSiku(10,20,5);
        System.out.println("Keliling Trapesium\t\t: " + trapesium.hitungKeliling());
        System.out.println("Luas Trapesium\t\t\t: " + trapesium.hitungLuas());
        
        PersegiPanjang persegiPanjang = new PersegiPanjang(6,9);
        System.out.println("Keliling Persegi Panjang\t: " + persegiPanjang.hitungKeliling());
        System.out.println("Luas Persegi Panjang\t\t: " + persegiPanjang.hitungLuas());
        
        LayangLayang layangLayang = new LayangLayang(6,4);
        System.out.println("Keliling Layang-Layang\t\t: " + layangLayang.hitungKeliling());
        System.out.println("Luas Layang-Layang\t\t: " + layangLayang.hitungLuas());
        
        BelahKetupat belahKetupat = new BelahKetupat(18,24);
        System.out.println("Keliling Belah Ketupat\t\t: " + belahKetupat.hitungKeliling());
        System.out.println("Luas Belah Ketupat\t\t: " + belahKetupat.hitungLuas());
        
        Lingkaran lingkaran = new Lingkaran(7);
        System.out.println("Keliling Lingkaran\t\t: " + lingkaran.hitungKeliling());
        System.out.println("Luas Lingkaran\t\t\t: " + lingkaran.hitungLuas());
        
        Juring juring = new Juring(90,7);
        System.out.println("Keliling Juring\t\t\t: " + juring.hitungKeliling());
        System.out.println("Luas Juring\t\t\t: " + juring.hitungLuas());
        
        Tembereng tembereng = new Tembereng(90,7);
        System.out.println("Keliling Tembereng\t\t: " + tembereng.hitungKeliling());
        System.out.println("Luas Tembereng\t\t\t: " + tembereng.hitungLuas());
        
        //BENDA TIGA DIMENSI
        LimasSegitigaSikuSiku limasSegitigaSikuSiku = new LimasSegitigaSikuSiku(6,8,12);
        System.out.println("Luas Permukaan Limas Segitiga\t: " + limasSegitigaSikuSiku.hitungLuasPermukaan());
        System.out.println("Volume Limas Segitiga\t\t: " + limasSegitigaSikuSiku.hitungVolume());
        
        PrismaSegitigaSikuSiku prismaSegitiga = new PrismaSegitigaSikuSiku(6,8,12);
        System.out.println("Luas Permukaan Prisma Segitiga\t: " + prismaSegitiga.hitungLuasPermukaan());
        System.out.println("Volume Prisma Segitiga\t\t: " + prismaSegitiga.hitungVolume());
        
        LimasPersegi limasPersegi = new LimasPersegi(6,4);
        System.out.println("Luas Permukaan Limas Persegi\t: " + limasPersegi.hitungLuasPermukaan());
        System.out.println("Volume Limas Persegi\t\t: " + limasPersegi.hitungVolume());
        
        LimasPersegiPanjang limasPersegiPanjang = new LimasPersegiPanjang(5,8,7);
        System.out.println("Luas Permukaan Limas Persegi Panjang: " + limasPersegiPanjang.hitungLuasPermukaan());
        System.out.println("Volume Limas Persegi Panjang\t: " + limasPersegiPanjang.hitungVolume());
        
        BalokPersegiPanjang balokPersegiPanjang = new BalokPersegiPanjang(9,4,5);
        System.out.println("Luas Permukaan Balok PersegiPanjang: " + balokPersegiPanjang.hitungLuasPermukaan());
        System.out.println("Volume Balok PersegiPanjang\t: " + balokPersegiPanjang.hitungVolume());
        
        Tabung tabung = new Tabung(7,10);
        System.out.println("Luas Permukaan Tabung\t\t: " + tabung.hitungLuasPermukaan());
        System.out.println("Volume Tabung\t\t\t: " + tabung.hitungVolume());
        
        Kerucut kerucut = new Kerucut(7,10);
        System.out.println("Luas Permukaan Kerucut\t\t: " + kerucut.hitungLuasPermukaan());
        System.out.println("Volume Kerucut\t\t\t: " + kerucut.hitungVolume());
        
        Bola bola = new Bola(7);
        System.out.println("Luas Permukaan Bola\t\t: " + bola.hitungLuasPermukaan());
        System.out.println("Volume Bola\t\t\t: " + bola.hitungVolume());
        
        Kubus kubus = new Kubus(5);
        System.out.println("Luas Permukaan Kubus\t\t: " + kubus.hitungLuasPermukaan());
        System.out.println("Volume Kubus\t\t\t: " + kubus.hitungVolume());
        
        KerucutTerpancung kerucutTerpancung = new KerucutTerpancung(10.5,24,7);
        System.out.println("Luas Permukaan Kerucut Terpancung : " + kerucutTerpancung.hitungLuasPermukaan());
        System.out.println("Volume Kerucut Terpancung\t: " + kerucutTerpancung.hitungVolume());
        
        TemberengBola temberengBola = new TemberengBola(10,4);
        System.out.println("Luas Permukaan Tembereng Bola\t : " + temberengBola.hitungLuasPermukaan());
        System.out.println("Volume Tembereng Bola\t:  " + temberengBola.hitungVolume());
                
    }
    
}
