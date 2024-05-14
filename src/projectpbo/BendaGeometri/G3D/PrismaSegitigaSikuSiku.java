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
public class PrismaSegitigaSikuSiku extends SegitigaSikuSiku {
    protected double tinggiPrisma;
    protected double luasPremukaanPrismaSegitiga;
    protected double volumePrismaSegitiga;

    public PrismaSegitigaSikuSiku(double alas, double tinggi, double tinggiPrisma) {
        super(alas, tinggi);
        this.tinggiPrisma = tinggiPrisma;
    }
    
    @Override
    public double hitungLuasPermukaan(){
        luasPremukaanPrismaSegitiga = 2.0 * super.hitungLuas() + tinggiPrisma * (super.sisiMiring + super.alas + super.tinggi); 
        return luasPremukaanPrismaSegitiga;
    }
    
    @Override
    public double hitungVolume(){
        volumePrismaSegitiga = tinggiPrisma * super.luasSegitiga;
        return volumePrismaSegitiga;
    }
}
