package grp32;
import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;																																//

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.RowSorter;																														//
import javax.swing.SortOrder;																														//
import javax.swing.border.EmptyBorder;
import javax.swing.table.AbstractTableModel;
import javax.swing.table.TableModel;																												//
import javax.swing.table.TableRowSorter;																											//

public class DisplayCSV extends JPanel {
    private final JTable table;

    private static String fn;
    
    public static void setFn(String fn){
    	DisplayCSV.fn = fn;
    }
    
    public DisplayCSV() {
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
        File DataFile;
        DataFile = new File(fn);																							//change filename
        ArrayList<String[]> Rs2;
        Rs2 = Rd.ReadCSVfile(DataFile);
        NewModel.AddCSVData(Rs2);
//        System.out.println("Rows: " + NewModel.getRowCount());
//        System.out.println("Cols: " + NewModel.getColumnCount());
//        TableRowSorter<TableModel> sorter;
//        sorter = new TableRowSorter<>(table.getModel());																	//start sort
//        table.setRowSorter(sorter);
//        List<RowSorter.SortKey> sortKeys;
//        sortKeys = new ArrayList<>();
//         
//        int columnIndexToSort = 1;
//        while (columnIndexToSort <3){
//        	sortKeys.add(new RowSorter.SortKey(columnIndexToSort++, SortOrder.ASCENDING));
//        }
//         
//        sorter.setSortKeys(sortKeys);
//        sorter.sort();																																//end sort
        
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

        DisplayCSV newContentPane;
        newContentPane = new DisplayCSV();
        frame.setContentPane(newContentPane);

        frame.pack();
        frame.setSize(1500, 1000);																													//change window size
        frame.setVisible(true);
    }

    class MyModel extends AbstractTableModel {
        //private final String[] columnNames = { "Username", "Tweet", " Retweet_Count", "Favourite_Count", "Date"  };						//for twitter
        private final String[] columnNames = { "Article_Category", "Article_Title", " Date_Published" };									//for CNA
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

    public static void main(String[] args) {
        // Schedule a job for the event-dispatching thread:
        // creating and showing this application's GUI.
//        javax.swing.SwingUtilities.invokeLater(new Runnable() {
//            @Override
//            public void run() {
//                createAndShowGUI();
//            }
//        });
    }
}