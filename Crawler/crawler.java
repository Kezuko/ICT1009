package grp32;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

abstract class Crawler {

	List<String[]> data;
	String keyword;
	
	public Crawler() {
		
	}
	
	public Crawler(String key) {
		 	keyword = key;
		   	data = new ArrayList();
	}
	
	public void setKeyword(String key) {
		keyword = key;
	}
	
	public String getKeyword() {
		return keyword;
	}
	
	
	// 
	public String convertToCSV(String[] data) {
	    return Stream.of(data)
	      .map(this::escapeSpecialCharacters)
	      .collect(Collectors.joining(","));
	}
	
	// Format the string into a format suitable for CSV file before allowing it to be inserted to the CSV file. 
	public String escapeSpecialCharacters(String data) {
		String escapedData = data.replaceAll("\\R", " ");
		if (data.contains(",") || data.contains("\"") || data.contains("'")) {
		data = data.replace("\"", "\"\"");
		escapedData = "\"" + data + "\"";
		}
		return escapedData;
	}
	
	
	public void givenDataArray_whenConvertToCSV_thenOutputCreated(List<String[]> dataLines,String CSV_File_Name,StringBuffer CSVHeader) throws IOException {	
	    File csvOutputFile = new File(CSV_File_Name);
	   
	    try (PrintWriter pw = new PrintWriter(csvOutputFile)) {
	    	if(csvOutputFile.exists()) {
	    		pw.write(CSVHeader.toString());
	    	}
	        dataLines.stream()
	          .map(this::convertToCSV)
	          .forEach(pw::println);
	    }
	   
	   // assertTrue(csvOutputFile.exists());
	}
	
	 public abstract void writeToFile(String filename);
		
	
}