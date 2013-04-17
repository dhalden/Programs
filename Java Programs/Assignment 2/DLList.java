/*
	
	DLList.java
	
	A doubley linked list that stores StudentScores for it's data.
	It maintains both a head and a tail.
	
	Author: Derek Halden
	Date:3/21/2013

*/
import java.io.*;

public class DLList
{
	private DNode head;
	private DNode tail;
	private int length;
	
	//Constructor takes in nothing.

	public DLList()
	{
		head = null;
		tail = null;
		length = 0;
	}
	//A bubble sort
	//note, this works, but it is unnecessary to call because of the
	//addInSortOrder() method below that is more efficient. 
	public void sort()
	{
		DNode temp = head;
		StudentScore savedData;
		while (temp != null)
		{
			boolean swappedDuringPass = false;
			
			while(temp.next != null)
			{
				
				if(temp.data.compareTo(temp.next.data) > 0)
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
	/* 
		Takes in new StudentScore, and adds it to the LinkedList
		returns nothing
	*/
	private void addToBeginning(StudentScore ss)
	{
		DNode tempNode = new DNode(ss);
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
	/* 
		Takes in new StudentScore, and adds it to the LinkedList
		returns nothing
	*/
	private void addToEnd(StudentScore ss)
	{
		if(isEmpty())
		{
			addToBeginning(ss);
		}
		else
		{
			DNode savedTail = tail;
			DNode newNode = new DNode(ss);
			
			tail.next = newNode;
			tail = newNode;
			tail.prev = savedTail;
			//Links to the previous once the tail is moved over
		
		}
	
		length++;
	}
	
	//Rather than implementing and using a sort method, adding a node in a specific
	//order seems like it would save time for small lists.
	//this is not as practical as the list gets arbitrarily large, because it runs in
	//O(n). Considering we don't know any O(nlog(n)) sorts this is actually pretty efficient.
	//If the list is already sorted from smallest to largest, it runs in O(1) for each object in the list
	//because it runs backwards.
	
	
	/*
		Takes in a value, and puts it in order from smallest to largest
		returns nothing
	*/
	public void addInSortOrder(StudentScore ss)
	{
		if(isEmpty())
		{
		//if the list is empty, the base case is still the same
		addToBeginning(ss);
		}
		else if(head.next == null)
		{
			if(head.data.compareTo(ss) > 0)
			{
				addToBeginning(ss);
			}
			else
			{
				addToEnd(ss);
					
			}
			
		}
		//I do this twice, because this time, I'm checking to see if something needs to
		//be added to the end
		else if (tail.data.compareTo(ss) > 0)
		{
			DNode temp = tail;
			DNode addNode = new DNode(ss);
			//find the node before where I want to insert this node.
			while((temp.prev != null) && (temp.data.compareTo(addNode.data) > 0))
			{
				temp = temp.prev;
				
			} 
			
			if(temp.prev != null)
			{
				
				addNode.next = temp.next;
				addNode.prev = temp;
				temp.next.prev = addNode;
				temp.next = addNode;
			}
		
		}
		else
		{
		
		addToEnd(ss);
		
		}
	}
	
	// I removed the insertAfter function from this code, because I want 
	// people to add things in the sorted order.
	
	//return the node that has ss in it
	private DNode findNode(StudentScore ss)
	{
		DNode temp = head;
		
		while ((temp != null) && (temp.data.compareTo(ss) != 0))
		{
			temp = temp.next;
		}
		
		return temp; 
	}
	
	
	//return the student score of the student with name "name"
	//if the list is empty, it returns null
	public StudentScore findSSWithName(String name)
	{
		DNode temp = head;
		if(isEmpty())
		{
			return null;
		}
		 while((temp != null) && (temp.data.getStudentName().compareTo(name) != 0))
		 {
		 
		 temp = temp.next;
		 
		 }
		 //returns null if student score does not exist.
		 if(temp == null) 
		 {
		 return null;
		 }
		 
		 return temp.data;
	}
	
	
	//takes in a Student Score
	//Returns True or False with regards to whether or not it
	//found that student score.
	public boolean delete(StudentScore delSS)
	{
		
		DNode foundNode = findNode(delSS);
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
	//returns whether or not it deleted the head
	private boolean deleteHead()
	{
		
		if(!isEmpty())
		{
			head.prev = null;
			head = head.next;
			return true;
		}
		return false;
	}
	//I wanted to clean up the delete code ergo I wrote these two methods
	//returns whether or not it deleted the tail
	private boolean deleteTail()
	{
	 if(!isEmpty())
	 {
	 	tail.next = null;
		tail = tail.prev;
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
	
	//returns each of the pieces of data in the list as a string
	
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
	
	//returns the tail StudentScore
	//if the list is sorted, this is the largest value
	public StudentScore getTailSS()
	{
		if(tail != null)
		{
			return tail.data;
		}
		
		return null;
	}
	//returns the Head StudentScore
	//if the list is sorted, this is the smallest value
	public StudentScore getHeadSS()
	{
		
		if(head != null)
		{
			return head.data;
		}
		
		return null;
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
	//clears the entire list
	public void clear()
	{
		head = null;
		tail = null;
	
	}
	//Takes in a File name as it's parameter
	//returns nothing, but instead writes all of the contents
	//Of the list into a file with each line looking like the following
	//studentName score where score is an integer.
	public void saveDLListToFile(String file)
	{
	
		PrintWriter pw;
		DNode temp = head;

	try
		{
			pw = new PrintWriter(new FileOutputStream(file, false));
			
			// This will need some work.
			while (temp != null)
			{ 
				pw.println(temp.data.formatForFile());
				temp = temp.next;
			}
			pw.close();
		}
		
		catch (IOException ioe)
		
		{
			
			System.out.println("couldn't read from file MSG:" + ioe.getMessage());
			
		}
		
	}

}
