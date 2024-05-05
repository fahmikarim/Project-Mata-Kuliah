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
public class Segitiga extends Benda2D {
    
    protected double alas;
    protected double tinggi;
    protected double luasSegitiga;

    public Segitiga(double alas, double tinggi) {
        this.alas = alas;
        this.tinggi = tinggi;
    }

    @Override
    public double hitungLuas() {
        luasSegitiga = 0.5 * alas * tinggi;
        return luasSegitiga;
    }
    
}
