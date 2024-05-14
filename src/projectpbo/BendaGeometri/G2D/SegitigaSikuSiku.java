/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package projectpbo.BendaGeometri.G2D;

import projectpbo.BendaGeometri.Benda2D;

/**
 *
 * @author ACER
 */
public class SegitigaSikuSiku extends Benda2D {
    //segitiga siku-siku
    protected double alas;
    protected double tinggi;
    protected double sisiMiring;
    protected double luasSegitiga;
    protected double kelilingSegitiga;

    public SegitigaSikuSiku(double alas, double tinggi) {
        this.alas = alas;
        this.tinggi = tinggi;
        this.sisiMiring = hitungPythagoras(alas, tinggi);
    }
    
    @Override
    public double hitungKeliling() {
        kelilingSegitiga = alas + tinggi + sisiMiring;
        return kelilingSegitiga;
    }
    
    @Override
    public double hitungLuas() {
        luasSegitiga = 0.5 * alas * tinggi;
        return luasSegitiga;
    }

}
