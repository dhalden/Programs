/**
 * This thread increments an internal counter from 1 to 20 and displays the current value in a
 * JLabel that appears in EWNSframe, a JFrame.
 * 
 * @author P. von Kaenel
 *
 */
public class CounterThread extends JLabelThread {

	int value;				// keeps track of the count
	
	/**
	 * Initialize the count to 0.
	 * @param disp a JLabel that is part of the GUI output
	 */
	public CounterThread()
	{
		//super();
		value =0;		//initially no people have entered
	}
	
	/* (non-Javadoc)
	 * @see java.lang.Thread#run()
	 * 
	 * Increment the counter every half second and display the current count in the JLabel.
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
				 * A variation could be used in which each turnstile is given
				 * the sleep parameter via its constructor.
				 */
				Thread.sleep(500);
				value++;
				myDisplay.setText(Integer.toString(value));
				
			}
			
		}catch(Exception e)
		{
			//don't do anything if something goes wrong
		}
	}
}
