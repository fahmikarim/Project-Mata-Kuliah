/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package DAOImplement;

import Model.DataMahasiswa;
import java.util.List;


/**
 *
 * @author ACER
 */
public interface DataMahasiswaImplement {
    public void insert(DataMahasiswa p);
    public void update(DataMahasiswa p);
    public void loginMahasiswa(DataMahasiswa p);
    public void cetakKTM(DataMahasiswa p);
    public void delete(int nim);
    public List<DataMahasiswa>getAll();
    
}
