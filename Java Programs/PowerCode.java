public class PowerCode
{
	public static int count = 0;
	public static int power(int number, int pow)
	{
		if(pow != 0)
		{
			return (power(number, (pow -1)) * number);
		}
		return 1;
	
	
	}
	public static long powerFast(long number, int pow)
	{
		
		count++;
		boolean even = (pow % 2 == 0);
		if(pow == 1)
			{
			return number;
			}
			
		long numToSquare = powerFast(number, pow/2);	
			
		if (even)
			{
			
			return  numToSquare*numToSquare;
			}
		else 
			{
			return(number*numToSquare*numToSquare);
			
			}
	
	
	
	}
	
	public static long powerFastIterative(long base, int exp)
	{
		long temp = base;
		int pwr = exp;
		 
		for (int i = 1; i <= pwr;)
			{
				count++;
				
					if((pwr/2 >= i))
					{
					temp = temp*temp;
					pwr = pwr/2;
					}
				
					if((pwr-- >= i))
					{
				  	
				  	temp *= base;
				  	pwr--;
					}
				
				
			}
		if(count == 0)
			count++;
			
		return temp;
		
	
	}
	public static void main(String args[])
	{
	
	System.out.println(powerFastIterative(2,31));
	System.out.println("Count: " + count);
	count= 0;
		
	System.out.println(powerFast(2,31));
	System.out.println("Count: " + count);
	count= 0;	
	/*
		System.out.println(powerFast(2,1));
		System.out.println("Count: " + count);
		count= 0;
		System.out.println(powerFast(2,2));
		System.out.println("Count: " + count);
		count= 0;
		System.out.println(powerFast(2,4));
		System.out.println("Count: " + count);
		count= 0;
		System.out.println(powerFast(2,8));
		System.out.println("Count: " + count);
		count= 0;
		System.out.println(powerFast(2,16));
		System.out.println("Count: " + count);
		count= 0;
		System.out.println(powerFast(2,32));
		System.out.println("Count: " + count);
		count= 0;
		
		System.out.println(powerFast(2,64));
		System.out.println("Count: " + count);
		count= 0;
		
		System.out.println(powerFast(2,128));
		System.out.println("Count: " + count);
		count= 0;
		
		System.out.println(powerFast(2,256));
		System.out.println("Count: " + count);
		count= 0;
		
		System.out.println(powerFast(2,512));
		System.out.println("Count: " + count);
		count= 0;
		
		System.out.println(powerFast(2,1024));
		System.out.println("Count: " + count);
		count= 0;
	
	*/
	}




}
