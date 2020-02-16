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



class BasicWebCrawler extends crawler implements News{
	private static final int MAX_DEPTH = 15;
    private HashSet<String> visited_Links; // stores the links that the crawler has visited
    private String baseURL; // Starting URL
    private int visitedPages = 0;
    private static final int maxPage = 5000;
    private String keyword2;
    
    
    public BasicWebCrawler(String URL,String key,String key2) {
    	super(key);
        visited_Links = new HashSet<String>();
        baseURL = URL;
        keyword2 = key2;
    }
    
    

    public void getPageLinks(String URL, int depth)// ,int col_node 
    {
    
    		
    	
    	
        if ((!visited_Links.contains(URL) && (depth <= MAX_DEPTH))) {
        	
            try {
            	if(visited_Links.add(URL)) {
            		//System.out.println(">> Depth: " + depth + " " +  URL + "" );
            		System.out.println("Visited pages no." + visitedPages);
            		if(depth+1 <= MAX_DEPTH) {
            			Document document = Jsoup.connect(URL).get();
            			Elements linksOnPage = document.select("a[href]");
            			for (Element page : linksOnPage) {
            				if(visitedPages <= maxPage) {
            				String CurrentLink = page.attr("abs:href"); 
            				
            				// Get Articles that are within the current website scope and checking for if got keyword or no keyword
            					if(!visited_Links.contains(CurrentLink) && CurrentLink.contains(baseURL) && !CurrentLink.contains(".jpg") ){   
            						if(!CurrentLink.contains("#")){
            							if(this.keyword.isBlank()) { // for keyword being empty
            								this.getArticlesOfKeyWord(this.keyword,CurrentLink);
            							}
            							else
            								if((CurrentLink.contains(keyword) || CurrentLink.contains(keyword2))){ // 
            									this.getArticlesOfKeyWord(this.keyword,CurrentLink);
            								}
            							this.visitedPages++;
            						this.getPageLinks(CurrentLink, depth+1); 
            						}
            					}
            				}	
            				else {
            					break;
            				}
            			}
                	
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
    				Elements articleHeader = document.select("article h1"); // CNA article header 
    				Elements articleDate = document.select("time.article__details-item"); //CNA article time
    				//System.out.println();
    				String[] tempArray;
    				tempArray = URL.split("/");
    				
    				
    				if(!articleHeader.text().isEmpty()) { // making sure that crawler saves actual data and not empty
    					if(tempArray.length >4) {
    						//System.out.println(tempArray[3] + " "+tempArray[4]);
    						this.data.add(new String[]{tempArray[4],articleHeader.text(),articleDate.text()});
    						
        				
    					}
    					
    				}
    				
    				
    			} catch (IOException e) {
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
    		System.out.println("Something went wrong");
    	}
    	
    }
   
}
   

  





