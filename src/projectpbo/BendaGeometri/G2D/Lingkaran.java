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
public class Lingkaran extends Benda2D{
    
    protected double jariJari;
    protected double luasLingkaran;
    protected double kelilingLingkaran;

    public Lingkaran(double jariJari) {
        this.jariJari = jariJari;
    }
    
    @Override
    public double hitungKeliling() {
        kelilingLingkaran = Math.PI * (jariJari + jariJari);
        return kelilingLingkaran;
    }
    
    @Override
    public double hitungLuas() {
        luasLingkaran = Math.PI * jariJari * jariJari;
        return luasLingkaran;
    }

    
    
}
