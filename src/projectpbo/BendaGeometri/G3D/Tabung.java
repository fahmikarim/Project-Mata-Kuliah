/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package projectpbo.BendaGeometri.G3D;

import projectpbo.BendaGeometri.G2D.Lingkaran;

/**
 *
 * @author ACER
 */
public class Tabung extends Lingkaran {
    protected double tinggiTabung;
    protected double luasPermukaanTabung;
    protected double volumeTabung;

    public Tabung(double jariJari, double tinggiTabung) {
        super(jariJari);
        this.tinggiTabung = tinggiTabung;
    }
    
    @Override
    public double hitungLuasPermukaan(){
        luasPermukaanTabung = 2 * super.hitungLuas() + super.hitungKeliling() * tinggiTabung;
        return luasPermukaanTabung;
    }
    
    @Override
    public double hitungVolume(){
        volumeTabung = tinggiTabung * super.luasLingkaran;
        return volumeTabung;
    }
}
