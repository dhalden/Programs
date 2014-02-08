public class Simulate
{
	public static void simInterrupt()
	{
		if(Math.random()<.5)
		{
			try{
				Thread.sleep(200);
			}catch(Exception e)
			{
				
			}
		}
	}
	
}