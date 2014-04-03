/**
 * <p>This class forms the "Model" component of the "Model-View-Controller" design pattern.
 * It must be subclassed when the model needs to access the controller for some purpose.</p>
 * 
 * <p>In version 1.3, a reference to the controller was introduced.  Prior to that, SLModel was
 * an empty class and the programmer had to subclass this class to add a reference to the 
 * controller, if it was needed.  In version 1.3, the code is included in the abstract class, but
 * the reference to the controller does not have to be used.  Frequently, methods added to a
 * subclass of SLModel return a value and the calling class (subclass of SLController) can retrieve
 * data using the return values.  However, there may be situations when SLModel must initiate
 * communications with the controller - in these cases the subclass of SLModel includes methods
 * that call methods in the controller and thus use the variable "controller" to access the
 * controller object.</p>
 * 
 * <p>Note that subclassing SLModel is not necessary.  The programmer may define a Model class
 * entirely from scratch.</p>
 * 
 * @author Pierre von Kaenel
 *
 */
abstract public class SLModel {

	protected SLController controller;
	
	/**
	 * SLModel may need access to a controller.  
	 * @param controller a subclass of SLController.
	 */
	public void registerController( SLController controller )
	{
		this.controller = controller;
	}
}
