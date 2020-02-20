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
public class Analysis extends JPanel{
	
	private final JTable table;

    private static String fn;
    private static String sc1;
    private static String sc2;
    
    public static void setFn(String fn){
    	Analysis.fn = fn;
    }
    public static void setSc1(String fn){																//file name
    	Analysis.sc1 = fn;
    }
    public static void setSc2(String fn){																//file name
    	Analysis.sc2 = fn;
    }
    
    
    public Analysis() {  	
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
        CSVFile Rd;
        Rd = new CSVFile();
        MyModel NewModel;
        NewModel = new MyModel();
        this.table.setModel(NewModel);
        
        this.analyse();
        																							//change filename
        
//        System.out.println("Rows: " + NewModel.getRowCount());
//        System.out.println("Cols: " + NewModel.getColumnCount());
        TableRowSorter<TableModel> sorter;
        sorter = new TableRowSorter<>(table.getModel());																	//start sort
        table.setRowSorter(sorter);
        List<RowSorter.SortKey> sortKeys;
        sortKeys = new ArrayList<>();
         
        int columnIndexToSort = 1;
        while (columnIndexToSort <3){
        	sortKeys.add(new RowSorter.SortKey(columnIndexToSort++, SortOrder.ASCENDING));
        }
         
        sorter.setSortKeys(sortKeys);
        sorter.sort();																																//end sort
        
//        createAndShowGUI();																															//display GUI
    }

    // Method for reading CSV file
    public class CSVFile {
        private final ArrayList<String[]> Rs = new ArrayList<String[]>();
        private String[] OneRow;

        public ArrayList<String[]> ReadCSVfile(File DataFile) {
            try {
                BufferedReader brd;
                brd = new BufferedReader(new FileReader(DataFile));
                brd.readLine();
                while (brd.ready()) {
                    String st;
                    st = brd.readLine();
//                    OneRow = st.split(",|\\s|;");
                    OneRow = st.split(",|;");
                    Rs.add(OneRow);
                    System.out.println(Arrays.toString(OneRow));
                }
            } 
            catch (Exception e) {
                String errmsg = e.getMessage();
                System.out.println("File not found:" + errmsg);
            } 
            return Rs;
        }
    }

    public void createAndShowGUI() {

        JFrame frame;
        frame = new JFrame("T1Data");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        Analysis newContentPane;
        newContentPane = new Analysis();
        frame.setContentPane(newContentPane);

        frame.pack();
        frame.setSize(1500, 1000);																													//change window size
        frame.setVisible(true);
    }

    class MyModel extends AbstractTableModel {
        private final String[] columnNames = { "Username", "Tweet", " Retweet_Count", "Favourite_Count", "Date" };						//for twitter
        //private final String[] columnNames = { "Article_Category", "Article_Title", " Date_Published" };									//for CNA
    	private ArrayList<String[]> Data = new ArrayList<String[]>();																		//change column name(one line above)

        public void AddCSVData(ArrayList<String[]> DataIn) {
            this.Data = DataIn;
            this.fireTableDataChanged();
        }

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

    public void analyse(){
        ArrayList<String[]> Rs2 = new ArrayList<>();
        MyModel NewModel;
        NewModel = new MyModel();
        File DataFile;
        DataFile = new File(fn);

        try {

            FileReader filereader = new FileReader(fn); 

            // create csvReader object and skip first Line 
            CSVReader csvReader = new CSVReaderBuilder(filereader).withSkipLines(1).build(); 
            List<String[]> allData = csvReader.readAll();
            
            String regex = "^(?=.*\\b"+sc1+"\\b)(?=.*\\b"+sc2+"\\b).*$";
            Pattern pattern = Pattern.compile(regex,Pattern.CASE_INSENSITIVE);
            
            for (String[] row : allData) { 
            	if (row == null){
                // Arrays.sort(row[1]);
	                
                }
            	else{
            //		if(row[1].toLowerCase().contains(sc1.toLowerCase()) && row[1].toLowerCase().contains(sc2.toLowerCase())){		//sc1 = "wuhan", sc2 = "singapore"
            		Matcher matcher = pattern.matcher(row[1]);
            		if(matcher.matches()){
            			Rs2.add(row);
	                	StanfordCoreNlpDemo.setLine(row[1]);
            		}
//	                    System.out.println(row);
	                	

            //		}
        		}
            }
            
            table.setModel(NewModel);
            NewModel.AddCSVData(Rs2);
            StanfordCoreNlpDemo jihyo = new StanfordCoreNlpDemo();
        	PieChart example = new PieChart("Pie Chart Example | BORAJI.COM");
            example.setSize(800, 400);
            example.setLocationRelativeTo(null);
            example.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
            example.setVisible(true);
                

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (Exception e){
            e.printStackTrace();
        }
	}
    
    public static void main(String[] args) {
    	Analysis.setFn("twitter - Copy 5.csv");
        Analysis aaa = new Analysis();
    	
    	aaa.createAndShowGUI();
    	
    	StanfordCoreNlpDemo jihyo = new StanfordCoreNlpDemo();
    	PieChart example = new PieChart("Pie Chart Example | BORAJI.COM");
        example.setSize(800, 400);
        example.setLocationRelativeTo(null);
        example.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        example.setVisible(true);
    	
    }
    
    
}
