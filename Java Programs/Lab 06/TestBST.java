

public class TestBST
{
	public static void main(String args[])
	{
		BSTree tree = new BSTree();
		
		tree.insert(20);
		tree.insert(19);
		tree.insert(21);
		tree.insert(71);
		tree.insert(12);
		tree.insert(5);
		tree.insert(17);
		tree.insert(25);
		tree.insert(20);
		
		System.out.println("the minimum value is " + tree.findMin());
		System.out.println("the maximum value is " + tree.findMax());
		
		tree.inOrderPrint();
		
		
	
	}
}
