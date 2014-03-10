
/**
 * This is the controller for the bouncing ball project.  The model tells the controller
 * when a new location for the bouncing ball has been calculated by the thread, Bouncer.
 *    
 * @author Pierre von Kaenel
 *
 */
public class Controller extends SLController {

	private int 	size;
	private Bouncer bouncer;
	
	public Controller(int size) {
		this.size = size;
	}
	
	public void move(int id, int oldCol, int newCol)
	{
		view.setGridButtonText(" ", 0, oldCol);
		view.setGridButtonText(""+id, 0, newCol);
	}
	
	@Override
	public void inputTextAction(String input) {
	}

	@Override
	public void aButtonAction() {
	}

	@Override
	public void bButtonAction() {
	}

	@Override
	public void upButtonAction() {
	}

	@Override
	public void downButtonAction() {
	}

	@Override
	public void rightButtonAction() {
	}

	@Override
	public void leftButtonAction() {
	}

	@Override
	public void button1Action() {
		// This is the button that starts a new thread

		bouncer = new Bouncer((Model)model, size);
		int id = bouncer.getTid();
		
		view.setGridButtonText(""+id, 0, 0);
		((Model)model).setCol(id, 0);
		((Model)model).setDirection(id, 1);

		
		bouncer.start();
	}

	@Override
	public void button2Action() {
	}

	@Override
	public void button3Action() {
	}

	@Override
	public void button4Action() {
	}

	@Override
	public void gridButtonAction(int r, int c) {
	}


}
