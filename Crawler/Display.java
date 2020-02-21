package grp32;

import java.awt.BorderLayout;

import java.awt.Dimension;
import java.awt.EventQueue;
import java.awt.FlowLayout;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.WindowConstants;
import javax.swing.border.EmptyBorder;
import javax.swing.table.AbstractTableModel;
import javax.swing.table.TableModel;																												//
import javax.swing.table.TableRowSorter;	
import javax.swing.RowSorter;																														//
import javax.swing.SortOrder;	

import com.opencsv.CSVReader;
import com.opencsv.CSVReaderBuilder;

import java.util.*;

import javax.swing.DefaultComboBoxModel;
import javax.swing.DefaultRowSorter;
import javax.swing.JComboBox;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
public class Display extends JPanel{
	
	private final JTable table;

    private static String fn1;
    private static String fn2;
    private static String mainFile;
    private static String sc1;
    private static String sc2;

    
    
    public static void setFn1(String fn){
    	Display.fn1 = fn;
    	Display.mainFile = fn;
    }
    public static void setFn2(String fn){
    	Display.fn2 = fn;
    	Display.mainFile = fn;
    }
    
    public void displayDisplay(){  	
    	MyModel NewModel;
        NewModel = new MyModel();
    	
        File DataFile;
        DataFile = new File(mainFile);	
        
        ArrayList<String[]> Rs2 = new ArrayList<>();
        

        try {

            FileReader filereader = new FileReader(mainFile); 

            // create csvReader object and skip first Line 
            CSVReader csvReader = new CSVReaderBuilder(filereader).build(); 
            String[] temp = csvReader.readNext();
            NewModel.setColumnNames(temp);
            
            List<String[]> allData = csvReader.readAll();
            
            
            for (String[] row : allData) { 

            	Rs2.add(row);
            }
            table.setModel(NewModel);
            NewModel.AddCSVData(Rs2);
            System.out.println(NewModel.getColumnCount());
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (Exception e){
            e.printStackTrace();
        }
        
        TableRowSorter<TableModel> sorter;
        sorter = new TableRowSorter<>(table.getModel());																	//start sort
        table.setRowSorter(sorter);
        List<RowSorter.SortKey> sortKeys;
        sortKeys = new ArrayList<>();
         
        int columnIndexToSort = 1;
        
        while (columnIndexToSort <NewModel.getColumnCount()){
        	sortKeys.add(new RowSorter.SortKey(columnIndexToSort++, SortOrder.ASCENDING));
        }
         
        sorter.setSortKeys(sortKeys);
        sorter.sort();				
        								
    }
    
    public Display() {  	
        super(new BorderLayout(3, 3));
        
        this.table = new JTable(new MyModel());
        this.table.setPreferredScrollableViewportSize(new Dimension(700, 70));
        this.table.setFillsViewportHeight(true);
        JPanel ButtonOpen;
        ButtonOpen = new JPanel(new FlowLayout(FlowLayout.CENTER));
        add(ButtonOpen, BorderLayout.SOUTH);
        

        JScrollPane scrollPane;
        scrollPane = new JScrollPane(table);

        add(scrollPane, BorderLayout.CENTER);

        setBorder(new EmptyBorder(5, 5, 5, 5));
        
        MyModel NewModel;
        NewModel = new MyModel();
        this.table.setModel(NewModel);
        
        this.displayDisplay();
    }

    public void createAndShowGUI() {

        JFrame frame;
        frame = new JFrame("Displaying table data from "+Display.mainFile);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        Display newContentPane;
        newContentPane = new Display();
        frame.setContentPane(newContentPane);

        frame.pack();
        frame.setSize(1500, 1000);																													//change window size
        frame.setVisible(true);
    }

    class MyModel extends AbstractTableModel {
        private String[] columnNames = { "Username", "Tweet", " Retweet_Count", "Favourite_Count", "Date" };						//for twitter
//        private final String[] columnNames = { "Article_Category", "Article_Title", " Date_Published" };									//for CNA
    	private ArrayList<String[]> Data = new ArrayList<String[]>();																		//change column name(one line above)

        public void AddCSVData(ArrayList<String[]> DataIn) {
            this.Data = DataIn;
            this.fireTableDataChanged();
        }

        public void setColumnNames(String[] colsName){columnNames = colsName;}
        
        @Override
        public int getColumnCount() {
            return columnNames.length;
        }

        @Override
        public int getRowCount() {
            return Data.size();
        }

        @Override
        public String getColumnName(int col) {
            return columnNames[col];
        }

        @Override
        public Object getValueAt(int row, int col) {
            return Data.get(row)[col];
        }
    }

}