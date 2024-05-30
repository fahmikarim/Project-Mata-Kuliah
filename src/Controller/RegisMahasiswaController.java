/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Controller;

import DAODataMahasiswa.DataMahasiswaDAO;
import DAOImplement.DataMahasiswaImplement;
import Model.DataMahasiswa;
import View.RegisViewMahasiswa;
import java.util.List;

/**
 *
 * @author ACER
 */
public class RegisMahasiswaController {
    RegisViewMahasiswa frame;
    DataMahasiswaImplement implDataMahasiswa;
    List<DataMahasiswa> dm;
    
    public RegisMahasiswaController(RegisViewMahasiswa frame){
        this.frame = frame;
        implDataMahasiswa = new DataMahasiswaDAO();
        
    }
    
    public void insert(){
        DataMahasiswa dm = new DataMahasiswa();
        dm.setNama(frame.getTFNama().getText());
        dm.setPassword(frame.getTFPassword().getText());
        dm.setFakultas(frame.getTFFakultas().getText());
        dm.setProdi(frame.getTFProdi().getText());
        dm.setAlamat(frame.getTFAlamat().getText());
        dm.setNim(Integer.parseInt(frame.getTFNim().getText()));
        
        implDataMahasiswa.insert(dm);
    }
    
}
