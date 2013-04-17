#Craps Roller
#demonstrates random number generation
#uses process to simulate dice roll by creating a random number

import random

#generate random number between 1 & 6
die1 = random.randint(1,6)
#0 is included in random range ergo +1
die2 = random.randrange(6) + 1

total = die1 + die2

print("you rolled a ", die1," and a ", die2, "for a total of", total)
print("\a")
input("\n\n Press the enter key to exit")
