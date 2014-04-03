
public class Main {

	/**
	 * Sets up the threads and starts them.  Waiters wait for clock signals.
	 * main will let the clock work for 6 seconds, then pause it before starting
	 * it up again and finally stopping it.  Read code below.
	 * @param args
	 */
	public static void main(String[] args) {
		PSignal ps = new PSignal();
		Event ev = new Event(Event.EventState.UP);
		Clock c = new Clock(ps, ev);
		Waiter w1, w2, w3;
		w1 = new Waiter(ps);
		w2 = new Waiter(ps);
		w3 = new Waiter(ps);

		w1.start();
		w2.start();
		w3.start();
		c.start();
		System.out.println("clock and waiters have been started");
		try {
			Thread.sleep(6000);		// wait 6 seconds before stopping clock
			ev.reset();
			Thread.sleep(8000);		// keep clock stopped for 8 seconds, then...
			ev.set();				// start the clock again.
			Thread.sleep(6000);		// wait 6 more seconds...
			ev.reset();				// stop the clock
		} catch (InterruptedException e) {}
		System.out.println("The End");

	}

}
