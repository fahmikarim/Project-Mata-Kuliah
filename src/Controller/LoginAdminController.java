/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Controller;

import DAODataAdmin.DataAdminDAO;
import DAOImplement.DataAdminImplement;
import Model.DataAdmin;
import View.LoginViewAdmin;
import java.util.List;

/**
 *
 * @author ACER
 */
public class LoginAdminController {
    LoginViewAdmin frame;
    DataAdminImplement implDataAdmin;
    List<DataAdmin> da;
    
    public LoginAdminController(LoginViewAdmin frame){
        this.frame = frame;
        implDataAdmin = new DataAdminDAO();
    }
    
    public void loginAdmin(){
        DataAdmin da = new DataAdmin();
        da.setUsername(frame.getTFUsername().getText());
        da.setPassword(frame.getTFPassword().getText());
        
        implDataAdmin.loginAdmin(da);
    }
}
