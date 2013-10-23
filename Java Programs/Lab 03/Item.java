/*
 	Author: Derek Halden
 	2/14/13
 
 */

public class Item
{
	private String itemName;
	private double itemPrice;
	private int itemQuantity;
	
	public Item(String label, double price, int quantity)
	{
		setItemName(label);
		setItemPrice(price);
		setItemQuantity(quantity);
	
	}
	
	public void setItemName(String name)
	{
		this.itemName = name;
	}
	
	public void setItemPrice(double price)
	{
		this.itemPrice = price;
	}
	
	public void setItemQuantity(int quantity)
	{
		this.itemQuantity = quantity;
	}
	
	public String toString()
	{
	
	String itemInfo = new String();
	itemInfo = (itemName + ", " + itemPrice + ", " + itemQuantity);
	return itemInfo;
	}


}
