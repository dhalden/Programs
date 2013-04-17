public class Lab09
{
	
	public static int denoms[] = {25, 21, 10, 5, 1};
	public static int[] change = new int[100];
	public static boolean evens(int[] list)
	{
	
		return evens(0, list);
	
	}
	
    private static boolean evens(int idx, int[] listOfInts)
    {
    	if ((idx == listOfInts.length - 1) && (listOfInts[idx] % 2 == 0))
    	{
    		return true;
    	}
    	else if (listOfInts[idx] % 2 == 0)
    	{
    		return evens(idx + 1,  listOfInts);
    	}
    	else
    	{
    		return false;
    	}
    
    
    
    }
    public static boolean atLeastOneNegative(int[] list)
	{
	
		return atLeastOneNegative(0, list);
	
	}
	private static boolean atLeastOneNegative(int idx, int[] listOfInts)
    {
    if ((idx == listOfInts.length - 1) && (!(listOfInts[idx] <= 0)))
    	return false;
    if(!(listOfInts[idx] <= 0))
    	return atLeastOneNegative(idx + 1, listOfInts);
    
    
    	return true; 
    
    
    
    }
    public static void changeBase(int n, int base)
	{
		// base case could be when n/base is = 0 .
		int x = n%base;
		if (n/base == 0)
		{
			switch (x)
				{
				case 10:
					System.out.print("A");
					break;
				case 11:
					System.out.print("B");
					break;
				case 12:
					System.out.print("C");
					break;
				case 13:
					System.out.print("D");
					break;
				case 14:
					System.out.print("E");
					break;
				case 15:
					System.out.print("F");	
					break;	
				default:
					System.out.print(n);
				}
		}
		else
		{
			changeBase(n/base, base);
			
			
			switch (x)
			{
			case 10:
				System.out.print("A");
				break;
			case 11:
				System.out.print("B");
				break;
			case 12:
				System.out.print("C");
				break;
			case 13:
				System.out.print("D");
				break;
			case 14:
				System.out.print("E");
				break;
			case 15:
				System.out.print("F");	
				break;	
			default:
				System.out.print(n%base);
			
			}
		}
		
	}
	public static int makeChange2(int idx)
		{
			// base cases are if change == denoms[i] for any i
			for (int i = 0; i < denoms.length; i++)
			{
				change[denoms[i]] = 1;
				
				if (idx == denoms[i])
				{	
					return change[idx];
				}
			}
			
			
			// recursive step
			if (change[1] == 0)
			{
				change[1] = 1;
			}
			if(change[idx-1] == 0)
			{
				//System.out.println("got here w/ idx-1 = " + (idx-1));
				change[idx - 1] = makeChange2(idx - 1);
			}
			
			//System.out.println("got here idx-1 = " + (idx-1));
			
			int currentFewestCoins = change[1] + change[idx-1];
			int amt1 = 2;
			// while amt1 <= 1/2 of change
			while (amt1 <= idx/2)
			{
				int amt2 = idx - amt1;
				
				if (change[amt1] == 0)
				{
					change[amt1] = makeChange2(amt1);
				}
				
				if (change[amt2] == 0)
				{
					change[amt2] = makeChange2(amt2);
				}
				
				int tempCoins = change[amt1] + change[amt2];
				
				if (tempCoins < currentFewestCoins)
				{
					currentFewestCoins = tempCoins;
				}
				amt1++;
			}
			
			change[idx] = currentFewestCoins;
			return currentFewestCoins;
		}
		
		
    public static void main(String args[])
    {
    	
    	int[] list = new int[]{2,4,6,8,10,12,14,15,18,20};
    	
    	System.out.println(evens(list));
    	
    	System.out.println(atLeastOneNegative(list));
    	
    	changeBase(78,16);
    	System.out.println();
    	changeBase(17,16);
    	System.out.println();
    	changeBase(32,16);
    	System.out.println();
    	changeBase(2560,16);
    	System.out.println();
    	
    	System.out.println("The fewest number of coins for 30 cents is " + makeChange2(30));
    	System.out.println("The fewest number of coins for 50 cents is " + makeChange2(50));
    	System.out.println("The fewest number of coins for 63 cents is " + makeChange2(63));
    	
    	
    
    
    
    
    }



}
