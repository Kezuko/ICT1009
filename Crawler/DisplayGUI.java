package grp32;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import javax.swing.filechooser.FileNameExtensionFilter;
import javax.swing.table.AbstractTableModel;
import javax.swing.table.TableModel;
import javax.swing.table.TableRowSorter;

import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.labels.PieSectionLabelGenerator;
import org.jfree.chart.labels.StandardPieSectionLabelGenerator;
import org.jfree.chart.plot.PiePlot;
import org.jfree.data.general.DefaultPieDataset;
import org.jfree.data.general.PieDataset;

import com.opencsv.CSVReader;
import com.opencsv.CSVReaderBuilder;

import grp32.Analysis.MyModel;

import java.awt.GridLayout;
import java.awt.Component;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.event.WindowListener;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.Panel;
import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class DisplayGUI{
	static private final String newline = "\n";
	private JTabbedPane tabbedPane;
	private JTextField textField_1;
	private JTextField textField_2;
	private JTable table;
	private JScrollPane scrollPane;
	
	private Display dd;
//	private Analysis an;
	private JTextField textField;
	private JTextField textField_3;
	private static JTable piechartTable;
	private static Panel panel_3;
	
	private String filenameCSV;
	private String searchKeyword1;
	private String searchKeyword2;
	private ChartPanel chartPanel;
	private ChartPanel chartPanel2;
	
	
	  private static double posSent;
	  private static double negSent;
	  private static double neuSent;
	  private static double vNegSent;
	  private static double vPosSent;
	  
	  public static void setPos(double posSent){DisplayGUI.posSent = posSent;}
	  public static void setNeg(double negSent){DisplayGUI.negSent = negSent;}
	  public static void setNeu(double neuSent){DisplayGUI.neuSent = neuSent;}
	  public static void setvNeg(double vNegSent){DisplayGUI.vNegSent = vNegSent;}
	  public static void setvPos(double vPosSent){DisplayGUI.vPosSent = vPosSent;}
	
	
    public DisplayGUI() {
//    	super(true);     		    // true = please double buffer

		this.tabbedPane = new JTabbedPane();
		this.tabbedPane.setBounds(0, 0, 1500, 750);
		
		String crawlFromHereLabel = "Crawl from here :";
		JLabel l = new JLabel(crawlFromHereLabel);
		l.setBounds(50, 30,90,20);
		
		String crawlFromHereList[]={"Twitter","CNN"};        
	    JComboBox cb=new JComboBox(crawlFromHereList);
	    cb.setBounds(50, 50,90,20);
	    
	    JButton b=new JButton("Click here to crawl");
	    b.setBounds(50,100,95,30);
	    
	    JPanel panel = new JPanel();
		panel.setLayout(new FlowLayout());
		panel.add(l);
		panel.add(cb);
		panel.add(b);
		panel.setSize(750,750);
	    
		Component panel1 = panel;
		panel1.setSize(750,750);
//        setLayout(new GridLayout(0, 1, 0, 0));
//        add(this.tabbedPane);
        
        final JFileChooser fc = new JFileChooser();												//Create a file chooser
        fc.setFileSelectionMode(JFileChooser.FILES_ONLY);
        File workingDirectory = new File(System.getProperty("user.dir"));
        fc.setCurrentDirectory(workingDirectory);
        fc.setFileFilter(new FileNameExtensionFilter("csv file","csv"));
        
        Panel panel_1 = new Panel();
        panel_1.setBounds(0, 0, 1500, 750);
        this.tabbedPane.addTab("Crawl", null, panel_1, null);
        panel_1.setLayout(null);
        
        JTextArea log = new JTextArea();
        log.setEditable(false);
        log.setBounds(10, 245, 450, 226);
        panel_1.add(log);
        
        textField = new JTextField();
        textField.setBounds(37, 31, 99, 20);
        panel_1.add(textField);
        textField.setColumns(10);
        
        textField_3 = new JTextField();
        textField_3.setBounds(37, 59, 99, 20);
        panel_1.add(textField_3);
        textField_3.setColumns(10);
        
        JComboBox comboBox = new JComboBox();
        comboBox.addActionListener(new ActionListener() {
        	public void actionPerformed(ActionEvent e) {
        		String s = (String) comboBox.getSelectedItem();//get the selected item
        		
                switch (s) {//check for a match
                    case "Twitter":
                    	Tweet crawlTwitter = new CrawlWithTJ4(textField.getText());
                    	crawlTwitter.searchTweets();
//                    	crawlTwitter.writeToFile("twitter - Copy 5.csv");
                    	int returnVal = fc.showSaveDialog(panel1);
                        if (returnVal == JFileChooser.APPROVE_OPTION) {
                            File file = fc.getSelectedFile();
                            String filename = fc.getSelectedFile().toString();
                            if (!filename .endsWith(".csv"))
                                 filename += ".csv";
                            file=new File(filename);
                            //This is where a real application would save the file.
                            log.append("Saving: " + file.getName() + "." + newline);                            
                            crawlTwitter.writeToFile(file.getName());
                            Analysis.setFn1(file.getName());	
                            Display.setFn1(file.getName());
                            

                        } else {
                            log.append("Save command cancelled by user." + newline);
                        }
                        log.setCaretPosition(log.getDocument().getLength());
                        break;
                    case "CNA":
                    	WebCrawlerCNA bwc = new WebCrawlerCNA("https://www.channelnewsasia.com/", textField.getText(), textField_3.getText());
                		bwc.getPageLinks("https://www.channelnewsasia.com/",0);
                		int returnVal2 = fc.showSaveDialog(panel1);
                        if (returnVal2 == JFileChooser.APPROVE_OPTION) {
                            File file = fc.getSelectedFile();
                            String filename = fc.getSelectedFile().toString();
                            if (!filename .endsWith(".csv"))
                                 filename += ".csv";
                            file=new File(filename);
                            //This is where a real application would save the file.
                            log.append("Saving: " + file.getName() + "." + newline);
                            bwc.writeToFile(file.getName());
                            Analysis.setFn2(file.getName());	
                            Display.setFn2(file.getName());

                        } else {
                            log.append("Save command cancelled by user." + newline);
                        }
                        log.setCaretPosition(log.getDocument().getLength());
//                		bwc.writeToFile("cna - Copy.csv");
                        break;
                    case "Guardian":
                    	WebCrawlGuardian wcg = new WebCrawlGuardian("https://www.theguardian.com/", textField.getText(), textField_3.getText());
                    	wcg.getPageLinks("https://www.theguardian.com/",0);
                		int returnVal3 = fc.showSaveDialog(panel1);
                        if (returnVal3 == JFileChooser.APPROVE_OPTION) {
                            File file = fc.getSelectedFile();
                            String filename = fc.getSelectedFile().toString();
                            if (!filename .endsWith(".csv"))
                                 filename += ".csv";
                            file=new File(filename);
                            //This is where a real application would save the file.
                            log.append("Saving: " + file.getName() + "." + newline);
                            wcg.writeToFile(file.getName());
                            Analysis.setFn2(file.getName());	
                            Display.setFn2(file.getName());

                        } else {
                            log.append("Save command cancelled by user." + newline);
                        }
                        log.setCaretPosition(log.getDocument().getLength());
                        break;
                }
        	}
        });
        comboBox.setBounds(10, 107, 89, 20);
        comboBox.setModel(new DefaultComboBoxModel(new String[] {"Twitter", "CNA", "Guardian"}));
        panel_1.add(comboBox);
        
        
        
        JLabel lblEnterTheKeyword = new JLabel("Enter the keyword to search with");
        lblEnterTheKeyword.setBounds(10, 9, 204, 14);
        panel_1.add(lblEnterTheKeyword);
        
        
        
        JLabel lblNewLabel = new JLabel("(1)");
        lblNewLabel.setBounds(10, 34, 32, 14);
        panel_1.add(lblNewLabel);
        
        JLabel lblNewLabel_2 = new JLabel("(2)");
        lblNewLabel_2.setBounds(10, 62, 39, 14);
        panel_1.add(lblNewLabel_2);
        
        JComboBox comboBox_3 = new JComboBox();
        comboBox_3.addActionListener(new ActionListener() {
        	public void actionPerformed(ActionEvent arg0) {
        		switch(comboBox_3.getSelectedIndex()){
	        		case 0:
	        			WebCrawlerCNA.setMaxPage(100);
	        			WebCrawlGuardian.setMaxPage(100);
	        			break;
	        		case 1:
	        			WebCrawlerCNA.setMaxPage(200);
	        			WebCrawlGuardian.setMaxPage(200);
	        			break;
	        		case 2:
	        			WebCrawlerCNA.setMaxPage(300);
	        			WebCrawlGuardian.setMaxPage(300);
	        			break;
	        		case 3:
	        			WebCrawlerCNA.setMaxPage(400);
	        			WebCrawlGuardian.setMaxPage(400);
	        			break;
	        		case 4:
	        			WebCrawlerCNA.setMaxPage(500);
	        			WebCrawlGuardian.setMaxPage(500);
	        			break;
	        		case 5:
	        			WebCrawlerCNA.setMaxPage(600);
	        			WebCrawlGuardian.setMaxPage(600);
	        			break;
	        		case 6:
	        			WebCrawlerCNA.setMaxPage(700);
	        			WebCrawlGuardian.setMaxPage(700);
	        			break;
	        		case 7:
	        			WebCrawlerCNA.setMaxPage(800);
	        			WebCrawlGuardian.setMaxPage(800);
	        			break;
	        		case 8:
	        			WebCrawlerCNA.setMaxPage(900);
	        			WebCrawlGuardian.setMaxPage(900);
	        			break;
	        		case 9:
	        			WebCrawlerCNA.setMaxPage(1000);
	        			WebCrawlGuardian.setMaxPage(1000);
	        			System.out.println("1000");
	        			break;
        		}
        	}
        });
        comboBox_3.setModel(new DefaultComboBoxModel(new String[] {"100", "200", "300", "400", "500", "600", "700", "800", "900", "1000"}));
        comboBox_3.setBounds(10, 163, 89, 20);
        panel_1.add(comboBox_3);
        
        JLabel lblNewLabel_3 = new JLabel("Search from which new sources");
        lblNewLabel_3.setBounds(10, 87, 204, 14);
        panel_1.add(lblNewLabel_3);
        
        JLabel lblNumberOfPages = new JLabel("Number of pages to query(for CNA)");
        lblNumberOfPages.setBounds(10, 138, 225, 14);
        panel_1.add(lblNumberOfPages);
        
        
        Panel panel_2 = new Panel();
        panel_2.setBounds(0, 0, 1500, 750);
        this.tabbedPane.addTab("Display", null, panel_2, null);
        panel_2.setLayout(null);
        
        JLabel lblShowResultIn = new JLabel("2. Show result in a ");
        lblShowResultIn.setBounds(10, 45, 163, 14);
        panel_2.add(lblShowResultIn);
        
        JButton btnFiletoJTable = new JButton("New window");
        btnFiletoJTable.setBounds(208, 41, 122, 23);
        btnFiletoJTable.addActionListener(new ActionListener() {
        	public void actionPerformed(ActionEvent arg0) {
        		searchKeyword1 = "";
        		searchKeyword2 = "";
        		displayJTable(panel_2, 2);
//        		dd = new Display();
//        		dd.createAndShowGUI();
        	}
        });
        
        panel_2.add(btnFiletoJTable);
        
        JButton btnNewButton_2 = new JButton("Browse");
        btnNewButton_2.setBounds(208, 5, 93, 23);
        btnNewButton_2.addActionListener(new ActionListener() {
        	public void actionPerformed(ActionEvent e) {
        		int returnVal = fc.showOpenDialog(panel1);
       		 
                if (returnVal == JFileChooser.APPROVE_OPTION) {
                    File file = fc.getSelectedFile();
                    //This is where a real application would open the file.
                    Display.setFn1(file.getName());
                    filenameCSV = file.getName();
                }
        	}
        });
        panel_2.add(btnNewButton_2);
        
        JButton btnNewButton_3 = new JButton("Browse");
        btnNewButton_3.setBounds(208, 75, 93, 23);
        btnNewButton_3.addActionListener(new ActionListener() {
        	public void actionPerformed(ActionEvent e) {
        		int returnVal = fc.showOpenDialog(panel1);
       		 
                if (returnVal == JFileChooser.APPROVE_OPTION) {
                    File file = fc.getSelectedFile();
                    //This is where a real application would open the file.
                    Display.setFn2(file.getName());
                    filenameCSV = file.getName();
                }
        	}
        });
        panel_2.add(btnNewButton_3);
        
        JLabel lblNewLabel_4 = new JLabel("1. ");
        lblNewLabel_4.setBounds(10, 9, 22, 14);
        panel_2.add(lblNewLabel_4);
        
        JLabel label = new JLabel("3. ");
        label.setBounds(10, 79, 22, 14);
        panel_2.add(label);
        
        JLabel lblShowResult = new JLabel("4. Show result in a ");
        lblShowResult.setBounds(10, 109, 177, 14);
        panel_2.add(lblShowResult);
        
        JButton button = new JButton("New window");
        button.setBounds(208, 105, 122, 23);
        panel_2.add(button);
        
        
        panel_3 = new Panel();
        panel_3.setBounds(0, 0, 2000, 1000);
        this.tabbedPane.addTab("Search", null, panel_3, null);
        panel_3.setLayout(null);
        
        textField_1 = new JTextField();
        textField_1.setBounds(175, 59, 86, 20);
        panel_3.add(textField_1);
        textField_1.setColumns(10);
        
        textField_2 = new JTextField();
        textField_2.setBounds(175, 90, 86, 20);
        panel_3.add(textField_2);
        textField_2.setColumns(10);
        
        JLabel lblShowResultIn_1 = new JLabel("5. Show result in a");
        lblShowResultIn_1.setBounds(10, 178, 158, 14);
        panel_3.add(lblShowResultIn_1);
        
        JButton btnOpenCSV = new JButton("New window");
        btnOpenCSV.setBounds(178, 174, 124, 23);
        btnOpenCSV.addActionListener(new ActionListener() {
        	public void actionPerformed(ActionEvent e) {																	//setter for filename, search criteria
        		Analysis.setSc1(textField_1.getText().trim());
        		Analysis.setSc2(textField_2.getText().trim());
//        		Analysis an = new Analysis();
//            	an.analyse();
//            	an.createAndShowGUI();
            	searchKeyword1 = textField_1.getText().trim();
            	searchKeyword2 = textField_2.getText().trim();
            	analyse();
        	}
        });
        panel_3.add(btnOpenCSV);
        
        JButton btnNewButton_4 = new JButton("Browse");
        btnNewButton_4.setBounds(173, 5, 88, 23);
        btnNewButton_4.addActionListener(new ActionListener() {
        	public void actionPerformed(ActionEvent arg0) {
        		int returnVal = fc.showOpenDialog(panel1);
       		 
                if (returnVal == JFileChooser.APPROVE_OPTION) {
                    File file = fc.getSelectedFile();
                    //This is where a real application would open the file.
                    Analysis.setFn1(file.getName());
                    filenameCSV = file.getName();
                }
        		
        	}
        });
        panel_3.add(btnNewButton_4);
        
        JButton btnNewButton_5 = new JButton("Browse");
        btnNewButton_5.setBounds(175, 120, 86, 23);
        btnNewButton_5.addActionListener(new ActionListener() {
        	public void actionPerformed(ActionEvent e) {
        		int returnVal = fc.showOpenDialog(panel1);
          		 
                if (returnVal == JFileChooser.APPROVE_OPTION) {
                    File file = fc.getSelectedFile();
                    //This is where a real application would open the file.
                    Analysis.setFn2(file.getName());
                    filenameCSV = file.getName();
                    secondAnalysis();
                }
        	}
        });
        panel_3.add(btnNewButton_5);
        
        JLabel label_1 = new JLabel("1. ");
        label_1.setBounds(10, 9, 13, 14);
        panel_3.add(label_1);
        
        JLabel lblEnterThe = new JLabel("2. Enter the keyword(s) you to search");
        lblEnterThe.setBounds(10, 39, 292, 20);
        panel_3.add(lblEnterThe);
        
        JLabel lblFirstKeyword = new JLabel("First keyword:");
        lblFirstKeyword.setBounds(10, 62, 143, 14);
        panel_3.add(lblFirstKeyword);
        
        JLabel lblSecondKeyword = new JLabel("Second keyword:");
        lblSecondKeyword.setBounds(10, 93, 143, 14);
        panel_3.add(lblSecondKeyword);
        
        JLabel label_2 = new JLabel("3. ");
        label_2.setBounds(10, 124, 13, 14);
        panel_3.add(label_2);
        
        JLabel lblEnterThe_1 = new JLabel("4. Change the keywords in step 2");
        lblEnterThe_1.setBounds(10, 151, 292, 20);
        panel_3.add(lblEnterThe_1);
        
        
        
//        this.ButtonOpen = new JPanel(new FlowLayout(FlowLayout.CENTER));
//        this.ButtonOpen.add(ButtonOpen, BorderLayout.SOUTH);
        
        JButton btnNewButton = new JButton("New button");
        btnNewButton.addActionListener(new ActionListener() {
        	public void actionPerformed(ActionEvent arg0) {
        		StanfordCoreNlpDemo nlp = new StanfordCoreNlpDemo();
            	PieChart example = new PieChart(filenameCSV);
                example.setSize(800, 400);
                example.setBounds(1501, 0, 1500, 750);
                example.setLocationRelativeTo(null);
                example.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
                example.setVisible(true);
        	}
        });
        panel_3.add(btnNewButton);
        

//        add(scrollPane, BorderLayout.CENTER);

//        this.ButtonOpen.setBorder(new EmptyBorder(5, 5, 5, 5));
        
        
        //analyse();
    }
    
    private PieDataset createDataset() {

        DefaultPieDataset dataset=new DefaultPieDataset();
        dataset.setValue("Positive sentiment", posSent);
        dataset.setValue("Negative sentiment", negSent);
        dataset.setValue("Neutral sentiment", neuSent);
        dataset.setValue("Very Negative sentiment", vNegSent);
        dataset.setValue("Very Positive sentiment", vPosSent);
        return dataset;
      }
    
    class DisplayModel extends AbstractTableModel {
        private String[] columnNames = { "Username", "Tweet", " Retweet_Count", "Favourite_Count", "Date" };						//for twitter
        //private final String[] columnNames = { "Article_Category", "Article_Title", " Date_Published" };									//for CNA
    	private ArrayList<String[]> Data = new ArrayList<String[]>();//change column name(one line above)

        public void AddCSVData(ArrayList<String[]> DataIn) {
            this.Data = DataIn;
            this.fireTableDataChanged();
        }

        public void refresh(){
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
    
    class SentimentModel extends AbstractTableModel {
        private String columnName = "";						//for twitter
        //private final String[] columnNames = { "Article_Category", "Article_Title", " Date_Published" };									//for CNA	
    	private ArrayList<String> sentimentAnalysis = new ArrayList<String>();//change column name(one line above)

        public void AddSentimentAnalysis(ArrayList<String> sentimentAnalysis) {
            this.sentimentAnalysis = sentimentAnalysis;
            this.fireTableDataChanged();
        }
        
        public void refresh(){
        	this.fireTableDataChanged();
        }
        
        public void setColumnNames(String colsName){columnName = colsName;}

        @Override
        public int getColumnCount() {
            return 1;
        }

        @Override
        public int getRowCount() {
            return sentimentAnalysis.size();
        }

        @Override
        public String getColumnName(int col) {
            return columnName;
        }

        @Override
        public Object getValueAt(int row, int col) {
            return sentimentAnalysis.get(row);
        }
    }
    
    public void displayJTable(Panel jpanelNumber, int jpanelNo){
    	DisplayModel NewModel;
        NewModel = new DisplayModel();
        SentimentModel NewModel2;
        NewModel2 = new SentimentModel();
//        this.table.setModel(NewModel);

        
        ArrayList<String[]> Rs2 = new ArrayList<>();
        ArrayList<String> Rs3 = new ArrayList<>();
//        MyModel NewModel;
//        NewModel = new MyModel();
//        File DataFile;
//        DataFile = new File(filenameCSV);

        try {

            FileReader filereader = new FileReader(filenameCSV); 

            // create csvReader object and skip first Line 
            CSVReader csvReader = new CSVReaderBuilder(filereader).build(); 
            String[] temp = csvReader.readNext();
            if(jpanelNo==2){NewModel.setColumnNames(temp);}
            else{
            	NewModel2.setColumnNames(temp[1]);
            	StanfordCoreNlpDemo.setSentimentTableHeader(temp[1]);}
            List<String[]> allData = csvReader.readAll();
            
            String regex = "^(?=.*\\b"+searchKeyword1+"\\b)(?=.*\\b"+searchKeyword2+"\\b).*$";
            Pattern pattern = Pattern.compile(regex,Pattern.CASE_INSENSITIVE);
            
            for (String[] row : allData) { 
            	//if (row == null){
                // Arrays.sort(row[1]);
	                
               // }
            	//else{
            //		if(row[1].toLowerCase().contains(sc1.toLowerCase()) && row[1].toLowerCase().contains(sc2.toLowerCase())){		//sc1 = "wuhan", sc2 = "singapore"
            		Matcher matcher = pattern.matcher(row[1]);
            		if(matcher.matches()){
            			if (jpanelNo == 3){Rs3.add(row[1]); }
            			else{Rs2.add(row); }
            			StanfordCoreNlpDemo.setLine(row[1]);
	                	
            		}
//	                    System.out.println(row);
	                	

            //		}
        		//}
            }
            if(jpanelNo == 2){
	            System.out.println("Rs2 = " + Rs2);
	            
	            
	            NewModel.AddCSVData(Rs2);
	            NewModel.refresh();
	            
	            this.table = new JTable(NewModel);
	            
	            this.table.setModel(NewModel);
            }
            else{
        		System.out.println("Rs3 = " + Rs3);
	            
	            
	            NewModel2.AddSentimentAnalysis(Rs3);
	            NewModel2.refresh();
	            
	            this.table = new JTable(NewModel2);
	            
	            this.table.setModel(NewModel2);
            }
            this.table.setBounds(0, 0, 1500, 750);
            this.table.setPreferredScrollableViewportSize(new Dimension(700, 70));
            this.table.setFillsViewportHeight(true);
            
            
            this.scrollPane = new JScrollPane(this.table);
            this.scrollPane.setBounds(500, 0, 1420, 900);
            jpanelNumber.add(this.scrollPane);
            jpanelNumber.revalidate();
            jpanelNumber.repaint();
            
            TableRowSorter<TableModel> sorter;
            sorter = new TableRowSorter<>(this.table.getModel());																	//start sort
            this.table.setRowSorter(sorter);
            List<RowSorter.SortKey> sortKeys;
            sortKeys = new ArrayList<>();
             
            int columnIndexToSort = 1;
            if(jpanelNo==2){
	            while (columnIndexToSort <NewModel.getColumnCount()){
	            	sortKeys.add(new RowSorter.SortKey(columnIndexToSort++, SortOrder.ASCENDING));
	            }
            }
            else{
            	while (columnIndexToSort <NewModel2.getColumnCount()){
	            	sortKeys.add(new RowSorter.SortKey(columnIndexToSort++, SortOrder.ASCENDING));
	            }
            }
             
            sorter.setSortKeys(sortKeys);
            sorter.sort();
            
//            this.scrollPane = new JScrollPane(this.table);
//            this.panel_3.add(this.scrollPane);
            
            if(jpanelNo==2)
            	NewModel.refresh();
            else
            	NewModel2.refresh();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (Exception e){
            e.printStackTrace();
        }
    }
    
    public void secondAnalysis(){
//    	DisplayModel NewModel;
//        NewModel = new DisplayModel();

        ArrayList<String[]> Rs2 = new ArrayList<>();

        try {

            FileReader filereader = new FileReader(filenameCSV); 

            // create csvReader object and skip first Line 
            CSVReader csvReader = new CSVReaderBuilder(filereader).build(); 
            String[] temp = csvReader.readNext();
//            NewModel.setColumnNames(temp);
            List<String[]> allData = csvReader.readAll();
            
            String regex = "^(?=.*\\b"+searchKeyword1+"\\b)(?=.*\\b"+searchKeyword2+"\\b).*$";
            Pattern pattern = Pattern.compile(regex,Pattern.CASE_INSENSITIVE);
            
            for (String[] row : allData) { 
            	//if (row == null){
                // Arrays.sort(row[1]);
	                
               // }
            	//else{
            //		if(row[1].toLowerCase().contains(sc1.toLowerCase()) && row[1].toLowerCase().contains(sc2.toLowerCase())){		//sc1 = "wuhan", sc2 = "singapore"
            		Matcher matcher = pattern.matcher(row[1]);
            		if(matcher.matches()){
//            			Rs2.add(row); 
            			StanfordCoreNlpDemo.setLine(row[1]);
	                	
            		}
//	                    System.out.println(row);
	                	

            //		}
        		//}
            }

//            System.out.println("Rs2 = " + Rs2);
//            
//            
//            NewModel.AddCSVData(Rs2);
//            NewModel.refresh();
            
//            this.table = new JTable(NewModel);
//            
//            this.table.setModel(NewModel);
//           
//            this.table.setBounds(0, 0, 1500, 750);
//            this.table.setPreferredScrollableViewportSize(new Dimension(700, 70));
//            this.table.setFillsViewportHeight(true);
            
            
//            this.scrollPane = new JScrollPane(this.table);
//            this.scrollPane.setBounds(500, 0, 1420, 900);
//            panel_3.add(this.scrollPane);
//            panel_3.revalidate();
//            panel_3.repaint();
//            
//            TableRowSorter<TableModel> sorter;
//            sorter = new TableRowSorter<>(this.table.getModel());																	//start sort
//            this.table.setRowSorter(sorter);
//            List<RowSorter.SortKey> sortKeys;
//            sortKeys = new ArrayList<>();
//             
//            int columnIndexToSort = 1;
//
//            while (columnIndexToSort <NewModel.getColumnCount()){
//            	sortKeys.add(new RowSorter.SortKey(columnIndexToSort++, SortOrder.ASCENDING));
//            }
//  
//            sorter.setSortKeys(sortKeys);
//            sorter.sort();
            
//            this.scrollPane = new JScrollPane(this.table);
//            this.panel_3.add(this.scrollPane);
            

//        	NewModel.refresh();

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (Exception e){
            e.printStackTrace();
        }
    }
    
    public void compare(){
    	secondAnalysis();
    	StanfordCoreNlpDemo nlp = new StanfordCoreNlpDemo();
  
        PieDataset dataset = createDataset();

        // Create chart
        JFreeChart chart = ChartFactory.createPieChart(
            filenameCSV+ " Sentiment Analysis",
            dataset,
            true, 
            true,
            false);

        //Format Label
        PieSectionLabelGenerator labelGenerator = new StandardPieSectionLabelGenerator(
            "{0} : ({2})", new DecimalFormat("0"), new DecimalFormat("0%"));
        ((PiePlot) chart.getPlot()).setLabelGenerator(labelGenerator);
        
        // Create Panel
        chartPanel2 = new ChartPanel(chart);
        chartPanel2.setSize(800, 400);
        chartPanel2.setBounds(400,400, 400, 400);
        chartPanel2.setVisible(true);
//        this.scrollPane.remove(this.table);
        panel_3.remove(this.scrollPane);
        panel_3.add(chartPanel2);
//        panel_3.repaint();
//        panel_3.revalidate();
        this.scrollPane.removeAll();
        this.scrollPane.setViewportView(chartPanel2);
        this.scrollPane.add(chartPanel2);
        this.scrollPane.revalidate();
        panel_3.revalidate();
        panel_3.repaint();
    }
    
    public void analyse(){
    	
//    	MyModel NewModel;
//        NewModel = new MyModel();
////        this.table.setModel(NewModel);
//
//        
//        ArrayList<String[]> Rs2 = new ArrayList<>();
////        MyModel NewModel;
////        NewModel = new MyModel();
////        File DataFile;
////        DataFile = new File(filenameCSV);
//
//        try {
//
//            FileReader filereader = new FileReader(filenameCSV); 
//
//            // create csvReader object and skip first Line 
//            CSVReader csvReader = new CSVReaderBuilder(filereader).build(); 
//            String[] temp = csvReader.readNext();
//            NewModel.setColumnNames(temp);
//            List<String[]> allData = csvReader.readAll();
//            
//            String regex = "^(?=.*\\b"+searchKeyword1+"\\b)(?=.*\\b"+searchKeyword2+"\\b).*$";
//            Pattern pattern = Pattern.compile(regex,Pattern.CASE_INSENSITIVE);
//            
//            for (String[] row : allData) { 
//            	//if (row == null){
//                // Arrays.sort(row[1]);
//	                
//               // }
//            	//else{
//            //		if(row[1].toLowerCase().contains(sc1.toLowerCase()) && row[1].toLowerCase().contains(sc2.toLowerCase())){		//sc1 = "wuhan", sc2 = "singapore"
//            		Matcher matcher = pattern.matcher(row[1]);
//            		if(matcher.matches()){
//            			Rs2.add(row);
//	                	StanfordCoreNlpDemo.setLine(row[1]);
//            		}
////	                    System.out.println(row);
//	                	
//
//            //		}
//        		//}
//            }
//            System.out.println("Rs2 = " + Rs2);
//            
//            
//            NewModel.AddCSVData(Rs2);
//            NewModel.refresh();
//            
//            this.table = new JTable(NewModel);
//            this.table.setBounds(0, 0, 1500, 750);
//            this.table.setPreferredScrollableViewportSize(new Dimension(700, 70));
//            this.table.setFillsViewportHeight(true);
//            this.table.setModel(NewModel);
//            
//            this.scrollPane = new JScrollPane(this.table);
//            this.scrollPane.setBounds(500, 0, 1420, 900);
//            panel_3.add(this.scrollPane);
//            panel_3.revalidate();
//            panel_3.repaint();
//            
//            TableRowSorter<TableModel> sorter;
//            sorter = new TableRowSorter<>(this.table.getModel());																	//start sort
//            this.table.setRowSorter(sorter);
//            List<RowSorter.SortKey> sortKeys;
//            sortKeys = new ArrayList<>();
//             
//            int columnIndexToSort = 1;
//            while (columnIndexToSort <NewModel.getColumnCount()){
//            	sortKeys.add(new RowSorter.SortKey(columnIndexToSort++, SortOrder.ASCENDING));
//            }
//             
//            sorter.setSortKeys(sortKeys);
//            sorter.sort();
            
//            this.scrollPane = new JScrollPane(this.table);
//            this.panel_3.add(this.scrollPane);
            
    		displayJTable(panel_3, 3);
    	
//            NewModel.refresh();
            
            StanfordCoreNlpDemo nlp = new StanfordCoreNlpDemo();
            
            
            PieDataset dataset = createDataset();

            // Create chart
            JFreeChart chart = ChartFactory.createPieChart(
                filenameCSV+ " Sentiment Analysis",
                dataset,
                true, 
                true,
                false);

            //Format Label
            PieSectionLabelGenerator labelGenerator = new StandardPieSectionLabelGenerator(
                "{0} : ({2})", new DecimalFormat("0"), new DecimalFormat("0%"));
            ((PiePlot) chart.getPlot()).setLabelGenerator(labelGenerator);
            
            // Create Panel
            chartPanel = new ChartPanel(chart);
            chartPanel.setSize(800, 400);
            chartPanel.setBounds(0,400, 400, 400);
            chartPanel.setVisible(true);
            panel_3.add(chartPanel);
            //this.ButtonOpen.add(this.scrollPane, BorderLayout.CENTER);
            
                

//        } catch (FileNotFoundException e) {
//            e.printStackTrace();
//        } catch (IOException e) {
//            e.printStackTrace();
//        } catch (Exception e){
//            e.printStackTrace();
//        }
	}
    
    public void createAndUpdateGUI(){
    	JFrame frame = new JFrame("Group 32");
    	
		WindowListener l = new WindowAdapter() {
		    public void windowClosing(WindowEvent e) {System.exit(0);}
		};
		frame.addWindowListener(l);
	
		frame.getContentPane().setLayout(new GridLayout(0, 1, 0, 0));
		frame.getContentPane().add("Center", this.tabbedPane);
		frame.setSize(1920, 900);																													//change the sizing of window here
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }

    public static void main(String[] args) {
	/*
	 * Create a window.  Use JFrame since this window will include 
	 * lightweight components.
	 */
//		JFrame frame = new JFrame("TabbedPaneDemo");
//	
//		WindowListener l = new WindowAdapter() {
//		    public void windowClosing(WindowEvent e) {System.exit(0);}
//		};
//		frame.addWindowListener(l);
//	
//		frame.getContentPane().add("Center", this.tabbedPane);
//		frame.setSize(1500, 750);																													//change the sizing of window here
//		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
//        frame.setVisible(true);
    	DisplayGUI main = new DisplayGUI();
    	main.createAndUpdateGUI();
    }
}