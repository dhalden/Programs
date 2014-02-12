
/**
 * Checkoff #2: moving a character on the grid left/right using buttons.
 * 
 * @author Derek Halden
 */
public class Main {

	/**
	 * This is the main method of the project and and it begins the project's execution.
	 * 
	 * @param args
	 */
	public static void main(String[] args) {
		SLView view = new SLView("Virtual Computer", 1, 5,60,20);   // use something like 1, 20 for a row of boxes
		Controller 	controller = new Controller();
		Model  		model = new Model();
		
		view.registerController( controller );	// view has reference to controller.
		
		controller.registerView( view );		// controller has references to view and model.
		controller.registerModel(model);
		
		model.registerController(controller);	// model has reference to controller. May not be needed.

		view.setTextArea("Demo.\n\n");
		
		// Remove panels that are not needed.
		view.setVisibleABPanel(false);
		view.setVisibleCommandPanel(false);
		view.setVisibleTextPanel(false);
		view.setVisibleInputPanel(false);
		view.setVisibleUpButton(false);
		view.setVisibleDownButton(false);
		
		view.setGridButtonText("X", 0, 0);
	}
}
