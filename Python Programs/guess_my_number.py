# Guess my number
# write a program (NO HELP) where I try to guess the computer's number

import random

myNumber = random.randint(1,100)
print("try to guess in 7 guesses or less")
guess = int(input("Guess a number from 1-100: "))
tries = 1
while guess != myNumber:
	if guess > myNumber:
		print("lower...")
	else:
		print("higher...")
	if tries >= 7:
		print("I'm sorry that's wrong, my number was",myNumber,"and you only get 7 guesses!")
		print("you lose!")
		break
	guess = int(input("guess again: "))
	tries += 1
	
if	guess == myNumber:
	print("That's correct!")
	print("You got it in",tries,"tries")
input("\n\npress enter to exit")


	

	
