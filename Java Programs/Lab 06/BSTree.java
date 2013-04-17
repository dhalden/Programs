

public class BSTree
{
	public BSTNode root;
	
	public BSTree()
	{
		root = null;
	}
	public boolean isEmpty()
	{
		return (root== null);
	}
	
	public void insert(int data)
	{
	
	BSTNode addNode = new BSTNode(data);
	
	if(isEmpty())
	{
		root = addNode;
		return;
	}
	else
		{
			
			BSTNode temp = root;
			while (true)
			{
			
			 	if(temp.key > addNode.key)
			 	{
			 		if (!(temp.hasLeftChild())) 
						{
							temp.left = addNode;
							addNode.parent = temp;
							return;
						}
					else
						{
							temp = temp.left;
						}
			  	}
			  	else
			  	{
			  		if (!(temp.hasRightChild()))
			  			{
			  				temp.right = addNode;
			  				addNode.parent = temp;
			  				return;
			  			}
			  		else
			  			{
				  			temp = temp.right;
				  		}
			 	}
	
			}	

		}
		
	
	}
	
	//returns rightmost node's data
	public int findMax()
	{
		BSTNode temp = root;
		
		while(temp.hasRightChild()) 
		{	
				temp = temp.right;	
		}
		return temp.key;
	}
	//returns leftmost node's data
	public int findMin()
	{
 		BSTNode temp = root;
		
		while(temp.hasLeftChild()) 
		{	
				temp = temp.left;	
		}
		return temp.key;
	}
	public void inOrderPrint()
   	{
		inOrderPrint(root);
   	}

   	private void inOrderPrint(BSTNode stRoot)
   	{
		if (stRoot != null)
        {
			inOrderPrint(stRoot.left);
			System.out.println(stRoot.key);
			inOrderPrint(stRoot.right);
        }
   	}
	 	
}
