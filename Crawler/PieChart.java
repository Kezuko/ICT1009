package grp32;


import java.text.DecimalFormat;

import javax.swing.JFrame;
import javax.swing.SwingUtilities;
import javax.swing.WindowConstants;

import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.labels.PieSectionLabelGenerator;
import org.jfree.chart.labels.StandardPieSectionLabelGenerator;
import org.jfree.chart.plot.PiePlot;
import org.jfree.data.general.DefaultPieDataset;
import org.jfree.data.general.PieDataset;

public class PieChart extends JFrame {
  private static final long serialVersionUID = 6294689542092367723L;

  private static double posSent;
  private static double negSent;
  private static double neuSent;
  private static double vNegSent;
  private static double vPosSent;
  
  public static void setPos(double posSent){PieChart.posSent = posSent;}
  public static void setNeg(double negSent){PieChart.negSent = negSent;}
  public static void setNeu(double neuSent){PieChart.neuSent = neuSent;}
  public static void setvNeg(double vNegSent){PieChart.vNegSent = vNegSent;}
  public static void setvPos(double vPosSent){PieChart.vPosSent = vPosSent;}
  
  public PieChart(String title) {
    super(title);

    // Create dataset
    PieDataset dataset = createDataset();

    // Create chart
    JFreeChart chart = ChartFactory.createPieChart(
        "Sentiment Analysis of the " + title,
        dataset,
        true, 
        true,
        false);

    //Format Label
    PieSectionLabelGenerator labelGenerator = new StandardPieSectionLabelGenerator(
        "{0} : ({2})", new DecimalFormat("0"), new DecimalFormat("0%"));
    ((PiePlot) chart.getPlot()).setLabelGenerator(labelGenerator);
    
    // Create Panel
    ChartPanel panel = new ChartPanel(chart);
    setContentPane(panel);
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

  public static void main(String[] args) {
    SwingUtilities.invokeLater(() -> {
      PieChart example = new PieChart("Sentiment Analysis of the <name>");
      example.setSize(800, 400);
      example.setLocationRelativeTo(null);
      example.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
      example.setVisible(true);
    });
  }
}


