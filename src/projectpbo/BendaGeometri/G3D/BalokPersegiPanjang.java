/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package projectpbo.BendaGeometri.G3D;

import projectpbo.BendaGeometri.G2D.PersegiPanjang;

/**
 *
 * @author ACER
 */
public class BalokPersegiPanjang extends PersegiPanjang{
    protected double tinggiBalok;
    protected double luasPermukaanBalokPersegiPanjang;
    protected double volumeBalokPersegiPanjang;

    public BalokPersegiPanjang(double panjang, double lebar, double tinggiBalok) {
        super(panjang, lebar);
        this.tinggiBalok = tinggiBalok;
    }
    
    @Override
    public double hitungLuasPermukaan(){
        luasPermukaanBalokPersegiPanjang = 2.0 * (super.hitungLuas() + tinggiBalok * (super.lebar + super.panjang));
        return luasPermukaanBalokPersegiPanjang;
    }
    
    @Override
    public double hitungVolume(){
        volumeBalokPersegiPanjang = tinggiBalok * super.luasPersegiPanjang;
        return volumeBalokPersegiPanjang;
    }
}
