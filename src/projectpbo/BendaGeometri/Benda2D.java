/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package projectpbo.BendaGeometri;

/**
 *
 * @author ACER
 */
public abstract class Benda2D implements BendaGeometri {
    @Override
    public abstract double hitungLuas();
    @Override
    public double hitungVolume(){
        double volumeGeometri2D = 0;
        return volumeGeometri2D;
    }
    @Override
    public abstract double hitungKeliling();
    @Override
    public double hitungLuasPermukaan(){
        double luasPermukaanGeometri2D = 0;
        return luasPermukaanGeometri2D;
    }
    @Override
    public double hitungPythagoras(double a, double b){
        double c = Math.sqrt(a*a + b*b);
        return c;
    }
}
