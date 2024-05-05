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
public class BalokPersegi extends Persegi {
    protected double tinggiBalok;
    protected double volumeBalokPersegi;

    public BalokPersegi(double sisi, double tinggiBalok) {
        super(sisi);
        this.tinggiBalok = tinggiBalok;
    }
    
    @Override
    public double hitungVolume(){
        volumeBalokPersegi = tinggiBalok * super.hitungLuas();
        return volumeBalokPersegi;
    }
}
