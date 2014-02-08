/**
 * A counter that is accessed by other threads.
 * 
 * @author P. von Kaenel
  * <STUDENT, ADD YOUR NAME HERE>
 *
 */
public class GlobalCounter extends JLabelThread
{
	int count;			// The counter
	
	 /**
	 * Constructor sets the counter to 0 and the JLabel to null;
	 */
	public GlobalCounter()
	 {
	 	count = 0;
	 }	
	
	/**
	 * Does nothing.
	 */
	public void run()
	{
	}
	
	 /**
	 * The counter value is displayed in a JLabel after incremented.
	 * CHANGE MADE HERE!
	 */
	public synchronized void  inc()
	 {
	 	int temp = count;
	 	Simulate.simInterrupt();	// DO NOT REMOVE THIS!
	 	count = temp +1;
	 	if (myDisplay != null)
	 		myDisplay.setText(Integer.toString(count));
	 }	
}