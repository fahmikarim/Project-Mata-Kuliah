/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package projectpbo.BendaGeometri.G2D;

/**
 *
 * @author ACER
 */
public class Juring extends Lingkaran {
    protected double sudut;
    protected double luasJuring;
    protected double kelilingJuring;

    public Juring(double sudut, double jariJari) {
        super(jariJari);
        this.sudut = sudut;
    }
    
    @Override
    public double hitungKeliling(){
        kelilingJuring = super.hitungKeliling() * (sudut/360.0) + (2.0* super.jariJari);
        return kelilingJuring;
    }
    
    @Override
    public double hitungLuas(){
        luasJuring = (sudut /360.0) * super.hitungLuas();
        return luasJuring;
    }
    
}
