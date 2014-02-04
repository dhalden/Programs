/**
 * This project demonstrates the use of Threads.  Two threads are
 * created and each begins incrementing a counter.  The counter
 * values are displayed in the main frame.
 * 
 * @author P. von Kaenel
 *
 */
public class Main {
	
	/**
	 * Create a JFrame and make it visible, thus running the program.
	 * @param args
	 */
	public static void main(String[] args)
	{
        CounterThread westThread = new CounterThread();
        CounterThread eastThread = new CounterThread();
        
        eastThread.setPriority(10);
        EWNSframe mainFrame = new EWNSframe(westThread, null, eastThread);
        mainFrame.setNorthTitle("Two threads counting");
        mainFrame.setEastTitle("Thread 2");
        mainFrame.setWestTitle("Thread 1");
        mainFrame.setCenterTitle(" ");
        
        mainFrame.setVisible(true);
	}
}
