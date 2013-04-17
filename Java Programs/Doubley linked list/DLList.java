public class DLList
{
	private DNode head;
	private DNode tail;
	private int length;
	
	public DLList()
	{
		head = null;
		tail = null;
		length = 0;
	}
	public void sort()
	{
		DNode temp = head;
		int savedData;
		while (temp != null)
		{
			boolean swappedDuringPass = false;
			
			while(temp.next != null)
			{
				
				if(temp.data > temp.next.data)
				{
					savedData = temp.data;
					temp.data = temp.next.data;
					temp.next.data = savedData;
					swappedDuringPass = true;
			
				}
					
			
			temp = temp.next;
			}
			
			if ((temp == null) && (swappedDuringPass = true))
			{
				temp = head;
			}
			
		}
	} 
	
	public void addToBeginning(int addInt)
	{
		DNode tempNode = new DNode(addInt);
		DNode savedHead = head;
		
		if(!isEmpty())
		{
			head = tempNode;
			tempNode.next = savedHead;
			savedHead.prev = tempNode;
			//links the list 'doubly'	
		}
		else
		{
			head = tempNode;
			tail = tempNode;
		
		}
		length++;
	}
	
	public void addToEnd(int addInt)
	{
		if(isEmpty())
		{
			addToBeginning(addInt);
		}
		else
		{
			DNode savedTail = tail;
			DNode newNode = new DNode(addInt);
			
			tail.next = newNode;
			tail = newNode;
			tail.prev = savedTail;
			//Links to the previous once the tail is moved over
		
		}
	
		length++;
	}
	
	public boolean insertAfter(int findInt, int addInt)
	{
		DNode foundNode = findNode(findInt);
		/*because of all of the returns it's easiest to just assume the person
		is passing in a good int*/
		length++;
		
		if(foundNode == null)
		{
		//if the Int is not in the list we need to undo the length++
			length--;
			return false;
			
		}
		else if (foundNode == tail)
		{
			/*if the Int they're adding after is the tail, then we just
			add the object to the end*/
			addToEnd(addInt);
			return true;
		}

		else
		{
			DNode addNode = new DNode(addInt);
			DNode temp = foundNode.next;
			
			foundNode.next = addNode;
			/*what one must link to the one before, one must also link to the 
			one after.*/ 
			addNode.prev = addNode; 
			addNode.next = temp;
			temp.prev = addNode;
			return true;
		}
	
	}
	
	//return the node that has s in it
	public DNode findNode(int findInt)
	{
		DNode temp = head;
		
		while ((temp != null) && (temp.data != findInt))
		{
			temp = temp.next;
		}
		
		return temp; 
	}
	public boolean delete(int delInt)
	{
		
		DNode foundNode = findNode(delInt);
		if (foundNode == null)
		{
			return false;
		}
		length--;
		
		if (head == foundNode)
		{
			return (deleteHead());
		}
		if(foundNode == tail)
		{
			return (deleteTail());
		}
		else
		{
			
			foundNode.prev.next = foundNode.next;
			foundNode.next.prev = foundNode.prev;
			foundNode.prev = foundNode.next;
			
			return true;
		}
	
		
	}
	//I wanted to clean up the delete code ergo I wrote these two methods
	private boolean deleteHead()
	{
		if(!isEmpty())
		{
			head = head.next;
			head.prev = null;
			return true;
		}
		return false;
	}
	private boolean deleteTail()
	{
	 if(!isEmpty())
	 {
		tail = tail.prev;
		tail.next = null;
		return true;
	 }
	 return false;
	}
	//I made both of these private because I don't want the person to delete
	//the head or tail nodes without specifying the data.
	
	
	public String toStringForward()
	{
		String s = "";
		DNode temp = head;
		
		while (temp != null)
		{
			s += temp.data + "\n";
			temp = temp.next;
		}
		return s;
	
	}
	
	public String toStringBackward()
	{
		String s = "";
		DNode temp = tail;
		
		while (temp != null)
		{
			s += temp.data + "\n";
			temp = temp.prev;
		}
		return s;
	
	}
	
	public int getTailInt()
	{
		return tail.data;
	}
	
	public int getHeadInt()
	{
		return head.data;
	}
	
	// return length
	public int size()
	{
		return length;
	}
	
	//return whether or not the list is empty
	public boolean isEmpty()
	{
		return (head == null);
	}
	public void clear()
	{
		head = null;
		tail = null;
	
	}

}
