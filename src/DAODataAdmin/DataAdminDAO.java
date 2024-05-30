/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package DAODataAdmin;
import DAOImplement.DataAdminImplement;
import java.sql. *;
import java.util.*;
import koneksi.Connector;
import Model. *;
import View. *;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.sql.SQLException;
import javax.swing.JOptionPane;
/**
 *
 * @author ACER
 */
public class DataAdminDAO implements DataAdminImplement{
    Connection connection;
    
    final String loginAdmin = "select username from admin where username=? and password=?;";
    
    public DataAdminDAO(){
        connection = Connector.connection();
    }

    @Override
    public void loginAdmin(DataAdmin p) {
        PreparedStatement statement = null;
        ResultSet resultSet = null;
        try {
            statement = connection.prepareStatement(loginAdmin);
            statement.setString(1, p.getUsername());
            statement.setString(2, p.getPassword());
            resultSet = statement.executeQuery();
            if (resultSet.next()) {
                System.out.println("login berhasil");
                
                MainViewAdmin v = new MainViewAdmin();
                v.setVisible(true);
                v.setLocationRelativeTo(null);
                
            } else {
                System.out.println("login gagal: NIM atau Password salah");
                JOptionPane.showMessageDialog(null, 
                        "Username atau Password salah", "Error",JOptionPane.ERROR_MESSAGE);
            }
        } catch (SQLException ex) {
            ex.printStackTrace();
            System.out.println("login gagal: Terjadi kesalahan SQL");
        } finally {
            try {
                if (resultSet != null) {
                    resultSet.close();
                }
                if (statement != null) {
                    statement.close();
                }
            } catch (SQLException ex) {
                ex.printStackTrace();
            }
        }
    }
    
}
