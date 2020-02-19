package grp32;

import javax.swing.*;  
import java.awt.GridLayout;
import java.awt.Component;
import java.awt.FlowLayout;
import java.awt.event.WindowListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.Panel;
import java.awt.Button;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class DisplayGUI extends JPanel implements ActionListener{
	private JTextField textField;
    public DisplayGUI() {
    	super(true);     		    // true = please double buffer

		JTabbedPane tabbedPane = new JTabbedPane();
		
	
		//PENDING: Add icons to tabs.
		String crawlFromHereLabel = "Crawl from here :";
		JLabel l = new JLabel(crawlFromHereLabel);
		l.setBounds(50, 30,90,20);
		
		String crawlFromHereList[]={"Twitter","CNN"};        
	    JComboBox cb=new JComboBox(crawlFromHereList);
	    cb.setBounds(50, 50,90,20);
	    
	    JButton b=new JButton("Click here to crawl");  
	    b.setBounds(50,100,95,30);  
	    
	    JPanel panel = new JPanel();
		panel.setLayout(new FlowLayout());
		panel.add(l);
		panel.add(cb);
		panel.add(b);
		panel.setSize(750,750); 
	    
		Component panel1 = panel;
		panel1.setSize(750,750);
	
		tabbedPane.setSize(750,750);
		//Add the tabbed pane to this panel.
		setLayout(new GridLayout(1, 0));
        add(tabbedPane);
        
        Panel panel_1 = new Panel();
        tabbedPane.addTab("Crawl", null, panel_1, null);
        panel_1.setLayout(null);
        
        JComboBox comboBox = new JComboBox();
        comboBox.setBounds(247, 6, 89, 20);
        comboBox.setModel(new DefaultComboBoxModel(new String[] {"Twitter", "CNN"}));
        panel_1.add(comboBox);
        
        Button button = new Button("Crawl");
        button.setBounds(346, 4, 89, 22);
        panel_1.add(button);
        
        textField = new JTextField();
        textField.setText("");
        textField.setBounds(119, 37, 217, 20);
        panel_1.add(textField);
        textField.setColumns(10);
        
        JButton btnNewButton_1 = new JButton("Save as");
        btnNewButton_1.setBounds(346, 36, 89, 23);
        panel_1.add(btnNewButton_1);
        
        Panel panel_2 = new Panel();
        tabbedPane.addTab("Results of crawl", null, panel_2, null);
        
        JLabel lblShowResultIn = new JLabel("Show result in a ");
        panel_2.add(lblShowResultIn);
        
        JButton btnNewButton = new JButton("New window");
        btnNewButton.addActionListener(this);
        panel_2.add(btnNewButton);
        
        JPanel panel_3 = new JPanel();
        tabbedPane.addTab("Search", null, panel_3, null);
        
        JLabel lblNewLabel = new JLabel("Search");
        panel_3.add(lblNewLabel);
        
        JComboBox comboBox_1 = new JComboBox();
        comboBox_1.setModel(new DefaultComboBoxModel(new String[] {"Date", "Location", "Time"}));
        panel_3.add(comboBox_1);
        
        JPanel panel_4 = new JPanel();
        tabbedPane.addTab("Results of analysis", null, panel_4, null);
        
        JLabel lblNewLabel_1 = new JLabel("View");
        panel_4.add(lblNewLabel_1);
        
        JComboBox comboBox_2 = new JComboBox();
        comboBox_2.setModel(new DefaultComboBoxModel(new String[] {"Table", "Graph"}));
        panel_4.add(comboBox_2);
        
    }
    
    public void actionPerformed(ActionEvent e){
    	Object obj = e.getSource();
    	if (obj instanceof JButton) {																												//validate "New window" is creating
    		if ( ((JButton)obj).getText().equals("New window")){
	    		DisplayCSV dd = new DisplayCSV();
	        	dd.createAndShowGUI();
    		}
    	}  	
    }

    public static void main(String[] args) {
	/*
	 * Create a window.  Use JFrame since this window will include 
	 * lightweight components.
	 */
		JFrame frame = new JFrame("TabbedPaneDemo");
	
		WindowListener l = new WindowAdapter() {
		    public void windowClosing(WindowEvent e) {System.exit(0);}
		};
		frame.addWindowListener(l);
	
		frame.getContentPane().add("Center", new DisplayGUI());
		frame.setSize(750, 425);																													//change the sizing of window here
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}