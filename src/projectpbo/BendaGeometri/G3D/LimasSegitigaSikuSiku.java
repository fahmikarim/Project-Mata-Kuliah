/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package projectpbo.BendaGeometri.G3D;

import projectpbo.BendaGeometri.G2D.SegitigaSikuSiku;

/**
 *
 * @author ACER
 */
public class LimasSegitigaSikuSiku extends SegitigaSikuSiku {
    protected double tinggiLimas;
    protected double luasPermukaanLimasSegitiga;
    protected double volumeLimasSegitiga;

    public LimasSegitigaSikuSiku(double alas, double tinggi, double tinggiLimas) {
        super(alas, tinggi);
        this.tinggiLimas = tinggiLimas;
    }

    
    
    @Override
    public double hitungLuasPermukaan(){
        luasPermukaanLimasSegitiga = super.hitungLuas() + 0.5 * tinggiLimas * (super.sisiMiring + super.alas + super.tinggi);
        return luasPermukaanLimasSegitiga;
    }
    
    @Override
    public double hitungVolume(){
        volumeLimasSegitiga = (1.0/3.0) * tinggiLimas * super.luasSegitiga;
        return volumeLimasSegitiga;
    }
    
    
}
