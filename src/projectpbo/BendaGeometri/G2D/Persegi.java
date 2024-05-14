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
public class Persegi extends Benda2D implements Runnable {
    
    Thread threadPersegi;
    protected double sisi;
    protected double luasPersegi;
    protected double kelilingPersegi;

    public Persegi(double sisi) {
        this.sisi = sisi;
    }
    
    @Override
    public double hitungKeliling(){
        kelilingPersegi = 4 * sisi;
        return kelilingPersegi;
    }
    
    @Override
    public double hitungLuas() {
        luasPersegi = sisi * sisi;
        return luasPersegi;
    }

    @Override
    public void run() {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
       
}
