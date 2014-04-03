import java.util.ArrayList;

/**
 * PSignal is used by Clock to signal the Waiter threads that a clock tick has
 * occurred. The heart of the signaling algorithm is in waitS().
 * @author P. von Kaenel
 *
 */
public class PSignal {
	private boolean started;
	private ArrayList<Waiter> receivedSignal;

	/**
	 * Constructor creates an ArrayList to store Waiters.  
	 * Also, a boolean that indicates the PSignal hasn't yet been
	 * activated is set.
	 */
	public PSignal() {
		receivedSignal = new ArrayList<Waiter>();
		started = false;
	}

	/**
	 * Threads that have already received the signal are put in a wait
	 * state.  New signals clear the ArrayList of Waiters that have received
	 * the signal, so waiting threads are released and are added to
	 * the ArrayList.
	 * 
	 * @throws InterruptedException
	 */
	public synchronized void waitS() throws InterruptedException {
		Waiter w = (Waiter) Thread.currentThread();

		while (receivedSignal.contains(w) || !started)
			wait();
		receivedSignal.add(w);
	}

	/**
	 * This sends the signal. The list of Waiters that received the signal
	 * is cleared. 
	 */
	public synchronized void send() {
		started = true;
		receivedSignal.clear();
		notifyAll();
	}
}
