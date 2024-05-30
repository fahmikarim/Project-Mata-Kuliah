/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Controller;

import DAODataMahasiswa.DataMahasiswaDAO;
import DAOImplement.DataMahasiswaImplement;
import Model. *;
import View.LoginMahasiswa;
import java.util.List;
/**
 *
 * @author ACER
 */
public class LoginMahasiswaController {
    LoginMahasiswa frame;
    DataMahasiswaImplement implDataMahasiswa;
    List<DataMahasiswa> dm;
    
    public LoginMahasiswaController(LoginMahasiswa frame){
        this.frame = frame;
        implDataMahasiswa = new DataMahasiswaDAO();
        dm = implDataMahasiswa.getAll();
    }
    
    public void loginMahasiswa(){
        DataMahasiswa dm = new DataMahasiswa();
        String nimString = frame.getTFNim().getText();
        int nim = Integer.parseInt(nimString);
        dm.setNim(nim);
        dm.setPassword(frame.getTFPassword().getText());
        
        implDataMahasiswa.loginMahasiswa(dm);
    }
}
