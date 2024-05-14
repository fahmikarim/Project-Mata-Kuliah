/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package projectpbo.BendaGeometri.G3D;

/**
 *
 * @author ACER
 */
public class TemberengBola extends Bola{
    protected double tinggiTemberengBola;
    protected double luasPermukaanTembereng;
    protected double volumeTemberengBola;

    public TemberengBola(double jariJari, double tinggiTemberengBola) {
        super(jariJari);
        this.tinggiTemberengBola = tinggiTemberengBola;
    }
    
    @Override
    public double hitungLuasPermukaan(){
        luasPermukaanTembereng = 2.0 * Math.PI * super.jariJari * tinggiTemberengBola;
        return luasPermukaanTembereng;
    }
    
    @Override
    public double hitungVolume(){
        volumeTemberengBola = 1.0 / 3.0 * Math.PI * tinggiTemberengBola * tinggiTemberengBola * (3.0*super.jariJari - tinggiTemberengBola);
        return volumeTemberengBola;
    }
    
}
