/**
 * 
 * @author Derek Halden
 * 
 */
public class Arrivals extends Thread {
	private int totalCars;
	private Model model;
	private CarQSemaphore q;

	/**
	 * 
	 * @param m the model required for accessing the controller/view
	 * @param queue a semaphore-like variable, that tells arrivals when there is room for cars, or when it needs to wait. 
	 */
	public Arrivals(Model m, CarQSemaphore queue) {
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
	public void run() {
		// System.out.print("this happens\n");
		while (true) {
			int r = (int) (Math.random() * 1000);
			try {
				Thread.sleep(r);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			// check for available space in gas station
			synchronized (q) {
				while (!q.arrival()) {

					try {
						model.mtw("Arrivals");
						q.wait();
					} catch (InterruptedException e) {
						e.printStackTrace();

					}

				}
				// when space is available, increment total cars
				model.setCol(totalCars, "C");
				totalCars = (totalCars + 1) % 10;
				// let Departures know that there is now a car for it to get rid
				// of.
				q.notifyAll();
			}

		}
	}

}
