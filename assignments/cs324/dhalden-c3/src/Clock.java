
public class Clock extends Thread {
	private long lastTime;
	private PSignal ps;
	private Event ev;
	
	public Clock(PSignal s, Event e)
	{
		lastTime = System.currentTimeMillis();
		ps = s;
		ev = e;
	}
	
	public void run()
	{
	
		while (true)
		{

			try {
				ev.await(Event.EventState.UP);
				
			} catch (InterruptedException e) {}
			
			 long time = System.currentTimeMillis();
			 if (time - lastTime > 2000)
			 {
				 lastTime = time;
				 ps.send();
			 }
		}
	} //run

}
