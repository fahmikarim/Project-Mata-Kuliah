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
public class Kerucut extends Lingkaran {
    protected double tinggiKerucut;
    protected double sisiMiring;
    protected double luasPermukaanKerucut;
    protected double volumeKerucut;

    public Kerucut(double jariJari, double tinggiKerucut) {
        super(jariJari);
        this.tinggiKerucut = tinggiKerucut;
        this.sisiMiring = hitungPythagoras(super.jariJari, tinggiKerucut);
    }
    
    @Override
    public double hitungLuasPermukaan(){
        luasPermukaanKerucut = super.hitungLuas() + Math.PI * super.jariJari * (sisiMiring + super.jariJari);
        return luasPermukaanKerucut;
    }
    
    @Override
    public double hitungVolume(){  //POTENSIAL
        volumeKerucut = (1.0/3.0) * super.hitungLuas() * tinggiKerucut;
        return volumeKerucut;
    }
}
