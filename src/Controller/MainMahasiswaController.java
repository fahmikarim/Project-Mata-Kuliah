/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Controller;

import DAODataMahasiswa.DataMahasiswaDAO;
import DAOImplement.DataMahasiswaImplement;
import Model.DataMahasiswa;
import View.MainViewMahasiswa;
import java.util.List;

/**
 *
 * @author ACER
 */
public class MainMahasiswaController {
    MainViewMahasiswa frame;
    DataMahasiswaImplement implDataMahasiswa;
    List<DataMahasiswa> dm;
    
    public MainMahasiswaController(MainViewMahasiswa frame){
        this.frame = frame;
        implDataMahasiswa = new DataMahasiswaDAO();
    }
    
    public void cetakKTM(){
        DataMahasiswa dm = new DataMahasiswa();
        dm.setNama(frame.getTFNama().getText());
        dm.setFakultas(frame.getTFFakultas().getText());
        dm.setProdi(frame.getTFProdi().getText());
        dm.setAlamat(frame.getTFAlamat().getText());
        dm.setStatus(frame.getTFStatus().getText());
        dm.setNim(Integer.parseInt(frame.getTFNim().getText()));
        
        implDataMahasiswa.cetakKTM(dm);
    
    }
    public void update(){
        DataMahasiswa dm = new DataMahasiswa();
        dm.setNama(frame.getTFNama().getText());
        dm.setFakultas(frame.getTFFakultas().getText());
        dm.setProdi(frame.getTFProdi().getText());
        dm.setAlamat(frame.getTFAlamat().getText());
        dm.setStatus(frame.getTFStatus().getText());
        dm.setNim(Integer.parseInt(frame.getTFNim().getText()));
        
        implDataMahasiswa.update(dm);
    }
    
}
