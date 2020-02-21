package grp32;


import java.io.IOException;
import java.text.DateFormat;  
import java.text.SimpleDateFormat;  
// importing twitter4j libraries
import twitter4j.*;
import twitter4j.Twitter;
import twitter4j.TwitterFactory;
import twitter4j.auth.AccessToken;

class CrawlWithTJ4 extends Crawler implements Tweet {

	private static final String con_Key = "DubGZhfy08e2kF7r4Z1FnH5nu";
	private static final String con_s="hfX9xdxvppgMIKaeJi2X8fzbood46UNyRJa25yzTQr931OOAmN";
	private static final String access_T = "285684564-QgwQAfaSgFLwlWNzl6JIpD6WlDCYPyiZsGKfU4Uc";
	private static final String access_T_S = "Lcx2SpsfGoKaxrtqg3sZOnIHIntfYZJpBMgUkPZGAXoyI";
	
	private final int max_Pages = 3;
	
	
	
	public CrawlWithTJ4(String kw) {
        super(kw);
    }
	
	public void run() 
    { 
        try
        { 
        	searchTweets();
        }
        catch (Exception e) 
        { 
            // Throwing an exception 
            System.out.println ("Exception is caught"); 
        } 
    }
	
	public void writeToFile(String filename) {
		
		StringBuffer csvHead = new StringBuffer("");
		
    	csvHead.append("Username,Tweet,Retweet_Count,Favourite_Count,Date\n");
		try {
    		givenDataArray_whenConvertToCSV_thenOutputCreated(data,filename,csvHead);
    	} catch (IOException e) {
            System.err.println(e.getMessage());
        }
    }
	
	public void searchTweets()  {
		System.out.println(this.keyword);
		Twitter twitter = new TwitterFactory().getInstance();
		twitter.setOAuthConsumer(con_Key,con_s);
		AccessToken oathAccessT = new AccessToken(access_T,access_T_S);
		twitter.setOAuthAccessToken(oathAccessT);
		int i = 0;
		DateFormat dateFormat = new SimpleDateFormat("dd/MM/yyyy hh:mm.a");  
		String strDate = new String();
		Query query = new Query();
		query.setLang("en");
		query.setQuery(this.keyword +"+exclude:retweets");
		QueryResult result ;
		try {
		    do {
		    	result = twitter.search(query);
		    for (Status status : result.getTweets()) {
		    	strDate = dateFormat.format(status.getCreatedAt());  // date format
			
		    	// add to data list.
				this.data.add(new String[]{"@"+status.getUser().getScreenName(),status.getText(),Integer.toString(status.getRetweetCount()),Integer.toString(status.getFavoriteCount()),strDate});
				
		    	
				// uncomment to display tweets
		       // System.out.println("@" + status.getUser().getScreenName() + ":" + status.getText());
		   
		    	//}
				}
				
		    
				
		    
		    i++;
		    }while((query = result.nextQuery()) != null && i > this.max_Pages);
		 
		    
		    	
			
		}catch (TwitterException te) {
           
			String error = te.getMessage();
			if(error.contains("rate limit")) { // for reaching API limit 
				System.out.println("API rate limit constraint, try again in awhile");
			}
			else
				System.out.println("Failed to search tweets: " + te.getMessage());
            
        }
		

	}
	
	
	
	
	
	
	
}