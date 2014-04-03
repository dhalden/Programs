
public class Waiter extends Thread {
	private PSignal ps;
	
	public Waiter(PSignal s)
	{
		ps = s;
	}
	
	public void run()
	{
		
		while (true)
		{
			try {
				ps.waitS();
				
			} catch (InterruptedException e) {}
			System.out.println(getName()+"  " +System.currentTimeMillis());		
		}
	}
}
