


public class BST2Tester
{
	public static void main(String args[])
	{
		BSTree2 tree = new BSTree2(64);
		
		tree.insert(13);
		tree.insert(45);
		tree.insert(10);
		tree.insert(9);
		tree.insert(54);
		tree.insert(11);
		tree.insert(42);
		
		System.out.println("the minimum value is " + tree.findMin());
		System.out.println("the maximum value is " + tree.findMax());
		
		tree.inOrderPrint();
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	}





}
