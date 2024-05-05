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
    protected double volumeLimasPersegiPanjang;

    public LimasPersegiPanjang(double panjang, double lebar, double tinggiLimas) {
        super(panjang, lebar);
        this.tinggiLimas = tinggiLimas;
    }
    
    @Override
    public double hitungVolume(){
        volumeLimasPersegiPanjang = (1.0/3.0) * tinggiLimas * super.hitungLuas();
        return volumeLimasPersegiPanjang;
    }
    
}
