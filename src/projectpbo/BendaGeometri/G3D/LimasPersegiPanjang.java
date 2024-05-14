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
public class LimasPersegiPanjang extends PersegiPanjang {
    protected double tinggiLimas;
    protected double sisiMiring1;
    protected double sisiMiring2;
    protected double luasPermukaanLimasPersegiPanjang;
    protected double volumeLimasPersegiPanjang; 

    public LimasPersegiPanjang(double panjang, double lebar, double tinggiLimas) {
        super(panjang, lebar);
        this.tinggiLimas = tinggiLimas;
        this.sisiMiring1 = hitungPythagoras(super.lebar / 2.0 , tinggiLimas);
        this.sisiMiring1 = hitungPythagoras(super.panjang / 2.0 , tinggiLimas);

    }
    
    @Override
    public double hitungLuasPermukaan(){
        luasPermukaanLimasPersegiPanjang = super.hitungLuas() + (super.panjang * sisiMiring1 + super.lebar * sisiMiring2);
        return luasPermukaanLimasPersegiPanjang;
    }
    
    @Override
    public double hitungVolume(){
        volumeLimasPersegiPanjang = (1.0/3.0) * tinggiLimas * super.luasPersegiPanjang;
        return volumeLimasPersegiPanjang;
    }
    
}
