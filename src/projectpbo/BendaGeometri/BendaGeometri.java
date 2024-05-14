/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package projectpbo.BendaGeometri;

/**
 *
 * @author ACER
 */
public interface BendaGeometri {
    double hitungLuas();
    double hitungVolume();
    double hitungKeliling();
    double hitungLuasPermukaan();
    double hitungPythagoras(double a, double b);
    
    //dibuat non static dan public semua
    //ditambah keliling SUDAH
    //trpesium siku-siku SUDAH
    //metode super.hitungLuas diganti langsung ke atribut luas kalau parameter tidak diganti. SUDAH
    //Geometri ruang diganti luas permukaan SUDAH
    //tambah cincin bola 
    //input pake scanner input harus bisa dari class (satu saja) dan main.
    //besok harusnya tambah multi trading (tahap 2) running dapat di interupt untuk mendahulukan proses lain
    //method run tidak langsung semua intine akan kelihatan jika data nya banyak
    //gunakan method random agar data yang diproses banyak
    //data disimpan di array
    //tambah bangun turunan bola
    //turunan bola 2 aja bola (juring tembereng)
    //turnan kerucut kerucut terpancung SUDAH
    
}
