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
public class JajarGenjang extends Benda2D {
    
    protected double alas;
    protected double tinggi;
    protected double luasJajarGenjang;
    protected double kelilingJajarGenjang;

    public JajarGenjang(double alas, double tinggi) {
        this.alas = alas;
        this.tinggi = tinggi;
    }
    
     @Override
    public double hitungKeliling() {
        kelilingJajarGenjang = 2.0 * (alas + tinggi);
        return kelilingJajarGenjang;
    }
    
    @Override
    public double hitungLuas() {
        luasJajarGenjang = alas * tinggi;
        return luasJajarGenjang;
    }

    
}
