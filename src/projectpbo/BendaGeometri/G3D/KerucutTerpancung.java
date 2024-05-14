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
public class KerucutTerpancung extends Kerucut {
    protected double jariJariTerpancung;
    protected double tinggiTerpancung;
    protected double sisiMiringTerpancung;
    protected double volumeKerucutTerpancung;
    protected double LuasPermukaanKerucutTerpancung;

    public KerucutTerpancung(double jariJari, double tinggiKerucut, double jariJariTerpancung) {
        super(jariJari, tinggiKerucut);
        this.jariJariTerpancung = jariJariTerpancung;
        this.tinggiTerpancung = jariJariTerpancung / super.jariJari * super.tinggiKerucut;
        this.sisiMiringTerpancung = hitungPythagoras(jariJariTerpancung, tinggiTerpancung);
    }
    
    @Override
    public double hitungLuasPermukaan(){
        LuasPermukaanKerucutTerpancung = Math.PI * (jariJariTerpancung *jariJariTerpancung) + super.hitungLuasPermukaan() - Math.PI * jariJariTerpancung * (sisiMiringTerpancung + jariJariTerpancung);
        return LuasPermukaanKerucutTerpancung;
    }
    
    @Override
    public double hitungVolume(){
        volumeKerucutTerpancung = super.hitungVolume() - 1.0/3.0 * Math.PI * jariJariTerpancung * jariJariTerpancung * tinggiTerpancung;
        return volumeKerucutTerpancung;
    }
    
    
}
