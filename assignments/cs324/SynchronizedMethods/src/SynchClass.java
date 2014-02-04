
public class SynchClass {

	public synchronized void sayHi() {
		try {
			Thread.sleep(5000);				// wait 5 seconds
		} catch (InterruptedException e) {

		}	
		System.out.println("Hi, after 5 seconds");
	}
	
	public synchronized void sayBye() {
		// this will say Bye right away
		
		System.out.println("Bye, right now");
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		SynchClass sc = new SynchClass();
		SayHi sh = new SayHi(sc);
		SayBye sb = new SayBye(sc);
		sh.start();
		try {
			Thread.sleep(1000);				// wait 5 seconds
		} catch (InterruptedException e) {

		}	
		sb.start();

	}

}
