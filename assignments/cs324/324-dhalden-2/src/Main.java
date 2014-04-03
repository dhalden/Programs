
/**
 *
 * * @author Derek Halden
 */
public class Main {

	/**
	 * Sets up a Model View and Controller, which can then be used to
	 * simulate cars coming and going from a gas station
	 * @param args 
	 */
	public static void main(String[] args) {
		SLView		view = new SLView("Gas Station",1, 10, 60,40);	// This version of constructor excludes button grid.
		Controller 	controller = new Controller();
		Model  		model = new Model();
		
		view.registerController( controller );	// view has reference to controller.
		
		controller.registerView( view );		// controller has references to view and model.
		controller.registerModel(model);
		
		model.registerController(controller);	// model has reference to controller.


		view.setVisibleABPanel(false);
		view.setVisibleCursorPanel(false);
		view.setVisibleTextPanel(true);
		view.setVisibleInputPanel(false);		// a few other components of view are excluded.
		view.setVisibleLeftButton(false);
		view.setVisibleRightButton(false);
		view.setVisibleDownButton(false);
		view.setVisibleUpButton(false);
		view.setVisibleButton2(false);
		view.setVisibleButton3(false);
		view.setVisibleButton4(false);
		view.setVisibleAButton(false);
		view.setVisibleBButton(false);

		view.setButton1Text("Start");	
	}
}
