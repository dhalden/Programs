
/**
 * This is a sample Main class that uses the Skidmore MVC library along with custom controller and
 * model classes that are subclassed from SLController and SLModel, respectively.  Note that main()
 * defines a view that does not include the grid of buttons.
 * 
 * Another example of a main() method is found in SLView.  That example includes the button grid.
 *
 * * @author Pierre von Kaenel
 */
public class Main {

	/**
	 * This is the main method of the project and and it begins the project's execution.
	 * 
	 * Reminder: Main, Model, and Controller form a demo program.  Students may use these
	 * classes as a starting point for a new project.  When this is done, the code below that
	 * appears after the "//----------- The code below defines .... --------" comment should 
	 * be deleted and replaced by code that defines the view needed by the new project.
	 * 
	 * @param args
	 */
	public static void main(String[] args) {

		int size = 10;
		SLView view = new SLView("Ball Bounce", 1, size,40,20);   // use something like 1, 20 for a row of boxes
		Controller 	controller = new Controller(size);
		Model  		model = new Model(size);
		
		view.registerController( controller );	// view has reference to controller.
		
		controller.registerView( view );		// controller has references to view and model.
		controller.registerModel(model);
		
		model.registerController(controller);	// model has reference to controller.


		//-------------- The code below defines the design of the view -----------------
		// If a prototype of a view was defined in SLView.main(), the that code should be copied
		// into the area below.

		view.setVisibleABPanel(false);
		view.setVisibleCursorPanel(false);
		view.setVisibleInputPanel(false);
		view.setVisibleTextPanel(false);
		view.setVisibleButton2(false);
		view.setVisibleButton3(false);
		view.setVisibleButton4(false);

		view.setButton1Text("Start Thread");
	}
}
