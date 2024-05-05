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
public class Trapesium extends Benda2D{
    
    protected double sisiAtas;
    protected double sisiBawah;
    protected double tinggi;
    protected double luasTrapesium;

    public Trapesium(double sisiAtas, double sisiBawah, double tinggi) {
        this.sisiAtas = sisiAtas;
        this.sisiBawah = sisiBawah;
        this.tinggi = tinggi;
    }

    @Override
    public double hitungLuas() {
        luasTrapesium = (sisiAtas + sisiBawah) * tinggi * 0.5;
        return luasTrapesium;
    }
    
}
