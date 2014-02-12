
/**
 * Controller used in Checkoff #2.
 *    
 * @author Derek Halden
 *
 */
public class Controller extends SLController {

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
		view.setGridButtonText(" ", 0, ((Model)model).getLoc());
		view.setGridButtonText("X", 0, ((Model)model).goRight());
	}

	@Override
	public void leftButtonAction() {
		view.setGridButtonText(" ", 0, ((Model)model).getLoc());
		view.setGridButtonText("X", 0, ((Model)model).goLeft());
	}

	@Override
	public void button1Action() {
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
		view.setGridButtonText(" ", 0, ((Model)model).getLoc());
		view.setGridButtonText("X", r, c);
		((Model)model).setLoc(c);
	}

}