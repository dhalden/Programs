public class Summing
{
	public static double Sum(int i, double list[])
	{
		if(i == (list.length))
		{
			return 0;
		}
		else
		{
			double d = Sum(i+1, list);
			return d + list[i];
		}
	}
	public static int SumInt(int n)
	{
	 try
	 {
		if(n == 1)
			return n;
		else
			{
			int sum = SumInt(n-1);
			//System.out.println(sum);
			return(n + sum);
			
		
			}
		}
		
	catch(StackOverflowError SOE)
		{
		System.out.println(SOE.getMessage());
		
		}
		return 0;
		
	}
	public static void main(String[] args)
	{
	
	 System.out.println(SumInt(6231));
	
	
	}


}
