/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Model;
import java.util.List;
import javax.swing.table.AbstractTableModel;
/**
 *
 * @author ACER
 */
public class ModelTabelDataMahasiswa extends AbstractTableModel{
    List<DataMahasiswa> dm;
    
    public ModelTabelDataMahasiswa(List<DataMahasiswa> dm){
        this.dm = dm;
    }
    
    @Override
    public int getRowCount() {
        return dm.size();
        
    }

    @Override
    public int getColumnCount() {
        return 6;
    }
    
    @Override
    public String getColumnName(int column){
        switch(column){
            case 0:
                return "NIM";
            case 1:
                return "NAMA";
            case 2:
                return "FAKULTAS";
            case 3:
                return "PRODI";
            case 4:
                return "ALAMAT";
            case 5:
                return "STATUS";
            default:
                return null;   
        }
        
    }

    @Override
    public Object getValueAt(int row, int column) {
        switch(column){
            case 0:
                return dm.get(row).getNim();
            case 1:
                return dm.get(row).getNama();
            case 2:
                return dm.get(row).getFakultas();
            case 3:
                return dm.get(row).getProdi();
            case 4:
                return dm.get(row).getAlamat();
            case 5:
                return dm.get(row).getStatus();
            default:
                return null;   
        }
    }
    
}
