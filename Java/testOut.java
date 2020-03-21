import java.io.File;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
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

public class testOut {
	
public static String stringRetweets(ArrayList<String[]> retweets) {
		
		return retweets.toString(); 
	}
	
	public static void analysation()
	{
		ArrayList<String[]> retweets = new ArrayList<>(); 
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
			
			for(String[] row: allData)
			{
				retweets.add(row); 
				//System.out.println(row[2]);	
			}
			
			for (int i=0; i< 10; i++) {
				String tempStr = (retweets.get(2))[2];
				for(String[] reteets: retweets) {
					if ((Integer.parseInt(tempStr))<Integer.parseInt(reteets[2])){
						int max = Integer.parseInt(reteets[2]);
						
						System.out.println(max); 
					}
							
				}
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
