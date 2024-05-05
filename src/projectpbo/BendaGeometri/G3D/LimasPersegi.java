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
    protected double volumeLimasPersegi;

    public LimasPersegi(double sisi, double tinggiLimas) {
        super(sisi);
        this.tinggiLimas = tinggiLimas;
    }
    
    @Override
    public double hitungVolume(){
        volumeLimasPersegi = (1.0/3.0) * tinggiLimas * super.hitungLuas();
        return volumeLimasPersegi;
    }
    
}
