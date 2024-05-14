/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package projectpbo.BendaGeometri.G3D;

import projectpbo.BendaGeometri.G2D.Persegi;

/**
 *
 * @author ACER
 */
public class LimasPersegi extends Persegi {
    protected double tinggiLimas;
    protected double sisiMiring;
    protected double kelilingLimasPersegi;
    protected double volumeLimasPersegi;

    public LimasPersegi(double sisi, double tinggiLimas) {
        super(sisi);
        this.tinggiLimas = tinggiLimas;
        this.sisiMiring = hitungPythagoras(tinggiLimas, 0.5 * super.sisi);
    }
    
    @Override
    public double hitungLuasPermukaan(){
        kelilingLimasPersegi = super.hitungLuas() + 4.0 * (super.sisi * sisiMiring * 0.5);
        return kelilingLimasPersegi;
    }
    
    @Override
    public double hitungVolume(){
        volumeLimasPersegi = (1.0/3.0) * tinggiLimas * super.luasPersegi;
        return volumeLimasPersegi;
    }
    
}
