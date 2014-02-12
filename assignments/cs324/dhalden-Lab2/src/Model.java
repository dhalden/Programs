
/**
 * Model for Checkoff #2.  Keep track of the location of the moving character.
 *
 * @author Derek Halden
 */
public class Model extends SLModel {

	private int loc = 0;

	public int getLoc() {
		return loc;
	}
	
	public void setLoc(int nl){
		loc = nl;
	}
	
	public int goLeft()
	{
		if(loc != 0)
		{
			loc =  loc - 1;
		}
		return loc;
	}
	
	public int goRight()
	{
		if(loc != 4)
		{
			loc = loc + 1;
		}
		return loc; 		// temporary - finish defining the method.
	}

}