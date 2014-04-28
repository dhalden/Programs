
public class Departures extends Thread {
	private int totalCars;
	private Model model;
	private CarQSemaphore q;
	
	/**
	 * 
	 * @param m the model required for accessing the controller/view
	 * @param queue a semaphore-like variable, that tells departures when are cars, or when it needs to wait. 
	 */
	public Departures(Model m, CarQSemaphore queue)
	{
		model = m;
		totalCars = 0;
		q = queue;
	}
	/**
	 *
	 * Method that runs an infinite while loop, and determines when
	 * New cars have a space, or don't.
	 * 
	 */
	public void run()
	{
		while(true)
		{
		//System.out.print("this also happens\n");
		int r = (int)(Math.random()*1000);
		try {
			Thread.sleep(r);
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		//check for available space in gas station
		synchronized(q)
		{	
		while(!q.departure())
		{

			try {
			//if there are no cars, then it should wait for a car to arrive
				model.mtw("Departures");
				q.wait();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		
		//when space is available, remove a car, and move on to the next car
		model.setCol(totalCars," ");
		totalCars = (totalCars + 1)%10;
		//let Arrivals know that there is now an empty space to put a car in.
			q.notifyAll();
		}
	}
	}
}