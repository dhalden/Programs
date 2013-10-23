# Hero's Inventory
# Demonstrates tuple creation

# create an empty tuple
inventory = ("sword", "armor","shield","healing potion",4)

# treat the tuple as a condition
if not inventory:
	print("You are empty-handed")
else:
	#print the inventory
	print("\n the tuple inventory is: ")
	print(inventory)
	
#Print each element in the tuple
print("\nYour items:")
for item in inventory:
	print(item)

#test for membership with in
if "healing potion" in inventory:
	print("you will live to fight another day")

# display one item through an index
index = int(input("\nEnter the index number for an item in inventory: "))
print("At index", index, "is", inventory[index])

#display a slice
start = int(input("\nEnter the index number to begin a slice: "))
finish = int(input("Enter the index number to end the slice: "))
print("inventory[", start, ":", finish, "] is", end=" ")
print(inventory[start:finish])

#shows length function for tuples
print("You have", len(inventory), "items in your possession.")

input("\n\nPress the enter key to exit")

