#Hero's inventory the third
#Demonstrates lists

# create a list with some items and display with a for loop

inventory = ["sword", "armor", "shield", "healing potion"]
print("Your items:")
for item in inventory:
	print(item)

input("\nPress the enter key to continue.")

#get the length of the list
print("you have", len(inventory), "items in your possession.")

input("\npress the enter key to continue")


#test for membership with in
if "healing potion" in inventory:
	print("You will live to fight another day")

#display one item through an index
index = int(input("\nEnter the index number for an item in inventory: "))
print("At index", index, "is", inventory[index])

#display a slice
start = int(input("\nEnter the index number to begin a slice"))
finish = int(input("\nEnter the index number to end the slice"))
print("Your slice is from [", start,":",finish,"]")
print("that displays: ", inventory[start:finish])

input("\nPress the enter key to continue")

#concatenate two lists
chest = ["gold", "gems"]
print("you find a chest which contains: ")
print(chest)
print("You add the contents of the chest to your inventory")
inventory += chest
print("your inventory is now: ")
print(inventory)

input("\npress the enter key to continue.")


#assign by index
print("you trade your sword for a crossbow")
inventory[0] = "crossbow"
print("your inventory is now: ")
print(inventory)

input("\npress the enter key to continue.")

#assign by slice
print("you use your gold and gems to buy an orb of future telling")
inventory[4:6] = ["orb of future telling"]
print("your inventory is now:")
print(inventory)

input("\npress the enter key to continue.")

#delete an element
print("In a great battle, your shield is destroyed.")
del inventory[2]
print("Your inventory is now")
print(inventory)

input("\npress the enter key to continue.")

#deleting a slice
print("Your crossbow and armor are stolen by thieves")
del inventory[:2]
print("your inventory is now: ")
print(inventory)

input("\npress the enter key to exit.")
