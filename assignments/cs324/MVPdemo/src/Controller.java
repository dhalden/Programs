
/**
 * This is an example of a subclass of SLController.  Controller uses just a few buttons
 * in the view (and does not use the button grid).  The user can ...
 * 1) enter text in the abPanel and press the aButton to move text to the text area.
 * 2) press the up button to copy the string in the model to the text area.
 * 3) press the down button to copy the string in the text area to the model.
 * 4) press button1 to tell the model to copy its text to the text area. (Similar to 2, but it is
 *    the model that manages the copy, whereas in (2), the controller manages the copy.)
 *    
 * @author Pierre von Kaenel
 *
 */
public class Controller extends SLController {

	@Override
	public void inputTextAction(String input) {
	}

	@Override
	public void aButtonAction() {
		// read the entry box
		String s = view.getABInputText();
		view.setTextArea(s);
		view.setABTextInput("");
		if (s == null)
			System.out.println("null");
		if (s.equals(""))
				System.out.println("empty string");
	}

	@Override
	public void bButtonAction() {
	}

	@Override
	public void upButtonAction() {
		String str = ((Model)model).getString();	// Note the type cast - this is important.
		view.setTextArea(str);
	}

	@Override
	public void downButtonAction() {
		String str = view.getTextArea();
		((Model)model).setString(str);

	}

	@Override
	public void rightButtonAction() {
	}

	@Override
	public void leftButtonAction() {
	}

	@Override
	public void button1Action() {
		// This is the button that the user presses in order to force Model to
		// write it's string.
		((Model)model).writeString();

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

	/**
	 * The methods above are called by SLView.  But passStringToView() is called by Model.
	 * @param s the string to print to the text area in SLView.
	 */
	public void passStringToView(String s)
	{
		view.setTextArea(s);
	}
}
