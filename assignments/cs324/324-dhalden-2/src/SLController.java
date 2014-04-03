import java.awt.Color;


/**
 * <p>This class forms the "Controller" component of the "Model-View-Controller" design pattern.
 * It must be subclassed when using SLView to implement methods called by the view
 * object and an instance of the subclass must be registered with SLView and a subclass of
 * SLModel.</p>
 * 
 * <p>The user must define the public abstract methods listed below in the subclass.  These are 
 * called by the SLView when the user interacts with the graphical interface.</p>
 * 
 *  <p>Note: the protected variables, <b>view<b> and <b>model</b>, is defined as a SLModel and this can
 *  be referenced in the public methods of the subclass of SLController.</p>
 * 
 * @author Pierre von Kaenel
 *
 */
public abstract class  SLController {

	protected SLModel model;
	protected SLView view; 
	
	/**
	 * SLController must have access to a model that is subclassed from SLModel.  This method
	 * is called by an external class that has defined a model and provides a reference to it.
	 * @param a subclass of SLModel.
	 */
	public void registerModel( SLModel model )
	{
		this.model = model;
	}
	
	/**
	 * SLController must have access to SLView. This method is called by an external class
	 * that has defined the view and provides a reference to it.
	 * @param view a reference to the view
	 */
	public void registerView(SLView view)
	{
		this.view = view;
	}

	/**
	 * The following abstract methods are called by the View object when the user has
	 * performed an action.  The other methods in the View object can be called by this
	 * controller to manipulate the view or display text in the text area and/or test fields.
	 * 
	 * Note that view and model objects must be registered using registerView() and
	 * registerModel().
	 */
	abstract public void inputTextAction(String input);
	abstract public void aButtonAction();
	abstract public void bButtonAction();
	abstract public void upButtonAction();
	abstract public void downButtonAction();
	abstract public void rightButtonAction();
	abstract public void leftButtonAction();
	abstract public void button1Action();
	abstract public void button2Action();
	abstract public void button3Action();
	abstract public void button4Action();
	abstract public void gridButtonAction(int r, int c);
	
	
	/**
	 * The following methods can be called by the model to interact with the view.
	 * 
	 * Set the foreground color (text color) of a button on the button grid.
	 * Nothing happens if grid is not in use.
	 * 
	 * @param color of the text on the button
	 * @param row of button in the grid (rows begin with index 0)
	 * @param column of button in the grid (columns begin with index 0)
	 */
	public void setGridButtonForeground(Color color, int row, int col)
	{
		view.setGridButtonForeground(color, row, col);
	}
	
	/**
	 * Get the foreground color defined for the button on the button grid.
	 *  
	 * @param row of button  (rows begin with index 0)
	 * @param col of button  (columns begin with index 0)
	 * @return the Color.  null returned if the view does not use a button grid.
	 */
	public Color getGridButtonForeground(int row, int col)
	{
		return view.getGridButtonForeground(row, col);
	}

	
	/**
	 * Write a String to a button on the button grid.  
	 * Nothing happens if grid is not in use.
	 * 
	 * @param str to display on the button
	 * @param row of button in the grid (starting with offset 0)
	 * @param column of button in the grid (starting with offset 0)
	 */
	public void setGridButtonText(String str, int row, int col)
	{
		view.setGridButtonText(str, row, col);
	}
	
	/**
	 * Get the text currently written on the button. The empty string ("")
	 * is returned if the button has no text.
	 * 
	 * @param row of button in the grid (starting with offset 0)
	 * @param column of button in the grid (starting with offset 0)
	 * @return
	 */
	public String getGridButtonText(int row, int col)
	{
		return view.getGridButtonText(row, col);
	}
	
}
