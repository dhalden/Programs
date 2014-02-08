/**
 * This project demonstrates the use of Threads.  Two threads are
 * created and each begins incrementing a counter.  The count
 * values are displayed in the main frame.  Also, a counter is used
 * to sum the two counting threads.  Uncomment one of the declarations
 * of gcounter to demonstrate interference or mutual exclusion.
 * 
 * @author P. von Kaenel
 * Derek Halden
 *
 */
public class Main {
	
	/**
	 * Create a Frame and make it visible. Run two counting threads.
	 * A global counter either sums the counters correctly or not,
	 * depending on whether mutual exclusion is used or not.
	 * @param args
	 */
	public static void main(String[] args)
	{
		GlobalCounter gcounter = new GlobalCounter();
		
        CounterThread westThread = new CounterThread(gcounter);
        CounterThread eastThread = new CounterThread(gcounter);
        
        EWNSframe mainFrame = new EWNSframe(westThread, gcounter, eastThread);
        mainFrame.setNorthTitle("Two threads counting");
        mainFrame.setEastTitle("Thread 2");
        mainFrame.setWestTitle("Thread 1");
        mainFrame.setCenterTitle("Total");
        
        mainFrame.setVisible(true);
	}
}
