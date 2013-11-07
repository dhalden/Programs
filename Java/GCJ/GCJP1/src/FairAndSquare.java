import java.util.Scanner;


public class FairAndSquare {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		long cases = sc.nextLong();
		for(long i = 1; i <= cases; i++)
		{
			long low = sc.nextLong();
			long upp = sc.nextLong();
			long count = calc(low, upp);
			stoutput(i, count);
			
		}
		
	}
	public static long calc(long low, long upp)
	{
		long count=0;
		
		for(long i = (long)Math.ceil(Math.sqrt(low)); i<= (long)Math.floor(Math.sqrt(upp)); i++)
		{

			if (isPalindrome(""+i)&&isPalindrome(""+i*i)) {				
				count++;
			}
			
		}
		
		
		return count;
	}
	
	public static long[] pal(long low, long upp)
	{
		long[] palList = new long[(int)(upp-low)];
		
		
		for()
		
		return palList;
		
	}
	
	public static boolean isPalindrome(String i)
	{
		boolean result = false;
		if (i.equals("")) {
			result = true;
		} else if (i.length() == 1) {
			result = true;
		} else {
			if (i.charAt(0) == i.charAt(i.length()-1)) {
				result = isPalindrome(i.substring(1, i.length()-1));
			}
		}
		return result;
	}
	
	public static void stoutput(long i, long count)
	{
		System.out.println("Case #"+i+": "+count);
	}

}
