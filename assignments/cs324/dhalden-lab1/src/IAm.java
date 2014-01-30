/**
 * 
 */

/**
 * @author jebediah
 *
 */
public class IAm implements Runnable {

	private String str;
	Thread t;
	/* (non-Javadoc)
	 * @see java.lang.Runnable#run()
	 */
	public IAm(String str)
	{
		this.str = str;
		t = new Thread(this);
		t.start();
	}
	@Override
	public void run() {
		// TODO Auto-generated method stub
		
		for (int i = 0; i < 9000; i++)
		{
			/*try {
				Thread.sleep(1);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}*/
			System.out.println(str);
		}
	}
}

