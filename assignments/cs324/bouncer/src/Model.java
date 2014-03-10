
/**
 * The model stores the program's data: location of the bouncing ball and direction
 * of movement.  +1 goes to the right, -1 goes to the left.
 * The scaffolding for multiple bouncers has been put in place.
 *
 * * @author Pierre von Kaenel
 */
public class Model extends SLModel {

	private int size;
	private int col;		// the location of the ball
	private int direction;
	

	public Model(int size) {
		this.size = size;
		col = 0;
		direction = 1;
	}

	// Aside from the methods below, more will be needed to finish the bomb effect.
	// The bomb lets the model know when the bomb goes off (we want to see the
	// bomb's id appear in the grid) and that the bouncing ball needs to stop.
	
	
	
	
	// So, here are the methods that have nothing to do with the bomb.
	
	public int getDirection() {
		return direction;
	}



	public void setDirection(int id, int direction) {
		this.direction = direction;
	}



	public int getCol() {
		return col;
	}



	public void setCol(int id, int col) {
		int oldCol = this.col;
		this.col = col;
		((Controller)controller).move(id, oldCol, col);
	}

}
