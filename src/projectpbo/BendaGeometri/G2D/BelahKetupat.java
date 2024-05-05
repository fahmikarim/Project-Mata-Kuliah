/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package projectpbo.BendaGeometri.G2D;

import projectpbo.BendaGeometri.Benda2D;

/**
 *
 * @author ACER
 */
public class BelahKetupat extends Benda2D {
    
    protected double diagonal1;
    protected double diagonal2;
    protected double luasBelahKetupat;

    public BelahKetupat(double diagonal1, double diagonal2) {
        this.diagonal1 = diagonal1;
        this.diagonal2 = diagonal2;
    }

    @Override
    public double hitungLuas() {
        luasBelahKetupat = 0.5 * diagonal1 * diagonal2;
        return luasBelahKetupat;
    }
    
}
