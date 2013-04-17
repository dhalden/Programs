


public class BSTree2
{
	public int BSTree[];
	
	public BSTree2(int size)
	{
		BSTree = new int[size];
		
		for(int i = 0; i < BSTree.length; i++) 
		{
			BSTree[i] = -1;
		
		}
		
	}
	public boolean isEmpty()
	{
		return (BSTree[0] == -1);
	}
	public boolean insert(int data)
	{
		int index = 0; 
	 //if -1 then the list is empty
		if (isEmpty())
			{
				BSTree[0] = data;
				return true;
			}
		else
			{
				while(true)
				{
					if (BSTree[index] > data) 
					{
						index = left(index);
						if((BSTree[index] == -1))
						{
							BSTree[index] = data;
							return true;
						} 
					}
					else 
					{
						index = right(index);
						if((BSTree[index] == -1))
						{
							BSTree[index] = data;
							return true;
						} 
					}
					if (index >= BSTree.length)
					{
					return false;
					}
				}
			}
	
	
	}
	public int findMin()
	{
		int index = 0;
		while(hasLeftChild(index))
		{
			index = left(index);
		}
		
		return BSTree[index];
	
	
	}
	public int findMax()
	{
		int index = 0;
		while(hasRightChild(index))
		{
			index = right(index);
		}
		
		return BSTree[index];
	
	
	}
	public void inOrderPrint()
   	{
		inOrderPrint(0);
   	}

   private void inOrderPrint(int stRootIndex)
   {
	if (BSTree[stRootIndex] != -1)
        {
		inOrderPrint(left(stRootIndex));
		System.out.println(BSTree[stRootIndex]);
		inOrderPrint(right(stRootIndex));
        }
   }
	
	//returns left index
	private int left(int index)
	{
		return(2*index + 1);
	}
	//returns right index
	private int right(int index)
	{
		return(2*index + 2);
	}
	private int parentIndex(int index)
	{
		return((index - 1)/2);
	}
	
	private boolean hasLeftChild(int index)
	{
		return(BSTree[left(index)] != -1);
	}
	private boolean hasRightChild(int index)
	{
		return(BSTree[right(index)] != -1);
	}
	

}
