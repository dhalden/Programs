public class DLListTester
{
	public static void main(String args[])
	{
		DLList dll = new DLList();
		
		//add to the beginning of an empty list
		dll.addToBeginning(4);
		dll.addToBeginning(3);
		dll.addToBeginning(2);
		dll.addToEnd(5);
		dll.addToEnd(6);
		dll.addToBeginning(1);
		dll.insertAfter(6, 7);
		dll.addToBeginning(0);
		
		//ensure the list prints both ways
		System.out.println(dll.toStringForward() + "\n");
		System.out.println(dll.toStringBackward() + "\n");
		
		//prints the head and the tail string to make sure they're correct
		System.out.println(dll.getHeadInt() + " : " + dll.getTailInt());
		
		//add space to what it's printing out.
		System.out.println("\n\n\n");
		
		//delete the head and the tail
		dll.delete(7);
		dll.delete(1);
		//check the head and tail afterwards to make sure they changed
		System.out.println("I deleted ints 1 and 7")'
		
		System.out.println(dll.toStringForward() + "\n");
		System.out.println(dll.toStringBackward() + "\n");
		
		//empty the list
		dll.clear();
		
		//show that the list is empty
		System.out.println(dll.toStringForward() + "<----This is printing an empty list.\n");
		System.out.println(dll.toStringBackward() + "\n");
		
		
		//delete from an empty list returns whether it worked or not
		System.out.println(dll.delete(4));
		
		//add to the end of an empty list
		dll.addToEnd(3);
		//delete something that doesn't exist returns whether it worked or not
		System.out.println(dll.delete(2));
		
		
		
	}

}
