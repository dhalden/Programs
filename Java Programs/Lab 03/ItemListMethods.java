import java.util.*;
import java.io.*;
import javax.swing.*;

/*
 	Author: Derek Halden
 	2/14/13
 
 */

public class ItemListMethods
{
	public static ArrayList<Item> populateItemList()
	{
	 ArrayList<Item> txtList = new ArrayList<Item>();
	 
	try
		{	
		BufferedReader listOfItemsFile = new BufferedReader(new FileReader("itemlist.txt")); 
		
		while(listOfItemsFile.ready())
			{
			
			String line = listOfItemsFile.readLine();
			
			
			
			StringTokenizer st = new StringTokenizer(line, ", ");
			
			String label = st.nextToken();
			String priceStr = st.nextToken();
			String quantityStr = st.nextToken();
			
			double price = Double.parseDouble(priceStr);
			int quantity = Integer.parseInt(quantityStr);
			
			Item item = new Item(label, price, quantity);
			txtList.add(item);
			}
			
			listOfItemsFile.close();
		
		} 
	catch (FileNotFoundException fnfe)
		{
			System.out.println("File not found MSG:" + fnfe.getMessage());
			
			 // kills the program
		} 
	catch (IOException ioe)
		{
			System.out.println("couldn't read from file MSG:" + ioe.getMessage());
			
			 // kills the program
		} 
		
		return txtList;
	}
	
	public static void printAL(ArrayList<Item> printList)
	{
	
		{
		String allTheItems = "";

		for (int i = 0; i < printList.size(); i++)
		{
		
			allTheItems +=  printList.get(i).toString() + "\n" ;
			
		}
		
		
		JOptionPane.showMessageDialog(null, allTheItems);

	}
	
	
	}
	
}





