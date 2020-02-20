package grp32;

import java.awt.BorderLayout;
import java.awt.EventQueue;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import javax.swing.JFrame;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.table.AbstractTableModel;

public class FiletoJTable {

    public static void main(String[] args) {
        Runnable r = new Runnable() {

            public void run() {
                new FiletoJTable().createUI();
            }
        };

        EventQueue.invokeLater(r);
    }

    //private void createUI() {
    void createUI() {

        try {
            JFrame frame = new JFrame();
            frame.setLayout(new BorderLayout());
            JTable table = new JTable();

            String readLine = null;

            TwitterTableModel tableModel = new TwitterTableModel();
            File file = new File("twitter - Copy.txt");																											//change filename here

            FileReader reader = new FileReader(file);
            BufferedReader bufReader = new BufferedReader(reader);

            List<Twitter> twitterList = new ArrayList<Twitter>();
            
            String removeLastLetterDelimiter;
            while((readLine = bufReader.readLine()) != null) {
                //String[] splitData = readLine.split("-");
            	//System.out.println("\n\n" + readLine + "\n\n");
                Twitter twitter = new Twitter();
                //twitter.setName(splitData[0]);
                //twitter.setName(splitData[1]);
                if (readLine.isEmpty())
                {
                	continue;																																//if empty line; skip
                }
                if (readLine.indexOf(";;")!=-1 && readLine.indexOf("}")!=-1){														//first sentence is the whole tweet
                	String[] startOfUsername = readLine.split("@");
	                																																	//startOfUsername = start of username
	                String[] endOfUsername = startOfUsername[1].split(";;");
                	twitter.setName(endOfUsername[0]);
	                //System.out.println(endOfUsername[0] + " --username");																						//endOfUsername = end of username
	                //twitter.setName(endOfUsername[0]);
	                
	                String[] startandEndOfTweet = readLine.split(";;");																								//startandEndOfTweet = start of tweet
	                removeLastLetterDelimiter = startandEndOfTweet[1].substring(0, startandEndOfTweet[1].length()-2);
	                twitter.setTweet(removeLastLetterDelimiter);
	                //System.out.println(removeLastLetterDelimiter + " --tweet");														//tweet need python slicing of last letter "}"
//	                if (readLine.substring(readLine.length()-1).equals("}")){
//	                	String[] momo = startandEndOfTweet[1].split(";");																								//momo = end of tweet
//	                }	
                }
                
                else if (readLine.indexOf(";;")!=-1 && readLine.indexOf("}")==-1){														//first sentence is NOT the whole tweet
//                	String[] startOfUsername = readLine.split("@");
//																																						
//            		//System.out.println(startOfUsername[0] + "  --CLIMAX");
//            		String[] endOfUsername = startOfUsername[1].split("\"");
//            		
//            		System.out.println(endOfUsername[0] + " --username");																						
//	                twitter.setName(endOfUsername[0]);
	                
                	twitter.setName("-");
                	
	                String[] startandEndOfTweet = readLine.split(";;");
	                twitter.setTweet(startandEndOfTweet[1]);
	                //System.out.println(startandEndOfTweet[1] + "  --tweet more after");
                }
                
                //if (readLine.substring(0, 1).equals("-")){
                else if (readLine.indexOf(";;")==-1 && readLine.indexOf("}")==-1){															//tweet is in the middle																				
                	twitter.setName("-");
                	twitter.setTweet(readLine);
                	//System.out.println(readLine + "  --tweet in the middle");
                }
                              
                else if (readLine.indexOf(";;")==-1 && readLine.indexOf("}")!=-1){														//end of the tweet																													//second sentence and onwards
                	String[] nayeon = readLine.split(";;");	
                	removeLastLetterDelimiter = nayeon[0].substring(0, nayeon[0].length()-2);
                	twitter.setName("-");																											//nayeon = continuation of tweet
	                twitter.setTweet(removeLastLetterDelimiter);
	                //System.out.println(removeLastLetterDelimiter + " --end of tweet");
                }
                
                
                
                
                twitterList.add(twitter);
            }

            tableModel.setList(twitterList);
            table.setModel(tableModel);

            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.add(new JScrollPane(table));
            frame.setTitle("File to JTable");
            frame.pack();
            frame.setBounds(0, 0, 1500, 1000);
            frame.setVisible(true);

        } catch(IOException ex) {}
    }

    class Twitter {

        private String username;
        private String tweet;

        public String getName() {
            return username;
        }
        public void setName(String username) {
            this.username = username;
        }
        public String getTweet() {
            return tweet;
        }
        public void setTweet(String tweet) {
            this.tweet = tweet;
        }
    }

    class TwitterTableModel extends AbstractTableModel {

        private List<Twitter> list = new ArrayList<Twitter>();
        private String[] columnNames = {"Username", "Tweet"};

        public void setList(List<Twitter> list) {
            this.list = list;
            fireTableDataChanged();
        }

        @Override
        public String getColumnName(int column) {
            return columnNames[column];
        }

        public int getRowCount() {
            return list.size();
        }

        public int getColumnCount() {
            return columnNames.length;
        }

        public Object getValueAt(int rowIndex, int columnIndex) {
            switch (columnIndex) {
            case 0:
                return list.get(rowIndex).getName();
            case 1:
                return list.get(rowIndex).getTweet();
            default:
                return null;
            }
        }
    }
}