/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Controller;

import DAODataMahasiswa.DataMahasiswaDAO;
import DAOImplement.DataMahasiswaImplement;
import java.util.List;
import Model. *;
import View.MainViewAdmin;
        
/**
 *
 * @author ACER
 */
public class DataMahasiswaController {
    MainViewAdmin frame;
    DataMahasiswaImplement implDataMahasiswa;
    List<DataMahasiswa> dm;
    
    public DataMahasiswaController(MainViewAdmin frame){
        this.frame = frame;
        implDataMahasiswa = new DataMahasiswaDAO();
        dm = implDataMahasiswa.getAll();
    }
    
    public void isitabel(){
        dm = implDataMahasiswa.getAll();
        ModelTabelDataMahasiswa mm = new ModelTabelDataMahasiswa(dm);
        frame.getTabelDataMahasiswa().setModel(mm);
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
    
    public void delete(){
        int id = Integer.parseInt(frame.getTFNim().getText());
        implDataMahasiswa.delete(id);
    }
}
