
/**
 * This is a class that has 2 main methods, one that tells the controller to
 *  change a button's text in the grid on the view
 *  
 *  The other that tells the controller to add text to the text area
 *  that the Arrivals, or Departures thread is having to wait.
 * * @author Derek Halden
 * 
 */
public class Model extends SLModel {
	/**
	 * @param col The column index of the grid button that needs to change
	 * @param str The thing that the grid button needs to change to
	 */
	public void setCol(int col, String str) {
		((Controller)controller).set(col,str);
	}
	/**
	 * @param str The string for the thread that is having to wait
	 */
	public void mtw(String str)
	{
		((Controller)controller).mentionWaiting(str);
	}
}
