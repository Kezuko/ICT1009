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
import java.util.Comparator;
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
	private JTable table;//for panel 2
	private JTable inner_table;//for panel 2
	private JTable inner_table2;//for panel 3
	private JTable table_panel4;//for panel 4
	private JTable table2_panel4;//for panel 4
	private Panel inner_panel_3;//for panel 3
	private JScrollPane scrollPane;//for panel 2
	private JScrollPane scrollPane2;//for panel 3
	private JScrollPane inner_scrollPane2;//for panel 3
	private JScrollPane inner_scrollPane;//for panel 3	
	private JScrollPane scrollPane_panel4;//for panel 4
	private JScrollPane scrollPane2_panel4;//for panel 4
	private JScrollPane scrollPane_outer_panel4;
	private JFreeChart chart;//for panel 3
	private JFreeChart chart2;//for panel 3
	private JFreeChart lineChart2;//for panel 4
	private ChartPanel chartPanel4;//for panel 4
	private JFreeChart lineChart;//for panel 4
	private ChartPanel chartPanel3;//for panel 4
	private JFreeChart lineChart3;//for panel 4
	private ChartPanel chartPanel5;//for panel 4
	private JFreeChart lineChart4;//for panel 4
	private ChartPanel chartPanel6;//for panel 4
	
	private JTextField textField;
	private JTextField textField_3;
	private static JTable piechartTable;
	private Panel panel_2;
	private Panel panel_3;
	private Panel panel_4;
	private Panel panel_4_outer;
	
	private String filenameCSV;
	private String filenameCSV2;
	private String searchKeyword1;
	private String searchKeyword2;
	private ChartPanel chartPanel;//for panel 3
	private ChartPanel chartPanel2;//for panel 3
	private List<String[]> firstFileRt;
	private List<String[]> firstFileFav;
	private List<String[]> secondFileRt;
	private List<String[]> secondFileFav;
	
	
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
		this.tabbedPane.setBounds(0, 0, 1920, 2000);
		
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
        log.setBounds(10, 245, 450, 350);
        log.setLineWrap(true);
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
                    	log.append("There are " + Integer.toString(((CrawlWithTJ4)crawlTwitter).getCounter()) + " number of Tweets crawled from keyword " + textField.getText() + newline);
                		log.setCaretPosition(log.getDocument().getLength());
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
                            

                        } else {
                            log.append("Save command cancelled by user." + newline);
                        }
                        log.setCaretPosition(log.getDocument().getLength());
                        break;
                    case "CNA":
                    	WebCrawlerCNA bwc = new WebCrawlerCNA("https://www.channelnewsasia.com/", textField.getText(), textField_3.getText());
                		bwc.getPageLinks("https://www.channelnewsasia.com/",0);
                		log.append("There are " + Integer.toString(bwc.getCounter()) + " number of CNA articles crawled from keywords " + textField.getText() + " " + textField_3.getText() + newline);
                		log.setCaretPosition(log.getDocument().getLength());
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

                        } else {
                            log.append("Save command cancelled by user." + newline);
                        }
                        log.setCaretPosition(log.getDocument().getLength());
//                		bwc.writeToFile("cna - Copy.csv");
                        break;
                    case "Guardian":
                    	WebCrawlGuardian wcg = new WebCrawlGuardian("https://www.theguardian.com/", textField.getText(), textField_3.getText());
                    	wcg.getPageLinks("https://www.theguardian.com/",0);
                    	log.append("There are " + Integer.toString(wcg.getCounter()) + " number of The Guardian articles crawled from keywords " + textField.getText() + " " + textField_3.getText() + newline);
                		log.setCaretPosition(log.getDocument().getLength());
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
	        		case 10:
	        			WebCrawlerCNA.setMaxPage(2000);
	        			WebCrawlGuardian.setMaxPage(2000);
	        			System.out.println("2000");
	        			break;
	        		case 11:
	        			WebCrawlerCNA.setMaxPage(3000);
	        			WebCrawlGuardian.setMaxPage(3000);
	        			System.out.println("3000");
	        			break;		
        		}
        	}
        });
        comboBox_3.setModel(new DefaultComboBoxModel(new String[] {"100", "200", "300", "400", "500", "600", "700", "800", "900", "1000", "2000", "3000"}));
        comboBox_3.setBounds(10, 163, 89, 20);
        panel_1.add(comboBox_3);
        
        JLabel lblNewLabel_3 = new JLabel("Search from which new sources");
        lblNewLabel_3.setBounds(10, 87, 204, 14);
        panel_1.add(lblNewLabel_3);
        
        JLabel lblNumberOfPages = new JLabel("Number of pages to query(for CNA and Guardian ONLY, not for Twitter)");
        lblNumberOfPages.setBounds(10, 138, 439, 14);
        panel_1.add(lblNumberOfPages);
        
        
        panel_2 = new Panel();
        panel_2.setBounds(0, 0, 1500, 750);
        this.tabbedPane.addTab("Display", null, panel_2, null);
        panel_2.setLayout(null);
        
        JButton btnNewButton_2 = new JButton("Browse");
        btnNewButton_2.setBounds(263, 7, 93, 23);
        btnNewButton_2.addActionListener(new ActionListener() {
        	public void actionPerformed(ActionEvent e) {
        		int returnVal = fc.showOpenDialog(panel1);
       		 
                if (returnVal == JFileChooser.APPROVE_OPTION) {
                    File file = fc.getSelectedFile();
                    //This is where a real application would open the file.
                    filenameCSV = file.getName();
                    searchKeyword1 = "";
            		searchKeyword2 = "";
            		displayJTable(2,0);
                }
        	}
        });
        panel_2.add(btnNewButton_2);
        
        JLabel lblNewLabel_4 = new JLabel("1. Browse the csv file you want to view");
        lblNewLabel_4.setBounds(10, 9, 243, 14);
        panel_2.add(lblNewLabel_4);
        
        JButton btnNewButton_3 = new JButton("Clear All");
        btnNewButton_3.addActionListener(new ActionListener() {
        	public void actionPerformed(ActionEvent e) {
        		panel_2.remove(scrollPane);
        		panel_2.revalidate();
        		panel_2.repaint();
        	}
        });
        btnNewButton_3.setBounds(263, 49, 93, 23);
        panel_2.add(btnNewButton_3);
        
        JLabel lblNewLabel_5 = new JLabel("2. Clear All to view more csv file");
        lblNewLabel_5.setBounds(10, 52, 198, 14);
        panel_2.add(lblNewLabel_5);
        
        
        panel_3 = new Panel();
        panel_3.setBounds(0, 0, 1920, 2000);
        this.tabbedPane.addTab("Search", null, panel_3, null);
        panel_3.setLayout(null);
        
        textField_1 = new JTextField();
        textField_1.setBounds(138, 31, 292, 20);
        panel_3.add(textField_1);
        textField_1.setColumns(10);
        
        textField_2 = new JTextField();
        textField_2.setBounds(138, 59, 292, 20);
        panel_3.add(textField_2);
        textField_2.setColumns(10);
        
        JButton btnNewButton_4 = new JButton("Browse");
        btnNewButton_4.setBounds(369, 86, 88, 23);
        btnNewButton_4.addActionListener(new ActionListener() {
        	public void actionPerformed(ActionEvent arg0) {
        		int returnVal = fc.showOpenDialog(panel1);
       		 
                if (returnVal == JFileChooser.APPROVE_OPTION) {
                    File file = fc.getSelectedFile();
                    //This is where a real application would open the file.
                    filenameCSV = file.getName();
                    searchKeyword1 = textField_1.getText().trim();
                	searchKeyword2 = textField_2.getText().trim();
                	displayJTable(3,1);
                	analyse(1);
                }
        		
        	}
        });
        panel_3.add(btnNewButton_4);
        
        JButton btnNewButton_5 = new JButton("Browse");
        btnNewButton_5.setBounds(371, 154, 86, 23);
        btnNewButton_5.addActionListener(new ActionListener() {
        	public void actionPerformed(ActionEvent e) {
        		int returnVal = fc.showOpenDialog(panel1);
          		 
                if (returnVal == JFileChooser.APPROVE_OPTION) {
                    File file = fc.getSelectedFile();
                    //This is where a real application would open the file.
                    filenameCSV = file.getName();
                    searchKeyword1 = textField_1.getText().trim();
                	searchKeyword2 = textField_2.getText().trim();
                    displayJTable(3,2);
                    analyse(2);
                    
                }
        	}
        });
        panel_3.add(btnNewButton_5);
        
        JLabel lblBrowseThe_2 = new JLabel("2. Browse the csv file you want to perform sentiment analysis");
        lblBrowseThe_2.setBounds(10, 90, 322, 14);
        panel_3.add(lblBrowseThe_2);
        
        JLabel lblEnterThe = new JLabel("1. Enter the keyword(s) you to search");
        lblEnterThe.setBounds(10, 6, 292, 20);
        panel_3.add(lblEnterThe);
        
        JLabel lblFirstKeyword = new JLabel("First keyword:");
        lblFirstKeyword.setBounds(10, 34, 143, 14);
        panel_3.add(lblFirstKeyword);
        
        JLabel lblSecondKeyword = new JLabel("Second keyword:");
        lblSecondKeyword.setBounds(10, 62, 143, 14);
        panel_3.add(lblSecondKeyword);
        
        JLabel lblBrowseThe_3 = new JLabel("4. Browse the next file you want to perform sentiment analysis");
        lblBrowseThe_3.setBounds(10, 158, 331, 14);
        panel_3.add(lblBrowseThe_3);
        
        JLabel lblEnterThe_1 = new JLabel("3. Change the keywords in step 1");
        lblEnterThe_1.setBounds(10, 121, 292, 20);
        panel_3.add(lblEnterThe_1);
        
        JButton btnNewButton = new JButton("Refresh Group 32");
        btnNewButton.addActionListener(new ActionListener() {
        	public void actionPerformed(ActionEvent arg0) {
        		inner_panel_3.remove(inner_scrollPane);
        		inner_panel_3.remove(inner_scrollPane2);
        		inner_panel_3.remove(chartPanel);
        		inner_panel_3.remove(chartPanel2);
        		inner_panel_3.revalidate();
        		inner_panel_3.repaint();
        	}
        });
        btnNewButton.setBounds(299, 190, 158, 23);
        panel_3.add(btnNewButton);
        
        this.inner_panel_3 = new Panel();
        this.inner_panel_3.setBounds(550, 0, 1420, 2000);
        this.inner_panel_3.setLayout(null);
        
        this.scrollPane2 = new JScrollPane();
        this.scrollPane2 = new JScrollPane(this.inner_panel_3);
        this.scrollPane2.setBounds(550, 0, 1420, 1080);
        panel_3.add(this.scrollPane2);
        
        JLabel lblNewLabel_1 = new JLabel("6. Clear All to perform more sentiment analysis");
        lblNewLabel_1.setBounds(10, 194, 240, 14);
        panel_3.add(lblNewLabel_1);
        
        panel_4 = new Panel();
        tabbedPane.addTab("Statistics", null, panel_4, null);
        panel_4.setLayout(null);
        
        JLabel lblBrowseThe = new JLabel("1. Browse the first Top 10 Retweet and Favourites you want to compare");
        lblBrowseThe.setBounds(10, 11, 389, 14);
        panel_4.add(lblBrowseThe);
        
        JButton btnNewButton_1 = new JButton("Browse");
        btnNewButton_1.addActionListener(new ActionListener() {
        	public void actionPerformed(ActionEvent e) {
        		int returnVal = fc.showOpenDialog(panel1);
         		 
                if (returnVal == JFileChooser.APPROVE_OPTION) {
                    File file = fc.getSelectedFile();
                    //This is where a real application would open the file.
                    filenameCSV = file.getName();                   
                    displayJTable(4, 1);
                    panel_4_outer.revalidate();
     		      	panel_4_outer.repaint();
                }
       		      
//       		   lineChart2 = ChartFactory.createLineChart(
//      		         filenameCSV,
//      		         "Username","Number of Schools",
//      		         createStatisticDataset(),
//      		         PlotOrientation.VERTICAL,
//      		         true,true,false);
//      		         
//      		      chartPanel4 = new ChartPanel( lineChart2 );
//      		      chartPanel4.setPreferredSize( new java.awt.Dimension( 560 , 367 ) );
//      		      chartPanel4.setBounds(620, 110, 560, 367);
//      		      panel_4.add( chartPanel4 );
        	}
        });
        btnNewButton_1.setBounds(438, 7, 105, 23);
        panel_4.add(btnNewButton_1);
        
        JLabel lblBrowseThe_1 = new JLabel("2. Browse the next Top 10 Retweet and Favourites you want to compare");
        lblBrowseThe_1.setBounds(10, 36, 409, 14);
        panel_4.add(lblBrowseThe_1);
        
        JButton btnNewButton_6 = new JButton("Browse");
        btnNewButton_6.addActionListener(new ActionListener() {
        	public void actionPerformed(ActionEvent e) {
        		int returnVal = fc.showOpenDialog(panel1);
        		 
                if (returnVal == JFileChooser.APPROVE_OPTION) {
                    File file = fc.getSelectedFile();
                    //This is where a real application would open the file.
                    filenameCSV = file.getName();
    				displayJTable(4, 2);
     		      	panel_4_outer.revalidate();
     		      	panel_4_outer.repaint();
                }
//        		
        	}
        });
        btnNewButton_6.setBounds(438, 32, 105, 23);
        panel_4.add(btnNewButton_6);
        
        JLabel lblClearAll = new JLabel("3. Clear all to continue comparing other csv files");
        lblClearAll.setBounds(10, 61, 345, 14);
        panel_4.add(lblClearAll);
        
        JButton btnNewButton_7 = new JButton("Clear All");
        btnNewButton_7.addActionListener(new ActionListener() {
        	public void actionPerformed(ActionEvent e) {
        		panel_4_outer.remove(scrollPane_panel4);
        		panel_4_outer.remove(scrollPane2_panel4);
        		panel_4_outer.revalidate();
        		panel_4_outer.repaint();
        	}
        });
        btnNewButton_7.setBounds(438, 57, 105, 23);
        panel_4.add(btnNewButton_7);
        
        panel_4_outer = new Panel();
        panel_4_outer.setBounds(0, 0, 950, 2000);
        
        
        scrollPane_outer_panel4 = new JScrollPane(this.panel_4_outer);
        panel_4_outer.setLayout(null);
        scrollPane_outer_panel4.setBounds(550, 0, 950, 1080);
        panel_4.add(scrollPane_outer_panel4);
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
    
    public void displayJTable(int jpanelNo, int innerPanelNo){
    	DisplayModel NewModel;
        NewModel = new DisplayModel();
        SentimentModel NewModel2;
        NewModel2 = new SentimentModel();
        SentimentModel NewModel3;
        NewModel3 = new SentimentModel();
        DisplayModel NewModel4;
        NewModel4 = new DisplayModel();
        DisplayModel NewModel5;
        NewModel5 = new DisplayModel();
//        this.table.setModel(NewModel);

        
        ArrayList<String[]> Rs2 = new ArrayList<>();//for panel 2     
        ArrayList<String> Rs3 = new ArrayList<>();//for panel 3, inner panel l
        ArrayList<String> Rs4 = new ArrayList<>();//for panel 3, inner panel 2
        ArrayList<String[]> Rs5 = new ArrayList<>();//for panel 4, inner panel 1
        ArrayList<String[]> Rs6 = new ArrayList<>();//for panel 4, inner panel 2

        try {

            FileReader filereader = new FileReader(filenameCSV); 

            // create csvReader object and skip first Line 
            CSVReader csvReader = new CSVReaderBuilder(filereader).build(); 
            String[] temp = csvReader.readNext();
            if(jpanelNo==2){
            	NewModel.setColumnNames(temp);
        	}
            else if (jpanelNo==3){
            	if(innerPanelNo==1){
            		NewModel2.setColumnNames(temp[1]);
            	}
            	else if(innerPanelNo==2){
            		NewModel3.setColumnNames(temp[1]);
            	}
            		
            	//StanfordCoreNlpDemo.setSentimentTableHeader(temp[1]);
        	}
            else if (jpanelNo==4){
            	String[] statsHeader = new String[4];
            	statsHeader[0] = "Username with Top 10 Retweets Ranking";
            	statsHeader[1] = "Retweets Count";
            	statsHeader[2] = "Username with Top 10 Favourites Ranking";
            	statsHeader[3] = "Favourites Count";
            	if (innerPanelNo == 1)
            		NewModel4.setColumnNames(statsHeader);
            	else if (innerPanelNo == 2)
            		NewModel5.setColumnNames(statsHeader);
            }
            
            List<String[]> allData = csvReader.readAll();
            
            String regex = "^(?=.*\\b"+searchKeyword1+"\\b)(?=.*\\b"+searchKeyword2+"\\b).*$";
            Pattern pattern = Pattern.compile(regex,Pattern.CASE_INSENSITIVE);
            
            if (jpanelNo==3){
	            for (String[] row : allData) { 
	            	Matcher matcher = pattern.matcher(row[1]);
	            		if(matcher.matches()){
	            			if (jpanelNo == 2){
	            				Rs2.add(row); 
	        				}
	            			else{
		            				if(innerPanelNo==1){
		            					Rs3.add(row[1]); 
		            				}
		            				else if (innerPanelNo==2){
		            					Rs4.add(row[1]);
		            				}
	        				}
	            			StanfordCoreNlpDemo.setLine(row[1]);
		                	
	            		}

	            }
            }
            else{
            	if (jpanelNo == 4){

    				Stats statsBodyList = new Stats(filenameCSV);
    				statsBodyList.FindTop10RT(); // find top 10 retweeted tweets
    				statsBodyList.FindTop10Fav(); 
    				List<String[]> rtList = statsBodyList.getTop10RT();
    				List<String[]> favList = statsBodyList.getTop10Fav();
    				for (int i = 0; i < 10; i++){
        				if (innerPanelNo == 1)
        					Rs5.add(new String[] { rtList.get(i)[0], rtList.get(i)[2], favList.get(i)[0], favList.get(i)[3] });
        				else if (innerPanelNo == 2)
        					Rs6.add(new String[] { rtList.get(i)[0], rtList.get(i)[2], favList.get(i)[0], favList.get(i)[3] });
    				}
    				
				}
            	else if (jpanelNo == 2)
            	{
		        	for (String[] row : allData) { 
		    				Rs2.add(row); 	
		            }
            	}
            }
            if(jpanelNo == 2){
	            System.out.println("Rs2 = " + Rs2);
     
	            NewModel.AddCSVData(Rs2);
	            NewModel.refresh();
	            
	            this.table = new JTable(NewModel);
	            
	            this.table.setModel(NewModel);
	            this.table.setBounds(0, 0, 1420, 750);
	            this.table.setPreferredScrollableViewportSize(new Dimension(700, 70));
	            this.table.setFillsViewportHeight(true);
	            
	            this.table.setPreferredScrollableViewportSize(new Dimension(700, 70));
	            this.table.setFillsViewportHeight(true);
	            
//	            this.inner_panel_3 = new Panel();
//	            this.inner_panel_3.setBounds(500, 0, 1420, 2000);
//	            this.inner_panel_3.setLayout(null);
	            
	            this.scrollPane = new JScrollPane(this.table);
	            this.scrollPane.setBounds(550, 0, 1420, 800);
	            
	            this.panel_2.add(this.scrollPane);
//	            this.scrollPane = new JScrollPane(this.inner_panel_3);
//	            this.scrollPane.setBounds(500, 0, 1420, 1080);
//	            panel_2.add(this.scrollPane);
//	            panel_2.revalidate();
//	            panel_2.repaint();
	            
	            TableRowSorter<TableModel> sorter;
	            sorter = new TableRowSorter<>(this.table.getModel());																	//start sort
	            this.table.setRowSorter(sorter);
	            List<RowSorter.SortKey> sortKeys;
	            sortKeys = new ArrayList<>();
	             
	            int columnIndexToSort = 1;

	            while (columnIndexToSort < NewModel.getColumnCount()){
	            	sortKeys.add(new RowSorter.SortKey(columnIndexToSort++, SortOrder.ASCENDING));	            	
	            }
	            sorter.setSortKeys(sortKeys);
	            sorter.sort();
	            

            	NewModel.refresh();

            }
            else if (jpanelNo == 3){
            	if(innerPanelNo==1){
	        		System.out.println("Rs3 = " + Rs3);
	
		            NewModel2.AddSentimentAnalysis(Rs3);
		            NewModel2.refresh();
		              
		            this.inner_table = new JTable(NewModel2);
		            this.inner_table.setBounds(0, 0, 900, 500);
		            
		            this.inner_table.setModel(NewModel2);
		            this.inner_table.setPreferredScrollableViewportSize(new Dimension(700, 70));
		            this.inner_table.setFillsViewportHeight(true);
		            
//		            this.inner_panel_3 = new Panel();
//		            this.inner_panel_3.setBounds(500, 0, 1420, 2000);
//		            this.inner_panel_3.setLayout(null);
		            
		            this.inner_scrollPane = new JScrollPane(this.inner_table);
		            this.inner_scrollPane.setBounds(450, 0, 950, 500);
		            
		            this.inner_panel_3.add(this.inner_scrollPane);
//		            this.scrollPane2 = new JScrollPane(this.inner_panel_3);
//		            this.scrollPane2.setBounds(500, 0, 1420, 1080);
//		            panel_3.add(this.scrollPane2);

		            
		            TableRowSorter<TableModel> sorter;
		            sorter = new TableRowSorter<>(this.inner_table.getModel());																	//start sort
		            this.inner_table.setRowSorter(sorter);
		            List<RowSorter.SortKey> sortKeys;
		            sortKeys = new ArrayList<>();
		             
		            int columnIndexToSort = 1;
		            
	            	while (columnIndexToSort <NewModel2.getColumnCount()){
		            	sortKeys.add(new RowSorter.SortKey(columnIndexToSort++, SortOrder.ASCENDING));
		            }

		            sorter.setSortKeys(sortKeys);
		            sorter.sort();
		            

	            	NewModel2.refresh();
            	}
            	else if(innerPanelNo==2){
            		System.out.println("Rs4 = " + Rs4);
            		
		            NewModel3.AddSentimentAnalysis(Rs4);
		            NewModel3.refresh();
  
		            this.inner_table2 = new JTable(NewModel3);
		            this.inner_table2.setBounds(0, 0, 900, 500);
		            
		            this.inner_table2.setModel(NewModel3);
		            this.inner_table2.setPreferredScrollableViewportSize(new Dimension(700, 70));
		            this.inner_table2.setFillsViewportHeight(true);
		            
//		            this.inner_panel_3 = new Panel();
//		            this.inner_panel_3.setBounds(500, 0, 1420, 2000);
//		            this.inner_panel_3.setLayout(null);
		            
		            this.inner_scrollPane2 = new JScrollPane(this.inner_table2);
		            this.inner_scrollPane2.setBounds(450, 550, 950, 500);
		            
		            this.inner_panel_3.add(this.inner_scrollPane2);
//		            this.scrollPane2 = new JScrollPane(this.inner_panel_3);
//		            this.scrollPane2.setBounds(500, 0, 1420, 1080);
//		            panel_3.add(this.scrollPane2);
//		            panel_3.revalidate();
//		            panel_3.repaint();
		            
		            TableRowSorter<TableModel> sorter;
		            sorter = new TableRowSorter<>(this.inner_table2.getModel());																	//start sort
		            this.inner_table2.setRowSorter(sorter);
		            List<RowSorter.SortKey> sortKeys;
		            sortKeys = new ArrayList<>();
		             
		            int columnIndexToSort = 1;
		            
	            	while (columnIndexToSort < NewModel3.getColumnCount()){
		            	sortKeys.add(new RowSorter.SortKey(columnIndexToSort++, SortOrder.ASCENDING));
		            }

		            sorter.setSortKeys(sortKeys);
		            sorter.sort();

	            	NewModel3.refresh();
            	}
	            
            }
            else if (jpanelNo == 4){
            	if(innerPanelNo == 1){
            		for (int i = 0; i < 10; i++){
            			System.out.println("Rs5 = "+ i + "," + Rs5.get(i)[0] + "," + Rs5.get(i)[1] + "," + Rs5.get(i)[2] + "," + Rs5.get(i)[3]);
            		}
	            	
	            	
		            NewModel4.AddCSVData(Rs5);
//		            NewModel4.refresh();
		              
		            this.table_panel4 = new JTable(NewModel4);
		            this.table_panel4.setBounds(0, 0, 900, 500);
		            
		            this.table_panel4.setModel(NewModel4);
		            this.table_panel4.setPreferredScrollableViewportSize(new Dimension(700, 70));
		            this.table_panel4.setFillsViewportHeight(true);	            
		            
		            this.scrollPane_panel4 = new JScrollPane(this.table_panel4);
		            this.scrollPane_panel4.setBounds(0, 0, 950, 500);
		            
		            this.panel_4_outer.add(this.scrollPane_panel4);
//		            this.panel_4.add(this.scrollPane_panel4);
		            
		            TableRowSorter<TableModel> sorter;
		            sorter = new TableRowSorter<>(this.table_panel4.getModel());																	//start sort
		            this.table_panel4.setRowSorter(sorter);
		            List<RowSorter.SortKey> sortKeys;
		            sortKeys = new ArrayList<>();
		             
		            int columnIndexToSort = 1;
		            
	            	while (columnIndexToSort < NewModel4.getColumnCount()){
		            	sortKeys.add(new RowSorter.SortKey(columnIndexToSort++, SortOrder.ASCENDING));
		            }
	
		            sorter.setSortKeys(sortKeys);
		            sorter.setComparator(1, new Comparator<String>() {
		            	@Override
		            	public int compare(String name1, String name2) {
		            		Integer temp1 = Integer.parseInt(name1);
		            		Integer temp2 = Integer.parseInt(name2);
		            		return temp1.compareTo(temp2);
		            	}
	            	});
		            sorter.setComparator(3, new Comparator<String>() {
		            	@Override
		            	public int compare(String name1, String name2) {
		            		Integer temp1 = Integer.parseInt(name1);
		            		Integer temp2 = Integer.parseInt(name2);
		            		return temp1.compareTo(temp2);
		            	}
	            	});

		            sorter.sort();
		            
	
	            	NewModel4.refresh();
            	}
            	else if (innerPanelNo == 2){
            		System.out.println("Rs6 = " + Rs6);
                	
    	            NewModel5.AddCSVData(Rs6);
    	            NewModel5.refresh();
    	              
    	            this.table2_panel4 = new JTable(NewModel5);
    	            this.table2_panel4.setBounds(0, 0, 900, 500);
    	            
    	            this.table2_panel4.setModel(NewModel5);
    	            this.table2_panel4.setPreferredScrollableViewportSize(new Dimension(700, 70));
    	            this.table2_panel4.setFillsViewportHeight(true);	            
    	            
    	            this.scrollPane2_panel4 = new JScrollPane(this.table2_panel4);
    	            this.scrollPane2_panel4.setBounds(0, 550, 950, 500);
    	            
    	            panel_4_outer.add(scrollPane2_panel4);
//    	            this.panel_4.add(this.scrollPane2_panel4);
    	            
    	            TableRowSorter<TableModel> sorter;
    	            sorter = new TableRowSorter<>(this.table2_panel4.getModel());																	//start sort
    	            this.table2_panel4.setRowSorter(sorter);
    	            List<RowSorter.SortKey> sortKeys;
    	            sortKeys = new ArrayList<>();
    	             
    	            int columnIndexToSort = 1;
    	            
                	while (columnIndexToSort < NewModel5.getColumnCount()){
    	            	sortKeys.add(new RowSorter.SortKey(columnIndexToSort++, SortOrder.ASCENDING));
    	            }

    	            sorter.setSortKeys(sortKeys);
    	            sorter.setComparator(1, new Comparator<String>() {
		            	@Override
		            	public int compare(String name1, String name2) {
		            		Integer temp1 = Integer.parseInt(name1);
		            		Integer temp2 = Integer.parseInt(name2);
		            		return temp1.compareTo(temp2);
		            	}
	            	});
		            sorter.setComparator(3, new Comparator<String>() {
		            	@Override
		            	public int compare(String name1, String name2) {
		            		Integer temp1 = Integer.parseInt(name1);
		            		Integer temp2 = Integer.parseInt(name2);
		            		return temp1.compareTo(temp2);
		            	}
	            	});
    	            sorter.sort();
    	            

                	NewModel5.refresh();
            	}
            }

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (Exception e){
            e.printStackTrace();
        }
    }
    
    public void analyse(int innerPanelNo){

        StanfordCoreNlpDemo nlp = new StanfordCoreNlpDemo();      
        
        PieDataset dataset = createDataset();
        if(innerPanelNo==1){
        // Create chart
            chart = ChartFactory.createPieChart(
                filenameCSV+ " Sentiment Analysis",
                dataset,
                true, 
                true,
                false);
            PieSectionLabelGenerator labelGenerator = new StandardPieSectionLabelGenerator(
                    "{0} : ({2})", new DecimalFormat("0"), new DecimalFormat("0%"));
                ((PiePlot) chart.getPlot()).setLabelGenerator(labelGenerator);
        }
        else if(innerPanelNo==2){
        	chart2 = ChartFactory.createPieChart(
	                filenameCSV+ " Sentiment Analysis",
	                dataset,
	                true, 
	                true,
	                false);
        	PieSectionLabelGenerator labelGenerator = new StandardPieSectionLabelGenerator(
                    "{0} : ({2})", new DecimalFormat("0"), new DecimalFormat("0%"));
                ((PiePlot) chart2.getPlot()).setLabelGenerator(labelGenerator);
        }

        if (innerPanelNo==1){
        	chartPanel = new ChartPanel(chart);
        	chartPanel.setBounds(0,0, 400, 400);
        	chartPanel.setVisible(true);
            this.inner_panel_3.add(chartPanel);                
        }
        else if(innerPanelNo==2){
        	chartPanel2 = new ChartPanel(chart2);
        	chartPanel2.setBounds(0,550, 400, 400);
        	chartPanel2.setVisible(true);
            this.inner_panel_3.add(chartPanel2);
        }

        inner_panel_3.revalidate();
		inner_panel_3.repaint();

	}
    
    public void createAndUpdateGUI(){
    	JFrame frame = new JFrame("Group 32");
    	
		WindowListener l = new WindowAdapter() {
		    public void windowClosing(WindowEvent e) {System.exit(0);}
		};
		frame.addWindowListener(l);
	
		frame.getContentPane().setLayout(new GridLayout(0, 1, 0, 0));
		frame.getContentPane().add("Center", this.tabbedPane);
		frame.setSize(1920, 2000);																													//change the sizing of window here
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }

    public static void main(String[] args) {
	/*
	 * Create a window.  Use JFrame since this window will include 
	 * lightweight components.
	 */
    	DisplayGUI main = new DisplayGUI();
    	main.createAndUpdateGUI();
    }
}