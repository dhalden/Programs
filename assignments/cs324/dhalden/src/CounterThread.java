/**
 * This thread increments an internal counter from 1 to 20 and displays the current value in a
 * JLabel that appears in EWNSframe, a JFrame.  When incrementing the internal counter, it also
 * increments a global (external) counter used by multiple CounterThread objects.
 * 
 * @author P. von Kaenel
  * <STUDENT, ADD YOUR NAME HERE>
 *
 */
public class CounterThread extends JLabelThread {

	GlobalCounter myCounter;	// global (external) counter
	int value;					// internal counter
	
	/**
	 * Initialize the count to 0.
	 * @param ct The global counter.
	 */
	public CounterThread(GlobalCounter ct)
	{
		//super();
		myCounter = ct;
		value =0;
	}
	
	/* (non-Javadoc)
	 * @see java.lang.Thread#run()
	 * 
	 * Increment the counter every half second and display the current count in the JLabel.
	 * Also increment the global counter.
	 */
	public void run()
	{
		try{
			//Loop until the max (20) has been reached
			for(int i=1;i<=20;i++)
			{
				/*
				 * 
				 * Sleep for half a second, to slow down the incrementing
				 * then increase the value.
				 * Finally, update the display with the new value.
				 * 
				 */
				Thread.sleep(500);
				value++;
				myCounter.inc();
				myDisplay.setText(Integer.toString(value));
				
			}
			
		}catch(Exception e)
		{
			//don't do anything if something goes wrong
		}
	}
}
