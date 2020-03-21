import java.io.File;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import com.opencsv.CSVReader;
import com.opencsv.CSVReaderBuilder;

class model_1
{
	private String[] columnNames = { "Username", "Tweet", " Retweet_Count", "Favourite_Count", "Date" };						//for twitter
    //private final String[] columnNames = { "Article_Category", "Article_Title", " Date_Published" };									//for CNA
	private ArrayList<String[]> Data = new ArrayList<String[]>();																		//change column name(one line above)

    public void setColumnNames(String[] colsName){columnNames = colsName;}
    
    
}

public class analyseTweets {
	
	public static void analysation()
	{
		ArrayList<String[]> retweets = new ArrayList<String[]>(); 
		model_1 model = new model_1(); 
		
		
		File DataFile; 
		DataFile = new File("testTweets - Copy.csv");
		
		try
		{
			FileReader filereader = new FileReader("testTweets - Copy.csv"); 
			
			CSVReader csvReader = new CSVReaderBuilder(filereader).build(); 
			
			String[] temp = csvReader.readNext(); 
			model.setColumnNames(temp);
			List<String[]> allData = csvReader.readAll(); 
			
			ArrayList<Integer> retweet_count = new ArrayList<Integer>();
			ArrayList<Integer> favourite_count = new ArrayList<Integer>(); 
			
			for(String[] row: allData)
			{
				retweet_count.add(Integer.parseInt(row[2]));
				favourite_count.add(Integer.parseInt(row[3])); 
			}
			
			//to get the retweet_count of the highest
			Collections.sort(retweet_count, Collections.reverseOrder()); 
			
			//to get the favourite_count of the highest
			Collections.sort(favourite_count, Collections.reverseOrder()); 
			
			int size = 10; 
			
			//get the top 10 rows from the highest(retweets)
			for(int i = 0; i < size; i++)
			{
				System.out.println(retweet_count.get(i));
			}
			
			//get the top 10 rows from the highest (favourites)
			for(int j = 0; j < size; j++)
			{
				System.out.println(favourite_count.get(j)); 
			}
			
			
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
	public static void main(String[] args) throws Exception
	{
		analysation();
	}

}
