
/**
 * This is a test class used with Controller and Main.  This model provides a setter and
 * getter method so that the controller can access the model's string.  It also provides
 * a writeString method that lets the controller direct the model to copy its string to
 * the view (via the controller).  Note that when the setter/getter is used, the model
 * remains passive, however writeString lets the model determine what to do.
 *
 * * @author Pierre von Kaenel
 */
public class Model extends SLModel {

	private String str = "bigdaddy";

	public String getString() {
		return str;
	}

	public void setString(String str) {
		this.str = str;
	}

	public void writeString()
	{
		// This takes the initiative and writes to the view, via the controller.
		// Note that since SLModel declares controller as SLController, even though 
		// in Main, it is a Controller that is registered, we must cast "controller" as a
		// Controller, otherwise Java flags an error, since it expects controller to be
		// an SLController.
		
		((Controller)controller).passStringToView(str);		// again, look carefully at the type cast.
	}
}
