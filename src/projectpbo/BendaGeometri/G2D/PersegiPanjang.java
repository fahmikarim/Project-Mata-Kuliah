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
public class PersegiPanjang extends Benda2D {
    
    protected double panjang;
    protected double lebar;
    protected double luasPersegiPanjang;
    protected double kelilingPersegiPanjang;

    public PersegiPanjang(double panjang, double lebar) {
        this.panjang = panjang;
        this.lebar = lebar;
    }
    
    @Override
    public double hitungKeliling() {
        kelilingPersegiPanjang = 2 * (panjang + lebar);
        return kelilingPersegiPanjang;
    }
    
    @Override
    public double hitungLuas() {
        luasPersegiPanjang = panjang * lebar;
        return luasPersegiPanjang;
    }

    
    
}
