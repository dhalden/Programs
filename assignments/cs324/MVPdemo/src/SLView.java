import javax.swing.*;
import javax.swing.border.*;
import java.awt.*;
import java.awt.event.*;

//Special note: Do a search for the string "U S E R:" (without the spaces between letters).
//              This will show you where you can do some tweaking to this code.

/**
 * <strong>SLView</strong> defines a GUI interface that can 
 * be used as a user interface for a variety of programs.
 * 
 * <p>This is the "view" component of a model-view-controller (MVC) design pattern.
 * The view object interacts with a controller, which should be registered via the
 * registerController method.</p>
 *   
 * <p>The graphical interface includes the following panels:</p>
 * <p>1)  A grid of buttons can be used for game playing (checkers, etc.)</p>
 * <p>2)  A multi-line text area is provided for output,</p>
 * <p>3)  A text field and up to two buttons can be used to input and process
 *     user input strings,</p>
 * <p>4)  Four cursor buttons can be programmed to perform special tasks.</p>
 * <p>5)  Four command buttons can be programmed for any purpose, and</p>
 * <p>6)  A text field that triggers an action method when the user presses ENTER.</p>
 * 
 * <p>Non-grid buttons can be enabled/disabled and set visible or not. They can also be renamed.
 * Each button and the text field (panel 5) have associated action methods that are
 * invoked when the user presses a button or types text followed by ENTER in panel 6.
 * Panels 3-5 can be set visible or not.  Panel 1 is only created if the second constructor
 * is used.  There is no method for making the grid buttons invisible once created.
 *  </p>
 * 
 * <p>2014  (version 2)
 * IMPORTANT NOTE:  The button grid looks like a proper grid under Java 7.  If Java 6 is used,
 * the grid may appear as buttons with a little space between each.  The program still works
 * under 6, but the appearance of the grid will not be optimal.</p>
 * 
 * <p>2014	(version 2.2)
 * The SLView constructor that sets the button grid now includes four parameters for dimensions:
 * ( title_string, number of rows, number of columns, button width, button height)</p>
 * 
 * @author Pierre von Kaenel
 * 
 */
public class SLView extends JFrame //implements ActionListener
{
	private static final long serialVersionUID = 2L;
	public static String version = "version 2.2";
	
	protected SLController controller;
	
	// size of button grid, if used.  A value of 0 for row or column removes the button grid.
	private int gRow;
	private int gCol;
	private boolean useGridButton;
	private	int	gButX;		// the grid's button size (width, height)
	private int gButY;
		
	protected Font originalFont;
	
	// JButtons ----------------------------------
	protected JButton	button1,		// general purpose buttons
						button2,
						button3,
						button4;
	
	protected JButton	upButton,	// cursor buttons
						downButton,
						rightButton,
						leftButton;

	protected JButton 	aButton;		// buttons associated with abInput JTextField
	protected JButton	bButton;
	
	protected JButton[][]	gridButton;


	// JPanels ------------------------------------

	JScrollPane 		textPanel;
	protected JPanel	cursorPanel = new JPanel();		// contains cursorButtonPanel
	protected JPanel	cursorButtonPanel;
	protected JPanel 	commandPanel;
	protected Box  		actionPanel;
	protected JPanel 	inputPanel;
	protected JPanel 	abPanel;
	protected JPanel	abButtonPanel;   // goes inside abPanel
	protected JPanel	gridPanel;
	
	Border etchedBorder;
	Border titledBorder;


	
	
	// Text fields, text areas, buffers, and labels ----

	protected JTextArea textArea;
	protected JTextField textInput;
	protected JTextField abTextInput;
	protected JLabel label;

	
	// =============== Two public constructors ========================
	
	/**
	 * This constructor creates a view that does not include the button grid.
	 * @param title for the window
	 */
	public SLView(String title)
	{
		super(title);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		useGridButton = false;
		initSLgenView();
	}
	

	/**
	 * This constructor includes a button grid.
	 * @param title for the window
	 * @param row Number of rows in the grid (e.g. 3 rows are numbered 0, 1, 2).
	 * @param col Number of columns in the grid (first column is column 0)
	 * @param x Grid button's width
	 * @param y Grid button's height
	 */
	public SLView(String title, int row, int col, int x, int y)
	{
		super(title);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		// The following sets up the upper portion of the BorderLayout of the content pane.
		
		gRow = row;
		gCol = col;
		useGridButton = gRow*gCol > 0;		// If rows and/or columns are 0, then the grid is not displayed.
		gridButton = new JButton[row][col];
		gButX = x;
		gButY = y;
		initSLgenView();
	}
	
	
	/**
	 * Defines the layout and action listeners for the GUI.
	 * 
	 * The window contains the following (top to bottom):
	 * 
	 * A text area (multi-line text area to display information)
	 * The a-b button panel that also includes a text field
	 * The cursor panel that contains four cursor buttons
	 * A command button panel that contains four buttons
	 * Another text field that is processed when user presses Enter
	 * after entering text up to 15 characters.
	 * 
	 * @param title the window title.
	 */
	protected void initSLgenView()
	{
		
		//================ North panel  (gridPanel) ================================
		if (useGridButton)
		{
			gridPanel = new JPanel();
			gridPanel.setLayout(new GridBagLayout());
			GridBagConstraints gc = new GridBagConstraints();
			

			for (int r=0; r<gRow; r++)
			{
				for (int c=0; c<gCol; c++)
				{
					gridButton[r][c] = new JButton();

					// USER:
					// The GridBagLayout is a powerful layout manager.  The settings below can be
					// tweaked to make the buttons in the grid sized according to your needs.
					// For some grid sizes, the buttons squeeze together to form a checkerboard
					// grid, but at other times, there's no way around having spaces between the
					// buttons appear.
					//
					// Dimension(width, height) - changes the values to reshape the buttons.
					// The width and height values now come in as parameters to the constructor.

					gridButton[r][c].setPreferredSize(new Dimension(gButX, gButY));

					// The following should not be edited:
					gc.fill = GridBagConstraints.HORIZONTAL;
					gc.gridx = c;
					gc.gridy = r;
					
					// USER: If interested, google "Java Constraints GridBagLayout" for more info.
					// There's no need to uncomment and edit the values below, but under
					// special circumstances, you may want to experiment.
					
					//gc.ipadx = 0;
					//gc.ipady = 0;
					//gc.insets = new Insets(0,0,0,0);
					//gc.fill = GridBagConstraints.BOTH;
					//gc.weightx = 0;
					//gc.weighty = 0;
					//gc.gridwidth = 1;
					//gc.gridheight = 1;

					gridPanel.add(gridButton[r][c], gc);


					gridButton[r][c].putClientProperty("column", c);			
					gridButton[r][c].putClientProperty("row", r);

					// when the user presses a button, the view notifies the controller.

					gridButton[r][c].addActionListener(new ActionListener() {
						public void actionPerformed(ActionEvent ae) {
							gridButtonAction(ae);
						}
					});

				}
			}

			getContentPane().add( gridPanel, "North");
		}
		
		//=============== Center Panel (textPanel) =============================
		
		textArea = new JTextArea(15, 20);
		textPanel = new JScrollPane(textArea);
		textArea.setLineWrap(true);
		textArea.setTabSize(4);
		textArea.setEditable(false);	// USER: set to "true" to make it editable
		textPanel.setPreferredSize(new Dimension(100, 150));  // USER: can tweak these dimensions
		                                                      // or comment out
		
		getContentPane().add(textPanel, "Center");

		// Everything below the text area goes into the southPanel:
		
		//=============== southPanel ==============================
		Box southPanel = Box.createVerticalBox();

		//------------- a-b buttons and text field panel---------------
		abPanel = new JPanel();
		etchedBorder = BorderFactory.createEtchedBorder();
		titledBorder = BorderFactory.createTitledBorder(etchedBorder, "Process Data");
		abPanel.setBorder(titledBorder);
		abPanel.setLayout( new BoxLayout(abPanel, BoxLayout.Y_AXIS));
		
		aButton = new JButton("aButton");
		bButton = new JButton("bButton");
		abTextInput = new JTextField("", 20);
		
		// notify the controller if user presses a button.
		
		aButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent ae) {
				aButtonAction();
			}
		});
		
		bButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent ae) {
				bButtonAction();
			}
		});
		
		// put the text field above the "ab" buttons, use BoxLayouts
		
		abButtonPanel = new JPanel();
		abButtonPanel.setLayout( new BoxLayout(abButtonPanel, BoxLayout.X_AXIS));
		abButtonPanel.add(aButton);
		abButtonPanel.add(bButton);
		
		abPanel.add(abTextInput);
		abPanel.add(abButtonPanel);

		southPanel.add(abPanel);

		//----------The cursor panel - contains the cursor buttons-------------
		cursorButtonPanel = new JPanel();
		cursorButtonPanel.setLayout(new BorderLayout());
		
		
		// add "cursor" buttons
		
		upButton = new JButton("up");
		downButton = new JButton("down");
		rightButton = new JButton("right");
		leftButton = new JButton("left");	
		
		// notify the controller if user presses a button.
		
		upButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent ae) {
				upButtonAction();
			}
		});
		
		downButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent ae) {
				downButtonAction();
			}
		});
		
		rightButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent ae) {
				rightButtonAction();
			}
		});
		
		leftButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent ae) {
				leftButtonAction();
			}
		});
		

		JPanel upBPanel = new JPanel();
		upBPanel.add(upButton);
		JPanel rightBPanel = new JPanel();
		rightBPanel.add(rightButton);
		JPanel downBPanel = new JPanel();
		downBPanel.add(downButton);
		JPanel leftBPanel = new JPanel();
		leftBPanel.add(leftButton);
				
		cursorButtonPanel.add(upBPanel, BorderLayout.NORTH);
		cursorButtonPanel.add(rightBPanel, BorderLayout.EAST);
		cursorButtonPanel.add(downBPanel, BorderLayout.SOUTH);
		cursorButtonPanel.add(leftBPanel, BorderLayout.WEST);

		etchedBorder = BorderFactory.createEtchedBorder();
		titledBorder = BorderFactory.createTitledBorder(etchedBorder, "Cursor");
		cursorPanel.setBorder(titledBorder);
		cursorPanel.add(cursorButtonPanel);
		
		southPanel.add(cursorPanel);
		
		// 1) the command button panel which contains four buttons
		
		button1 = new JButton("Button1");
		button2 = new JButton("Button2");
		button3 = new JButton("Button3");
		button4 = new JButton("Button4");
		
		// notify the controller if user presses a button.
		
		button1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent ae) {
				button1Action();			
			}
		});

		
		button2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent ae) {
				button2Action();
			}
		});

		
		button3.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent ae) {
				button3Action();
			}
		});


		button4.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent ae) {
				button4Action();			}
		});

		
		actionPanel = Box.createHorizontalBox();
		actionPanel.add(button1);
		actionPanel.add(button2);
		actionPanel.add(button3);
		actionPanel.add(button4);
		
		commandPanel = new JPanel();
		etchedBorder = BorderFactory.createEtchedBorder();
		titledBorder = BorderFactory.createTitledBorder(etchedBorder, "Commands");
		commandPanel.setBorder(titledBorder);
		commandPanel.add(actionPanel);
		
		southPanel.add(commandPanel);

		//-----------the data panel : contains a textField--------------------

		textInput = new JTextField(15);
		label = new JLabel("Input", SwingConstants.CENTER);
		inputPanel = new JPanel(); 
		inputPanel.add(label);
		inputPanel.add(textInput);

 
		// listener for the bottom Text Field - activates when user hits "ENTER"
		
		textInput.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent event)
			{
				String textBuffer = textInput.getText();
				inputTextAction(textBuffer);
				textInput.setText("");   // delete string in the text field
			}
		});

		southPanel.add(inputPanel);
		getContentPane().add(southPanel, "South");

		pack();		// this makes java calibrate sizes of all objects on screen
		setMinimumSize(getSize());
		
		//Center the window

		Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
		Dimension frameSize = getSize();
		if (frameSize.height > screenSize.height)
			frameSize.height = screenSize.height;
		if (frameSize.width > screenSize.width)
			frameSize.width = screenSize.width;
		setLocation(
			(screenSize.width - frameSize.width) / 2,
			(screenSize.height - frameSize.height) / 2);

		setVisible(true);
		originalFont = 	textArea.getFont();

	}		// end of constructor
	
	/**
	 * Performs an action when the user has entered new text in the bottom input field.
	 * 
	 * @param input the input text
	 */
	protected void inputTextAction(String input)
	{
		if (controller == null) return;
		controller.inputTextAction(input);
	}
	
	/**
	 * When user clicks on a grid button, this method is invoked.  The properties are used to
	 * extract button location (row, column) and are passed to the controller.
	 * 
	 * @param ae the event caused by clicking a button.  It stores the button source.
	 */
	protected void gridButtonAction(ActionEvent ae)
	{
		JButton btn = (JButton) ae.getSource();
		int column = (Integer)btn.getClientProperty("column");
		int row = (Integer)btn.getClientProperty("row");
		
		// USER: the next line really isn't necessary, but is included for debugging if needed.
		// Comment out the line if you don't want data written to the console.
        System.out.println("clicked column " + column + ", row " + row);
        
        if (controller!=null)
        	controller.gridButtonAction(row, column);	// let the controller decide what to do.
	}

	/**
	 * Performs an action when the user clicks aButton.
	 * The controller might call getABInputText() to process the text
	 * that the user has entered in the text field.
	 * A subclass could define this as a "find" button, to 
	 * read the text in textInput and perform a search.
	 */
	protected void aButtonAction()
	{
		if (controller == null) return;
		controller.aButtonAction();
	}
	

	/**
	 * Performs an action when the user clicks the enterButton. Usually,
	 * this method would call getABInputText() and process the text
	 * that the user has entered in the text field.	 
	 * A subclass could define this as an "add" button, to 
	 * read the text in textInput and process it, like add
	 * to a collection.
	 */
	protected void bButtonAction()
	{
		if (controller == null) return;
		controller.bButtonAction();
	}
	

	/**
	 * Performs an action when the user clicks the up button.
	 */
	protected void upButtonAction()
	{
		if (controller == null) return;
		controller.upButtonAction();
	}
	
	
	/**
	 * Performs an action when the user clicks the down button.
	 */
	protected void downButtonAction()
	{
		if (controller == null) return;
		controller.downButtonAction();
	}
	
	
	/**
	 * Performs an action when the user clicks the right button.
	 */
	protected void rightButtonAction()
	{
		if (controller == null) return;
		controller.rightButtonAction();
	}
	
	
	/**
	 * Performs an action when the user clicks the left button.
	 */
	protected void leftButtonAction()
	{
		if (controller == null) return;
		controller.leftButtonAction();
	}
	

	/**
	 * Performs an action when the user clicks button 1.
	 */
	protected void button1Action()
	{
		if (controller == null) return;
		controller.button1Action();
	}
	

	/**
	 * Performs an action when the user clicks button 2.
	 */
	protected void button2Action()
	{
		if (controller == null) return;
		controller.button2Action();
	}
	

	/**
	 * Performs an action when the user clicks button 3.
	 */
	protected void button3Action()
	{
		if (controller == null) return;
		controller.button3Action();
	}
	

	/**
	 * Performs an action when the user clicks button 4.
	 */
	protected void button4Action()
	{
		if (controller == null) return;
		controller.button4Action();
	}
	
	
	/**
	 * Sets the monospace attribute for the output text area.  
	 * Helpful for lining up text vertically.
	 * @param b true sets to monotype, false sets to default font.
	 */
	public void setMonospaceFont(boolean b)
	{
		
		if (b)			// true: set monotype font
		{
			Font mono = new Font("Monospaced", Font.PLAIN, 12);
			textArea.setFont(mono);			
		}
		else			// false: set default font
		{
			textArea.setFont(originalFont);
		}
	}
		
	// set text functions - redefine text on a button

	/**
	 * Redefines aButton's text.
	 * @param s Text to replace the default 'aButton'.
	 */
	public void setAButtonText(Object s)
	{
		aButton.setText(s.toString());
	}

	/**
	 * Redefines bButton's text.
	 * @param s Text to replace the default 'bButton'.
	 */
	public void setBButtonText(Object s)
	{
		bButton.setText(s.toString());
	}

	/**
	 * Redefines upButton's text.
	 * @param s Text to replace the default 'up'.
	 */
	public void setUpButtonText(Object s)
	{
		upButton.setText(s.toString());
	}

	/**
	 * Redefines rightButton's text.
	 * @param s Text to replace the default 'right'.
	 */
	public void setRightButtonText(Object s)
	{
		rightButton.setText(s.toString());
	}

	/**
	 * Redefines leftButton's text.
	 * @param s Text to replace the default 'left'.
	 */
	public void setLeftButtonText(Object s)
	{
		leftButton.setText(s.toString());
	}

	/**
	 * Redefines downButton's text.
	 * @param s Text to replace the default 'down'.
	 */
	public void setDownButtonText(Object s)
	{
		downButton.setText(s.toString());
	}

	/**
	 * Redefines Button1's text.
	 * @param s Text to replace the default "Button1".
	 */
	public void setButton1Text(Object s)
	{
		button1.setText(s.toString());
	}

	/**
	 * Redefines Button2's text.
	 * @param s Text to replace the default "Button2".
	 */
	public void setButton2Text(Object s)
	{
		button2.setText(s.toString());
	}

	/**
	 * Redefines Button3's text.
	 * @param s Text to replace the default "Button3".
	 */
	public void setButton3Text(Object s)
	{
		button3.setText(s.toString());
	}

	/**
	 * Redefines Button4's text.
	 * @param s Text to replace the default "Button4".
	 */
	public void setButton4Text(Object s)
	{
		button4.setText(s.toString());
	}

	// Enable functions - enable/disable buttons
	
	/**
	 * Enable or disable  clearButton
	 * @param b true = enable, false=disable
	 */
	public void enableAButton(boolean b)
	{
		aButton.setEnabled(b);
	}

	/**
	 * Enable or disable enterButton
	 * @param b true = enable, false=disable
	 */
	public void enableBButton(boolean b)
	{
		bButton.setEnabled(b);
	}

	/**
	 * Enable or disable the up button
	 * @param b true = enable, false=disable
	 */
	public void enableUpButton(boolean b)
	{
		upButton.setEnabled(b);
	}

	/**
	 * Enable or disable the right button
	 * @param b true = enable, false=disable
	 */
	public void enableRightButton(boolean b)
	{
		rightButton.setEnabled(b);
	}

	/**
	 * Enable or disable the down button
	 * @param b true = enable, false=disable
	 */
	public void enableDownButton(boolean b)
	{
		downButton.setEnabled(b);
	}

	/**
	 * Enable or disable the left button
	 * @param b true = enable, false=disable
	 */
	public void enableLeftButton(boolean b)
	{
		leftButton.setEnabled(b);
	}

	/**
	 * Enable or disable Button1.
	 * @param b true = enable, false=disable
	 */
	public void enableButton1(boolean b)
	{
		button1.setEnabled(b);
	}

	/**
	 * Enable or disable Button2.
	 * @param b true = enable, false=disable
	 */
	public void enableButton2(boolean b)
	{
		button2.setEnabled(b);
	}

	/**
	 * Enable or disable Button3.
	 * @param b true = enable, false=disable
	 */
	public void enableButton3(boolean b)
	{
		button3.setEnabled(b);
	}

	/**
	 * Enable or disable Button4.
	 * @param b true = enable, false=disable
	 */
	public void enableButton4(boolean b)
	{
		button4.setEnabled(b);
	}

	// Set buttons visible or invisible.

	/**
	 * Make aButton visible/invisible.
	 * @param b true=make visible, false=make invisible
	 */
	public void setVisibleAButton(boolean b)
	{
		aButton.setVisible(b);
	}

	/**
	 * Make bButton visible/invisible.
	 * @param b true=make visible, false=make invisible
	 */
	public void setVisibleBButton(boolean b)
	{
		bButton.setVisible(b);
	}

	/**
	 * Make the up button visible/invisible.
	 * @param b true=make visible, false=make invisible
	 */
	public void setVisibleUpButton(boolean b)
	{
		upButton.setVisible(b);
	}

	/**
	 * Make the right button visible/invisible.
	 * @param b true=make visible, false=make invisible
	 */
	public void setVisibleRightButton(boolean b)
	{
		rightButton.setVisible(b);
	}

	/**
	 * Make the down button visible/invisible.
	 * @param b true=make visible, false=make invisible
	 */
	public void setVisibleDownButton(boolean b)
	{
		downButton.setVisible(b);
	}

	/**
	 * Make the left button visible/invisible.
	 * @param b true=make visible, false=make invisible
	 */
	public void setVisibleLeftButton(boolean b)
	{
		leftButton.setVisible(b);
	}

	/**
	 * Make the panel containing a and b buttons visible/invisible.
	 * @param b true=make visible, false=make invisible
	 */
	public void setVisibleABPanel(boolean b)
	{
		abPanel.setVisible(b);
	}
	
	/**
	 * Make the panel containing the input text field visible/invisible.
	 * @param b true=make visible, false=make invisible
	 */
	public void setVisibleInputPanel(boolean b)
	{
		inputPanel.setVisible(b);
		pack();
	}
	
	/**
	 * Make the panel containing cursor buttons visible/invisible.
	 * @param b true=make visible, false=make invisible
	 */
	public void setVisibleCursorPanel(boolean b)
	{
		cursorPanel.setVisible(b);
		pack();
	}
	
	/**
	 * Make the panel containing four buttons visible/invisible.
	 * @param b true=make visible, false=make invisible
	 */
	public void setVisibleCommandPanel(boolean b)
	{
		commandPanel.setVisible(b);
		pack();
	}
	
	/**
	 * Make Button1 visible/invisible.
	 * @param b true=make visible, false=make invisible
	 */
	public void setVisibleButton1(boolean b)
	{
		button1.setVisible(b);
	}

	/**
	 * Make Button2 visible/invisible.
	 * @param b true=make visible, false=make invisible
	 */
	public void setVisibleButton2(boolean b)
	{
		button2.setVisible(b);
	}

	/**
	 * Make Button3 visible/invisible.
	 * @param b true=make visible, false=make invisible
	 */
	public void setVisibleButton3(boolean b)
	{
		button3.setVisible(b);
	}

	/**
	 * Make Button4 visible/invisible.
	 * @param b true=make visible, false=make invisible
	 */
	public void setVisibleButton4(boolean b)
	{
		button4.setVisible(b);
	}

	/**
	 * Make the text panel visible/invisible.
	 * @param b true=make visible, false=make invisible
	 */	
	public void setVisibleTextPanel(boolean b)
	{
		textPanel.setVisible(b);
		//pack();
		setMinimumSize( new Dimension(0,0));
		pack();
	}
	
	/**
	 * Display text in the text area. Erases old text.
	 * @param s Text to display in the text area.
	 */
	public void setTextArea(Object s)
	{
		textArea.setText(s.toString());
	}
	
	/**
	 * Append text to the text area. Use "\n" to insert new line.
	 * @param s Text to append to the text area.
	 */
	public void appendTextArea(Object s)
	{
		textArea.append(s.toString());
		textArea.setCaretPosition(textArea.getDocument().getLength() ); 
	}

	/**
	 * Get the text currently displayed in the text area. Does not affect displayed text.
	 * @return the String displayed in the text area.
	 */
	public String getTextArea()
	{
		return textArea.getText();
	}

	/**
	 * Get the user's input from the "ab" text input line.  This method could be
	 * called when the user presses one of the a-b buttons to process the text.
	 * When called, the text is deleted from the text field.
	 * @return the user's input text.  Return "" if none has been entered.
	 */
	public String getABInputText()
	{
		String tmp = abTextInput.getText();
		abTextInput.setText("");
		return tmp;	
	}
	
	/**
	 * Display text in the textInput field 
	 * @param s the text to display
	 */
	public void setABTextInput(String s)
	{
		abTextInput.setText(s);
	}


	//-------- methods called by controller------------
	
	public void terminate()
	{
		System.exit( 0 );
	}
	
	
	/**
	 * In MVC, a controller is needed to manipulate this view object.  The controller should be
	 * instantiated as a subclass of SLController and passed to the view using this
	 * method.  main() could also call this to set up the links between model, view, and controller.
	 * 
	 * @param c a subclass of SLController
	 */
	public void registerController(SLController c)
	{
		controller = c;
	}
	
	/**
	 * Write a String to a button on the button grid.
	 * 
	 * @param str to display on the button
	 * @param row of button in the grid (starting with offset 0)
	 * @param column of button in the grid (starting with offset 0)
	 */
	public void setGridButtonText(String str, int row, int col)
	{
		if (useGridButton)
			gridButton[row][col].setText(str);
	}
	
	/**
	 * Get the text currently written on the button.
	 * 
	 * @param row of button in the grid (starting with offset 0)
	 * @param column of button in the grid (starting with offset 0)
	 * @return the string on the button, or the empty string, "", if button grid is not used.
	 */
	public String getGridButtonText(int row, int col)
	{
		if (useGridButton)
			return gridButton[row][col].getText();
		else
			return "";
	}
	
	/**
	 * Set the Foreground color of a button on the button grid.
	 * 
	 * @param color of the text on the button
	 * @param row of button in the grid (starting with offset 0)
	 * @param column of button in the grid (starting with offset 0)
	 */
	public void setGridButtonForeground(Color color, int row, int col)
	{
		if (useGridButton)
			gridButton[row][col].setForeground(color);
	}
	
	/**
	 * Return the Color of the text on the button.
	 * (Note: some platforms do not permit changing a button color, hence
	 * this feature is not provided.)
	 * @param row of the button in the grid
	 * @param col of the button in the grid
	 * @return the Color of the text, or nul if the button grid is not used.
	 */
	public Color getGridButtonForeground(int row, int col)
	{
		if (useGridButton)
			return gridButton[row][col].getForeground();
		else
			return null;
	}
	
//======================= test program for this class =======================

	
	/**
	 * A demo program that just displays the GUI.
	 */
	public static void main(String[] args)
	{
		// Note:  This sample class only uses SLView, not the other two components, model and controller.
		//        Clicking buttons or entering text has no effect outside SLView.
		//        When all three components are used, then they must be properly registered. Also, 
		//        recall that SLModel and SLController cannot be used, subclass for each must be defined.
		// Example:  Assuming two subclasses ARE defined:  Model and Controller, then the following
		//        shows how they are to be set up in main().  Assume that view is instantiated from SLView:
		//
		// SLView       view = new SLVew(......);
		// Controller 	controller = new Controller();
		// Model  		model = new Model();
		// view.registerController( controller );	// view has reference to controller.
		// controller.registerView( view );		// controller has references to view and model
		// controller.registerModel(model);
		// model.registerController(controller);	// model has reference to controller (optional)
		//
		// Note:  At times a model only reacts to method calls from controller.  In such cases, there is
		//        no need to establish a reference from model to controller, since the methods can return
		//        values to controller.

		// The code below displays all components of the GUI.
		
		System.out.println(version);		// This is optional

		SLView adv = new SLView("Virtual Computer", 20, 20,40,20);   // use something like 1, 20 for a row of boxes
		adv.setTextArea("The model's output.\n\n");
		
		// The following two lines show how you can make things invisible if needed.
		//adv.setVisibleButton2(false);
		//adv.setVisibleTextPanel(false);
		
		adv.setGridButtonText("X", 0, 2);
		adv.setGridButtonText("O", 2, 5);
		adv.setGridButtonForeground(Color.RED, 2, 5);

		// Note: on some platforms, like OS/X, button background color cannot be changed from default.
		// Thus background color is not supported in this class.
	}
}
