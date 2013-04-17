

public class BSTNode
{
	public BSTNode parent;
	public BSTNode left;
	public BSTNode right;
	public int key;
	
	public BSTNode(int data)
	{
		key = data;
		parent = null;
		left = null;
		right = null;
	
	}
	public boolean hasChildren()
	{
		return ((hasLeftChild()) || (hasRightChild()));
	}
	public boolean hasLeftChild()
	{
		return (left != null);
	}
	public boolean hasRightChild()
	{
		return (right != null);
	}
}
