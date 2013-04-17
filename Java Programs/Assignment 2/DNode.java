/*
	DNode.java
	
	This class is a node for a Doubley linked list.
	It contains info for the following
	
	next: The node after it.
	prev: The node before it.
	data: A StudentScore with a Name, and Score.
	
	Author:Derek Halden
	Date: 3/21/2013


*/

public class DNode
   {
       public StudentScore data;
       public DNode next;
       public DNode prev;

		//this constructor takes in a StudentScore
		//creates a node that with both next and prev as null.
       public DNode(StudentScore data)
       {
           this.data = data;
           this.next = null;
           this.prev = null;
       }
              
   }	
