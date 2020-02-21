//package com.mkyong.basicwebcrawler;
package myPackage;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.select.Elements;
import org.jsoup.nodes.Element;



class WebCrawlGuardian extends crawler implements News{
	private static final int MAX_DEPTH = 15;
    private HashSet<String> visited_Links; // stores the links that the crawler has visited
    private String baseURL; // Starting URL
    private int visitedPages = 0;
    private int maxPage = 300;
    private String keyword2;
    
    
    public WebCrawlGuardian(String URL,String key,String key2) {
    	super(key);
        visited_Links = new HashSet<String>();
        baseURL = URL;
        keyword2 = key2;
    }
    
    public void setMaxPage(int Max) {
    	maxPage = Max;
    }
    
    public int getMaxPage(int Max) {
    	return maxPage;
    }
    

    public void getPageLinks(String URL, int depth)// ,int col_node 
    {
    
    		
    
    	
        if ((!visited_Links.contains(URL) && (depth <= MAX_DEPTH))) {
        	
            try {
            	if(visited_Links.add(URL)) {
            		//System.out.println( " " +  URL + "" );
            		System.out.println("Visited pages no." + visitedPages);
            		if(depth+1 <= MAX_DEPTH) {
            			Document document = Jsoup.connect(URL).get();
            			Elements linksOnPage = document.select("a[href]");
            			
            			
            			
            			
            			
            			for (Element page : linksOnPage) {
            				if(visitedPages <= maxPage) {
            				String CurrentLink = page.attr("abs:href"); 
            				
            				// Get Articles that are within the current website scope and checking for if got keyword or no keyword
            					if(!visited_Links.contains(CurrentLink) && CurrentLink.contains(baseURL) && !CurrentLink.contains(".jpg") ){   
            						if(!CurrentLink.contains("#"))
            							this.getArticlesOfKeyWord(this.keyword,CurrentLink);
            							this.visitedPages++;
            						this.getPageLinks(CurrentLink, depth+1); 
            						}
            					//}
            				}	
            				else {
            					break;
            				}
            			}
                	
            		//}
            	}	
                
            	} 
                
            } catch (IOException e) {
            	
                System.err.println("For '" + URL + "': " + e.getMessage());
            }
        }
    	
    }
   
    public void getArticlesOfKeyWord(String keyword,String URL) {
    			try {
    				Document document = Jsoup.connect(URL).get();
    				Elements articleHeader = document.select("h1.content__headline");
    				Elements articleDate = document.select("p.content__dateline time.content__dateline-wpd");  //js-wpd.content__dateline-wpd--modified
    				//System.out.println();
    				String Time = articleDate.text();
    				String NewTime = "";
    				if(Time.length() > 25) {
    					NewTime = Time.substring(0,26);
    				}
    				else
    					NewTime = Time;
    				//
    				String Header = articleHeader.text();
    				String[] tempArray;
    				tempArray = URL.split("/");
    				if(this.keyword.isEmpty() || this.keyword2.isEmpty())
					{
						if(Header.length() != 0 && NewTime.length() !=0)
							
							this.data.add(new String[]{tempArray[3],articleHeader.text(),NewTime});
					}
    				else
    				if(Header.contains(this.keyword)|| Header.contains(this.keyword2))
    				{
    					if(Header.length() != 0 && NewTime.length() != 0)
    						this.data.add(new String[]{tempArray[3],articleHeader.text(),NewTime});//articleDate.text()
    				}
    				
    					

    					
    				}
    				
    				
    			 catch (IOException e) {
                    System.err.println("For '" + URL + "': " + e.getMessage());
                }
    }
    
    public void writeToFile(String filename) {
      
    	StringBuffer csvHead = new StringBuffer("");
    	csvHead.append("Article_Category ,Article_Title, Date_Published\n");
    	try {
    		givenDataArray_whenConvertToCSV_thenOutputCreated(data,filename,csvHead);
    	}
    	catch(IOException IE) {
    		System.out.println(IE.getMessage());
    		System.out.println("Something went wrong");
    	}
    	
    }
    
    /*public static void main(String[] args) {
     	String keyword = "";
	    	String keyword2 = "";
	    	String URL = "https://www.theguardian.com/";
	    	//String URL = "https://www.bbc.com/";
	    	News webCrawlCNN = new WebCrawlCNN(URL,keyword,keyword2);
     		webCrawlCNN.getPageLinks(URL,0); 
	    	String csv_Name = "Test.csv";
	    	webCrawlCNN.writeToFile(csv_Name);
     
     }*/
   	
}
   

  





