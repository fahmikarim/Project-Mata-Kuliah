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
public class LimasSegitiga extends Segitiga {
    protected double tinggiLimas;
    protected double volumeLimasSegitiga;

    public LimasSegitiga(double alas, double tinggi, double tinggiLimas) {
        super(alas, tinggi);
        this.tinggiLimas = tinggiLimas;
    }
    @Override
    public double hitungVolume(){
        volumeLimasSegitiga = (1.0/3.0) * tinggiLimas * super.hitungLuas();
        return volumeLimasSegitiga;
    }
    
    
}
