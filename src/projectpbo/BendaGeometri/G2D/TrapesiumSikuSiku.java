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
public class TrapesiumSikuSiku extends Benda2D{
    //trapesium siku siku
    protected double sisiAtas;
    protected double sisiBawah;
    protected double tinggi;
    protected double sisiMiring;
    protected double luasTrapesium;
    protected double kelilingTrapesium;

    public TrapesiumSikuSiku(double sisiAtas, double sisiBawah, double tinggi) {
        this.sisiAtas = sisiAtas;
        this.sisiBawah = sisiBawah;
        this.tinggi = tinggi;
        this.sisiMiring = hitungPythagoras(sisiBawah - sisiAtas, tinggi);
    }
    
    @Override
    public double hitungKeliling() {
        kelilingTrapesium = sisiAtas + sisiBawah + tinggi + sisiMiring;
        return kelilingTrapesium;
    }
    
    @Override
    public double hitungLuas() {
        luasTrapesium = (sisiAtas + sisiBawah) * tinggi * 0.5;
        return luasTrapesium;
    }

    
    
}
