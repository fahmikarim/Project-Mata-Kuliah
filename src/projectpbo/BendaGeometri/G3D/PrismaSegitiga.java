/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package projectpbo.BendaGeometri.G3D;

import projectpbo.BendaGeometri.G2D.Segitiga;

/**
 *
 * @author ACER
 */
public class PrismaSegitiga extends Segitiga {
    protected double tinggiPrisma;
    protected double volumePrismaSegitiga;

    public PrismaSegitiga(double alas, double tinggi, double tinggiPrisma) {
        super(alas, tinggi);
        this.tinggiPrisma = tinggiPrisma;
    }
    @Override
    public double hitungVolume(){
        volumePrismaSegitiga = tinggiPrisma * super.hitungLuas();
        return volumePrismaSegitiga;
    }
}
