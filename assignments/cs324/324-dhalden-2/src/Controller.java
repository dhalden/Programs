
/**
 * The controller class now has 3 main classes. The first, is the start button
 * The second, is the set action.
 * The third, is the mentionWaiting action.
 * @author Derek Halden
 *
 */
public class Controller extends SLController {


	/**
	 *  Runs the program
	 */
	@Override
	//start button
	public void button1Action() {
		CarQSemaphore q = new CarQSemaphore(0,10);
		Arrivals arrs = new Arrivals((Model)model, q);
		Departures deps = new Departures((Model)model, q);
		arrs.start();
		deps.start();
		view.setVisibleButton1(false);
		view.setVisibleCommandPanel(false);
	}
	/**
	 * @param col The column of the button that needs to change
	 * @param id the string that the button needs to change to.
	 */
	public synchronized void set(int col, String id)
	{
		view.setGridButtonText(id, 0, col);
	}
	/**
	 * * @param str The string for the thread that is having to wait
	 */
	public synchronized void mentionWaiting(String str)
	{
		view.appendTextArea(str + " was made to wait\n");
	}

	@Override
	public void gridButtonAction(int r, int c) {
		System.out.print(r + " " + c);
	}
	@Override
	public void inputTextAction(String input) {
		// TODO Auto-generated method stub
		
	}
	@Override
	public void aButtonAction() {
		// TODO Auto-generated method stub
		
	}
	@Override
	public void bButtonAction() {
		// TODO Auto-generated method stub
		
	}
	@Override
	public void upButtonAction() {
		// TODO Auto-generated method stub
		
	}
	@Override
	public void downButtonAction() {
		// TODO Auto-generated method stub
		
	}
	@Override
	public void rightButtonAction() {
		// TODO Auto-generated method stub
		
	}
	@Override
	public void leftButtonAction() {
		// TODO Auto-generated method stub
		
	}
	@Override
	public void button2Action() {
		// TODO Auto-generated method stub
		
	}
	@Override
	public void button3Action() {
		// TODO Auto-generated method stub
		
	}
	@Override
	public void button4Action() {
		// TODO Auto-generated method stub
		
	}

}
