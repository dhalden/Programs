/**
 * @author Derek Halden
 *
 */
public class CarQSemaphore {
	private int q;
	private int maxcarqueue;
	private int initq;
	
	
	/**
	 * @param initqu The starting number of cars in the gas station
	 * @param maxcars The most cars that the gas station can have at one time.
	 */
	public CarQSemaphore(int initqu, int maxcars)
	{
		q = initqu;
		initq = initqu;
		maxcarqueue=maxcars;
		
	}
	/**
	 * @return the current value of q
	 */
	public synchronized int getq()
	{
		return q;
	}
	
	/**
	 * @return whether or not there is space in the gas station
	 */
	public synchronized boolean arrival()
	{
		if(q < maxcarqueue)
		{
			q++;
			return true;
		}
		else
		{
			return false;
		}
	}
	
	/**
	 * @return whether or not the gas station is empty
	 */
	public synchronized boolean departure()
	{
		if(q > initq)
		{
			q--;
			return true;
		}
		else
		{
			return false;
		}
	}

}
