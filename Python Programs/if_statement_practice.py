#the if statement
#Derek Halden

print("Welcome to system security inc.")
print("-- where security is our middle name\n")

password = input("Enter your password: ")

if password == "purple":
    print("Access Granted")
    #everything indented is executed if the statement is true.
    print("you must be someone very important")
else:
    print("Access Denied")

input("\n\nPress the enter key to exit.")
