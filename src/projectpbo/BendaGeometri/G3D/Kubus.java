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
public class Kubus extends Persegi {
    protected double luasPermukaanKubus;
    protected double volumeKubus;

    public Kubus(double sisi) {
        super(sisi);
    }
    
    @Override
    public double hitungLuasPermukaan(){
        luasPermukaanKubus = 6.0 * super.hitungLuas();
        return luasPermukaanKubus;
    }
    
    @Override
    public double hitungVolume(){
        volumeKubus = super.sisi * super.luasPersegi;
        return volumeKubus;
    }
}
