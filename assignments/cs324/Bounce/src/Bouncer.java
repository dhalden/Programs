/**
 * A lab exercise.
 * @author pvonk
 *
 */
public class Bouncer extends Thread {

	private int	size;
	private Model model;
	private static int nextid = 0;
	private int id;
	
	/**
	 * 
	 */
	public Bouncer(Model m, int s) {
		model = m;
		size = s;
		id = nextid;
	}
	

	public int getTid() {
		return id;
	}

	public void run()
	{
		try{

			while (true)
			{
				Thread.sleep(500);		// The ball moves smoothly.
				
				// If the model knows that the ball is toast, then this is where
				// you can use a "break"
				
				
				// Now for the ball's movement.
				
				int col = model.getCol();
				int dir = model.getDirection();
				int nextCol = col+dir;

				if (nextCol < 0 || nextCol > size-1)
				{
					// change direction
					dir = -dir;
					nextCol = col+dir;
				}
				
				// debug: print col and dir
//				System.out.println("col: "+col+"   dir: "+dir+"    nextCol: "+nextCol);
				

				// make the change in the model
				model.setCol(id, nextCol);
				model.setDirection(id, dir);
				
			}
			
		}catch(Exception e)
		{
			//don't do anything if something goes wrong
		}
	}



}
