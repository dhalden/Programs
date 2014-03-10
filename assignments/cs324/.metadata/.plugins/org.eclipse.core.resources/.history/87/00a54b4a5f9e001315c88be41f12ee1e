
public class Bomb extends Thread {

	private int	size;
	private Model model;
	private Controller controller;
	private int id;
	private int loc;
	
	/**
	 * 
	 */
	public Bomb(Model m, Controller c, int s) {
		model = m;
		size = s;
		id = 1;
		loc = size-2;
	}
	

	public int getTid() {
		return id;
	}
	
	public void run()
	{
		try{

			while (true)
			{
				Thread.sleep(200);
				
				// Blow up the ball if it enters the bomb's cell.  To do this,
				// you need to tell the model that it must tell the controller 
				// to write this thread's id to the grid in the bomb's cell, then
				// tell the model that the ball is toast.  (The ball checks with the
				// model about this periodically.)
				
				
				
			}
			
		}catch(Exception e)
		{
			//don't do anything if something goes wrong
		}
	}


}
