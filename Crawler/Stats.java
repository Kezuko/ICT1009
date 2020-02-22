package grp32;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

import java.util.List;

import com.opencsv.CSVReader;
import com.opencsv.CSVReaderBuilder;




//import grp32.Analysis.MyModel;

public class Stats {

	 private String mainFile;
	 private List<String[]> Top10RT = new ArrayList();
	 private List<String[]> Top10Fav = new ArrayList();
	 
	 List<String[]> allData = new ArrayList();
	 
	public Stats(String file) {
		mainFile = file;
		openCSV(mainFile); // opening csv file
	}
	
	public int getNumOfRows() {
			return allData.size();
	}
	
	public List<String[]> getTop10RT(){
		return Top10RT;
	}
	
	public List<String[]> getTop10Fav(){
		return Top10Fav;
	}
	
	public void clear(){
		Top10RT.clear();
		Top10Fav.clear();
	}
	
	
	
	public void openCSV(String file) {
		try {
			File DataFile = new File(this.mainFile);
			FileReader filereader = new FileReader(mainFile); 
			
			// create csvReader object and skip first Line 
			CSVReader csvReader = new CSVReaderBuilder(filereader).build(); 
			String[] temp = csvReader.readNext(); // header row. 
			allData = csvReader.readAll();
			clear();//clear before next stats
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}	catch (Exception e){
				e.printStackTrace();
			}
	}
	
	
	public void FindTop10Fav() {
		try {
			List<String []> newDataList = new ArrayList<>(allData);
			List<Integer> Favcount = new ArrayList();
			
			// store all data from fav column into a arraylist of int for comparing
			for (String[] rows : newDataList) {
				  int x = Integer.parseInt(rows[3]);
				Favcount.add(x);
				
			}
			
			
			// finding top 10 fav;
		
			for (int i =0; i <10;i++) {
				int size = Favcount.size();
				int Max = Favcount.get(0);
				int MaxIndex = 0;
				int current = 0;
				
				for(int j =1; j < size-1;j++) {
					
					current = Favcount.get(j);
					if(current > Max){
						Max = current;
						MaxIndex = j;
					}
				}
				Top10Fav.add(newDataList.get(MaxIndex));
				Favcount.remove(MaxIndex);
				newDataList.remove(MaxIndex);
			}
			
			// for displaying the top 10 Fav can be commented 
			int i =0;
			for (String[] rows : Top10Fav) {
				i++;
				System.out.println(i + " " + rows[0] + " RT = " + rows[2] + " Fav = " + rows[3] );
				//System.out.println(rows[0] + " " + rows[1] + " " + rows[2] + " "  + rows[3] + " " + rows[4]);
			}
			
			
		}catch (Exception e){
			e.printStackTrace();
		}
		
		
	}
	
	
	
	
	public void FindTop10RT() {
		try {
			
			//DataFile = new File(mainFile);
		
			List<String []> newDataList = new ArrayList<>(allData);
			List<Integer> RTcount = new ArrayList();

			// store all data from retweet column into a arraylist of int for comparing
			for (String[] rows : newDataList) {
				  int x = Integer.parseInt(rows[2]);
				RTcount.add(x);
				
			}
			// finding top 10 RT;
		
			for (int i =0; i <10;i++) {
				int size = RTcount.size();
				int Max = RTcount.get(0);
				int MaxIndex = 0;
				int current = 0;
				
				for(int j =1; j < size-1;j++) {
					
					current = RTcount.get(j);
					if(current > Max){
						Max = current;
						MaxIndex = j;
					}
				}
				Top10RT.add(newDataList.get(MaxIndex));
				RTcount.remove(MaxIndex);
				newDataList.remove(MaxIndex);
			}
			
			
			
			
			
			
			// for displaying the top 10 retweets can be commented 
			int i =0;
			for (String[] rows : Top10RT) {
				i++;
				System.out.println(i + " " + rows[0] + " RT = " + rows[2] + " Fav = " + rows[3] );
				//System.out.println(rows[0] + " " + rows[1] + " " + rows[2] + " "  + rows[3] + " " + rows[4]);
			}
			
			
			
			} catch (Exception e){
				e.printStackTrace();
			}
	}
	
	
	
	
	
	public static void main(String[] args) {
		Stats stat =  new Stats("testTweets.csv"); // can change to where you store your file name that you want to open
		
		//System.out.println(stat.getNumOfRows()); // to show the number of rows of data there are.
		stat.FindTop10RT(); // find top 10 retweeted tweets
		stat.FindTop10Fav(); // find top 10 favourited tweets
	}
	
	
}
