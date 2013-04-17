 
 /*
 	Author: Derek Halden
 	2/14/13
 
 */
 
 import java.util.*;
 
 
 public class ProcessItems
 {
 	public static void main(String args[])
 	{
 	
 	ArrayList<Item> itemList = new ArrayList<Item>();
 	itemList = ItemListMethods.populateItemList();
 	
 	ItemListMethods.printAL(itemList);
 	
 	
 	}
 
 
 }
