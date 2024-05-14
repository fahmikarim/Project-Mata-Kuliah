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
public class Bola extends Lingkaran{
    protected double luasPermukaanBola;
    protected double volumeBola;

    public Bola(double jariJari) {
        super(jariJari);
    }
    
    @Override
    public double hitungLuasPermukaan(){
        luasPermukaanBola = 4.0 * super.hitungLuas();
        return luasPermukaanBola;
    }
    
    @Override
    public double hitungVolume(){
        volumeBola = (4.0/3.0) * super.luasLingkaran * super.jariJari;
        return volumeBola;
    }
}
