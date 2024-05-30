/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package DAODataMahasiswa;
import DAOImplement.DataMahasiswaImplement;
import Model.DataMahasiswa;
import java.sql. *;
import java.util.*;
import koneksi.Connector;
import Model. *;
import View.MainViewMahasiswa;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.sql.SQLException;
import javax.swing.JOptionPane;
/**
 *
 * @author ACER
 */
public class DataMahasiswaDAO implements DataMahasiswaImplement{
    Connection connection;
    
    final String select = "select nim, nama, fakultas, prodi, alamat, status from mahasiswa;";
    final String loginMahasiswa = "select nim, nama, fakultas, prodi, alamat, status from mahasiswa where nim=? and password=?;";
    final String update = "UPDATE mahasiswa SET nama=?, fakultas=?, prodi=?,alamat=?, status=? WHERE nim=?;";
    final String delete = "DELETE FROM mahasiswa WHERE nim=?;";
    final String insert = "INSERT INTO `mahasiswa` (`nim`, `nama`, `fakultas`, `prodi`, `alamat`, `password`) VALUES (?, ?, ?, ?, ?, ?); ";
    
    public DataMahasiswaDAO(){
        connection = Connector.connection();
    }
        

    @Override
    public void insert(DataMahasiswa p) {
        PreparedStatement statement = null;
        try{
            statement = connection.prepareStatement(insert, Statement.RETURN_GENERATED_KEYS);
            
            statement.setInt(1, p.getNim());
            statement.setString(2, p.getNama());
            statement.setString(3, p.getFakultas());
            statement.setString(4, p.getProdi());
            statement.setString(5, p.getAlamat());
            statement.setString(6, p.getPassword());
            
            statement.executeUpdate();
            JOptionPane.showMessageDialog(null, 
                    "Daftar berhasil", "Sukses", JOptionPane.INFORMATION_MESSAGE);
        }catch (SQLException ex) {
            ex.printStackTrace();
            System.out.println("Insert gagal: Terjadi kesalahan SQL");
            JOptionPane.showMessageDialog(null, 
                        "Daftar Gagal", "Error",JOptionPane.ERROR_MESSAGE);
        } finally {
            try {
                statement.close();
            } catch (SQLException ex) {
                ex.printStackTrace();
            }
        }
        
    }

    @Override
    public void update(DataMahasiswa p) {
        PreparedStatement statement = null;
        try{
            statement = connection.prepareStatement(update);
            statement.setString(1, p.getNama());
            statement.setString(2, p.getFakultas());
            statement.setString(3, p.getProdi());
            statement.setString(4, p.getAlamat());
            statement.setString(5, p.getStatus());
            statement.setInt(6, p.getNim());
            statement.executeUpdate();
        } catch (SQLException ex) {
            ex.printStackTrace();
            System.out.println("Update gagal: Terjadi kesalahan SQL");
        } finally {
            try {
                statement.close();
            } catch (SQLException ex) {
                ex.printStackTrace();
            }
        }
    }

    @Override
    public void delete(int nim) {
        PreparedStatement statement = null;
        try{
            statement = connection.prepareStatement(delete);
            statement.setInt(1,nim);
            statement.executeUpdate();
        } catch (SQLException ex) {
            ex.printStackTrace();
            System.out.println("Delete gagal: Terjadi kesalahan SQL");
        } finally {
            try {
                statement.close();
            } catch (SQLException ex) {
                ex.printStackTrace();
            }
        }
    }

    @Override
    public List<DataMahasiswa> getAll() {
        List<DataMahasiswa> dm = null;
        try{
            dm = new ArrayList<DataMahasiswa>();
            Statement st = connection.createStatement();
            ResultSet rs = st.executeQuery(select);
            while(rs.next()){
                DataMahasiswa mahasiswa = new DataMahasiswa();
                mahasiswa.setNim(rs.getInt("nim"));
                mahasiswa.setNama(rs.getString("nama"));
                mahasiswa.setFakultas(rs.getString("fakultas"));
                mahasiswa.setProdi(rs.getString("prodi")); 
                mahasiswa.setAlamat(rs.getString("alamat"));
                mahasiswa.setStatus(rs.getString("status"));
                
                dm.add(mahasiswa);
            }
                
        }catch(SQLException ex){
            Logger.getLogger(DataMahasiswaDAO.class.getName()).
                    log(Level.SEVERE, null, ex);
        }
        return dm;
    }

    @Override
    public void loginMahasiswa(DataMahasiswa p) {
        PreparedStatement statement = null;
        ResultSet resultSet = null;
        try {
            statement = connection.prepareStatement(loginMahasiswa);
            statement.setInt(1, p.getNim());
            statement.setString(2, p.getPassword());
            resultSet = statement.executeQuery();
            if (resultSet.next()) {
                System.out.println("login berhasil");
                p.setNim(resultSet.getInt("nim"));
                p.setNama(resultSet.getString("nama"));
                p.setFakultas(resultSet.getString("fakultas"));
                p.setProdi(resultSet.getString("prodi"));
                p.setAlamat(resultSet.getString("alamat"));
                p.setStatus(resultSet.getString("status"));
                
                MainViewMahasiswa v = new MainViewMahasiswa(p);

                v.setVisible(true);
                v.setLocationRelativeTo(null);
                
            } else {
                JOptionPane.showMessageDialog(null, 
                        "Username atau Password salah", "Error",JOptionPane.ERROR_MESSAGE);
                System.out.println("login gagal: NIM atau Password salah");
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

    @Override
    public void cetakKTM(DataMahasiswa p) {
        String filePath = "D:\\Fahmi File\\KULIAH\\SEM 4\\Prak PBO\\Projek Akhir\\projekakhir_prakPBO\\ktm\\ktm" + p.getNim() + ".txt";
        try(PrintWriter writer = new PrintWriter(filePath)){
            writer.println("=====================================");
            writer.println("       KARTU TANDA MAHASISWA       ");
            writer.println("=====================================");
            writer.println("   Nama\t\t: " + p.getNama());
            writer.println("   Nim\t\t: " + p.getNim());
            writer.println("   Fakultas\t: " + p.getFakultas());
            writer.println("   Prodi\t: " + p.getProdi());
            writer.println("   Alamat\t: " + p.getAlamat());
            writer.println("          ");
            writer.println("");
            writer.println("\t\t\tRektor");
            writer.println("");
            writer.println("\t\t\t TTD");
            writer.println("");
            writer.println(" KTM jangan sampai hilang/Rusak");
            writer.println("=====================================");
            JOptionPane.showMessageDialog(null, 
                    "Cetak berhasil", "Sukses", JOptionPane.INFORMATION_MESSAGE);
        } catch (FileNotFoundException e) {
            JOptionPane.showMessageDialog(null, 
                        "Cetak gagal", "Error",JOptionPane.ERROR_MESSAGE);
        }
    }
    
    
    
}
