import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

/**
 * This JFrame is used for displaying output from various thread classes.  It provides a "Run"
 * button, which when pressed starts each thread, and three JLabels which threads can write to.
 * 
 * @author P. von Kaenel
 *
 */
@SuppressWarnings("serial")

public class EWNSframe extends JFrame {
    JPanel mainPanel,threadPanel, buttonPanel,
    		eastPanel, westPanel, northPanel, centerPanel;
	JLabel eastTitle,westTitle,northTitle, centerTitle,
			eastData, westData, centerData, northData;
	JButton runButton;
	JLabelThread westThread, centerThread, eastThread;
	

	/**
     * The constructor sets up the app's window.
     */
    public EWNSframe(JLabelThread wThread, JLabelThread cThread, JLabelThread eThread) 
    {  	
    	westThread = wThread;
    	centerThread = cThread;
    	eastThread = eThread;
    	
    	/*
    	 *
    	 *Creation of JLabels to display the number of guests
    	 *
    	 */
    	eastTitle = new JLabel(" East panel ");
    	westTitle = new JLabel(" West panel ");
    	northTitle = new JLabel(" EWNS Frame ");
    	centerTitle = new JLabel(" Center panel ");

    	eastTitle.setHorizontalAlignment(SwingConstants.CENTER);
    	westTitle.setHorizontalAlignment(SwingConstants.CENTER);
    	northTitle.setHorizontalAlignment(SwingConstants.CENTER);
    	centerTitle.setHorizontalAlignment(SwingConstants.CENTER);
    	
    	eastData = new JLabel(" ");
    	westData = new JLabel(" ");
    	centerData = new JLabel(" ");
    	northData = new JLabel(" ");

    	eastData.setHorizontalAlignment(SwingConstants.CENTER);
    	westData.setHorizontalAlignment(SwingConstants.CENTER);
    	centerData.setHorizontalAlignment(SwingConstants.CENTER);

     	/*
    	 *
    	 *A Panel is created to hold each of the three displays, one for the east and west turnstiles. 
    	 *	Each will hold a JLabel to display the number, and a JLabel to hold a caption.
    	 *
    	 */
    	eastPanel = new JPanel(new GridLayout(2,1));
    	eastPanel.add(eastTitle);
    	eastPanel.add(eastData);
    	
    	westPanel = new JPanel(new GridLayout(2,1));
    	westPanel.add(westTitle);
    	westPanel.add(westData);
    	
    	northPanel = new JPanel(new GridLayout(2,1));
    	northPanel.add(northTitle);

    	centerPanel = new JPanel(new GridLayout(2,1));
    	centerPanel.add(centerTitle);
    	centerPanel.add(centerData);
    	
    	if (westThread != null)
    		westThread.setDisplay(westData);
    	
    	if (centerThread != null)
    		centerThread.setDisplay(centerData);
    	
    	if (eastThread != null)
    		eastThread.setDisplay(eastData);
    	
    	
    	/*
    	 *
    	 *The panel holds each of the smaller displays in a row.
    	 *
    	 */
    	threadPanel = new JPanel(new GridLayout(1,3));
    	threadPanel.add(westPanel);
    	threadPanel.add(centerPanel);
    	threadPanel.add(eastPanel);
    	
    	/*
    	 *
    	 *The button panel holds the 'run' button.
    	 *
    	 */
    	buttonPanel = new JPanel();
    	runButton = new JButton("Run");
    	runButton.addActionListener(new ActionListener() {
    		public void actionPerformed(ActionEvent e)
    		{
    			runButtonAction();
    		}
    	});
 
    	buttonPanel.add(runButton);
    	
    	/*
    	 *
    	 *The main panel will be the content pane of the JFrame, and will use a borderlayout in which the title will
    	 *	go in the north section, the displays in the center, and the button in the south.
    	 *
    	 */
        mainPanel = new JPanel(new BorderLayout());
        mainPanel.add(northPanel,BorderLayout.NORTH);
        mainPanel.add(threadPanel,BorderLayout.CENTER);
        mainPanel.add(buttonPanel,BorderLayout.SOUTH);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);   // this lets the user exit by closing the panel
        setContentPane(mainPanel);
        pack();
        
		//Center the window - standard code
		
		Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
		Dimension frameSize = getSize();
		if (frameSize.height > screenSize.height)
		   frameSize.height = screenSize.height;
		if (frameSize.width > screenSize.width)
		   frameSize.width = screenSize.width;
		setLocation((screenSize.width - frameSize.width) / 2, (screenSize.height - frameSize.height) / 2);

		setVisible(true);

    }

    /**
     * This is the method for the 'Run' button.  It will create and start two threads, one for each turnstile.
     */
    void runButtonAction()
    {
    	if (eastThread != null)
    		eastThread.start();
    	if (centerThread != null)
    		centerThread.start();
    	if (westThread != null)
    		westThread.start();
    	
    }

	/**
	 * @param eastTitle the eastTitle to set
	 */
	public void setEastTitle(String title) {
		eastTitle.setText(title);
		eastTitle.setHorizontalAlignment(SwingConstants.CENTER);
	}

	/**
	 * @param westTitle the westTitle to set
	 */
	public void setWestTitle(String title) {
		westTitle.setText(title);
		westTitle.setHorizontalAlignment(SwingConstants.CENTER);
	}


	/**
	 * @param centerTitle the centerTitle to set
	 */
	public void setCenterTitle(String title) {
		centerTitle.setText(title);
		centerTitle.setHorizontalAlignment(SwingConstants.CENTER);
	}

	/**
	 * @param northTitle the northTitle to set
	 */
	public void setNorthTitle(String title) {
		northTitle.setText(title);
		northTitle.setHorizontalAlignment(SwingConstants.CENTER);
	}
}
