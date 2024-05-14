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
public class Tembereng extends Juring{
    protected double luasTembereng;
    protected double kelilingTembereng;

    public Tembereng(double sudut, double jariJari) {
        super(sudut, jariJari);
    }
    
    @Override
    public double hitungKeliling(){
        kelilingTembereng = 2.0 * super.jariJari * (super.sudut / 360.0 * Math.PI + Math.sin(super.sudut / 360.0));
        return kelilingTembereng;
    }
    
    @Override
    public double hitungLuas(){
        luasTembereng = super.hitungLuas() - (0.5 * super.jariJari * super.jariJari);
        return luasTembereng;
    }
        
}
