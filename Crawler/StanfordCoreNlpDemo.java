package grp32;

import edu.stanford.nlp.pipeline.*;
import edu.stanford.nlp.util.CoreMap;
import edu.stanford.nlp.ling.CoreAnnotations;
import edu.stanford.nlp.sentiment.SentimentCoreAnnotations;
import java.math.RoundingMode;
import java.text.DecimalFormat;
 
import java.util.*;

import javax.print.DocFlavor.STRING;
 
public class StanfordCoreNlpDemo
{
    private static DecimalFormat df2 = new DecimalFormat("#.##");
 
    private static ArrayList<String> lineArr = new ArrayList<>();
    
    public static void setLine(String line){StanfordCoreNlpDemo.lineArr.add(line);}
    
    public StanfordCoreNlpDemo(){
        int negative=0;
        int vNegative=0;
        int positive=0;
        int vPositive=0;
        int neutral=0;
        int count=0;
        double total;
        double totalNeg;
        double totalPos;
        double posPercentage;
        double negPercentage;
        double neutPercentage;
        double vPosPercentage;
        double vNegPercentage;

        Properties pipelineProps = new Properties();
        Properties tokenizerProps = new Properties();
        pipelineProps.setProperty("annotators", "parse, sentiment");
        pipelineProps.setProperty("parse.binaryTrees", "true");
        pipelineProps.setProperty("enforceRequirements", "false");
        tokenizerProps.setProperty("annotators", "tokenize ssplit");
        StanfordCoreNLP tokenizer = new StanfordCoreNLP(tokenizerProps);
        StanfordCoreNLP pipeline = new StanfordCoreNLP(pipelineProps);
        // String line = " never regret to love you and the others member really i mean it,thank you for being you,thank you for loving us,Army..thank you for your music and passion..,borahaee";
        //String line = "Cocktail of flu, HIV drugs appears to help fight coronavirus: Thai doctors(Article: BANGKOK: Thai doctors have seen success in treating severe cases of the new coronavirus with combination of medications for flu and HIV, with initial results showing vast improvement 48 hours after applying the treatment, they said on Sunday (Feb 2). The doctors from Rajavithi Hospital in Bangkok said a new approach in coronavirus treatment had improved the condition of several patients under their care, including one 70-year-old Chinese woman from Wuhan who tested positive for the coronavirus for 10 days. The drug treatment includes a mixture of anti-HIV drugs lopinavir and ritonavir, in combination with flu drug oseltamivir in large doses. \"This is not the cure, but the patient's condition has vastly improved. From testing positive for 10 days under our care, after applying this combination of medicine the test result became negative within 48 hours,\" Dr Kriangska Atipornwanich, a lung specialist at Rajavithi, told reporters. \"The outlook is good but we still have to do more study to determine that this can be a standard treatment.\" Chinese health officials have already been administering the HIV and flu drugs to fight the coronavirus. The use of the three together in a cocktail seemed to improve the treatment, the Thai doctors said. Another doctor said that a similar approach in two other patients resulted in one displaying some allergic reaction but the other showed improvement. \"We have been following international practices, but the doctor increased the dosage of one of the drugs,\" said Somsak Akkslim, director-general of the Medical Services Department, referring to the flu medicine Oseltamivir. Thailand has recorded 19 cases of coronavirus. Of the Thai patients, eight have recovered and gone home while 11 are still under treatment in hospitals. Somsak said the health ministry will meet on Monday to discuss the successful treatment in the case of the 70-year-old but said it is still too soon to say that this approach can be applied to all cases.";
        int tempLength= StanfordCoreNlpDemo.lineArr.size();
        System.out.println("Array = " + StanfordCoreNlpDemo.lineArr + ",Length = " + tempLength);
        String[] ar = new String[100];
        for(String x:StanfordCoreNlpDemo.lineArr){
        	ar = x.split("[.!?]");
        	 
        	for (String s : ar){
    	    	System.out.println(s);
    	     	s = s.trim();
    	     	if(!s.isEmpty()){
    	             Annotation annotation = tokenizer.process(s);
    	             pipeline.annotate(annotation);
    	             // normal output
    	             for (CoreMap sentence : annotation.get(CoreAnnotations.SentencesAnnotation.class)) {
    	                 String output = sentence.get(SentimentCoreAnnotations.SentimentClass.class);
    	                 System.out.println("Input sentence " + count + " is: "+ sentence);
    	                 if(output.equals("Very negative")){
    	                     vNegative++;
    	                 }else if(output.equals("Negative")){
    	                     negative++;
    	                 }else if(output.equals("Neutral")){
    	                     neutral++;
    	                 }else if(output.equals("Very positive")){
    	                     vPositive++;
    	                 }else if(output.equals("Positive")){
    	                     positive++;
    	                 }
    	                 System.out.println("The feeling of this sentence is: " + output + "\n");
    	                 count++;
    	             }
    	     	}
    	    }
        }
	    
       


        total = vNegative + negative + neutral + vPositive + positive;
        totalNeg = vNegative + negative;
        totalPos = vPositive + positive;
        vNegPercentage = (vNegative/total)*100;
        vPosPercentage = (vPositive/total)*100;
        negPercentage = (totalNeg/total)*100;
        posPercentage = (totalPos/total)*100;
        neutPercentage = 100.00 - negPercentage - posPercentage;
        System.out.println("\nThe tweet is " + df2.format(negPercentage)+ "% negative and " + df2.format(posPercentage) + "% positive");
        System.out.println("\nThe tweet is " + df2.format(vNegPercentage)+ "% v negative and " + df2.format(vPosPercentage) + "% v positive"+ df2.format(neutPercentage) + "% neutral");
        PieChart.setNeg(negPercentage);																				//negative sentiment
        PieChart.setPos(posPercentage);
        PieChart.setNeu(neutPercentage);
        PieChart.setvNeg(vNegPercentage);
        PieChart.setvPos(vPosPercentage);
        // System.out.println("The tweet is " + df2.format(posPercentage) + "% positive");
        if(totalNeg > totalPos){
            System.out.println("The overall tweet is negative");
        }else if(totalNeg == totalPos){
            System.out.println("The overall tweet is neutral");
        }else{
            System.out.println("The overall tweet is positive");
        }
    }
    
}