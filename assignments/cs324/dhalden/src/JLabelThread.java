import javax.swing.JLabel;


/**
 * This abstract thread is linked to a JLabel in some external GUI class.  The class must be
 * extended to provide a meaningful run method.  The thread is started by the GUI class, thus
 * the usual setup in a main method is to first instantiate a JLabelThread subclass, pass a
 * reference of itself to the GUI class which calls setDisplay() to give JLabelThread
 * a reference to the JLabel.
 * 
 * @author P. von Kaenel
 *
 */
public abstract class JLabelThread extends Thread 
{
	JLabel myDisplay;		// write the count to a JLabel
	
	/**
	 * Initialize the JLabel to null.
	 */
	public JLabelThread()
	{
		myDisplay = null;
	}
	
	/* (non-Javadoc)
	 * @see java.lang.Thread#run()
	 * 
	 * Must be overridden by a subclass.
	 */
	public abstract void run();
	
	/**
	 * Define the JLabel that is accessed for output.
	 * @param disp The JLabel.
	 */
	public void setDisplay(JLabel disp)
	{
		myDisplay = disp;
	}
}
