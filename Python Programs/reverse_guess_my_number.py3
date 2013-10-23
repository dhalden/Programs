#I pick the number, and the computer guesses.

myNumber = int(input("Pick a number between 1 and 100: "))
while not myNumber <= 100:
	myNumber = int(input("You have to pick an integer between 1 and 100!: "))
guess = 64
tries = 1
guessModifier = guess//2
while guess != myNumber:
	print("my guess is",guess)
	myResponse = str(input("is it lower or higher? "))

	#algorithm for if the number is lower than the guess.

	if myResponse == "lower" and guess >= myNumber:
		guess = guess - guessModifier
		guessModifier = guessModifier//2
		# If it started to go below 1 it would immediately start adding
		# zero. I couldn't have that, so it defaults to one.		
		if guessModifier < 1:
		    guessModifier = 1
	#the algorithm for if the number is higher than the guess.

	elif myResponse == "higher" and guess <= myNumber:
		guess = guess + guessModifier
		guessModifier = guessModifier//2
		# There was a problem when the computer tried to guess more than 100
		# It would still get the answer right, but I wanted it to guess
		# more like a human. a human wouldn't guess over 100 when the
		# limit was between 1 and 100.
		if guess > 100:
			guessModifier = 2
			guess = 100
		
		if guessModifier < 1:
		    guessModifier = 1
	# If they don't give 'lower' or 'higher' it asks for them to do it again.
	else:
		print("you have to tell me lower or higher!")
		print("you also have to tell me the truth!")
		print("try again")
		continue
	#counts the number of guesses the computer makes.
	tries += 1
print("is it ", guess, "?")
verification = str(input("Yes, No or Y/N: "))
#checks to make sure you know it got the answer right
#there's no lying to the computer when you already entered a value.
if verification == "Yes" or verification == "Y":
	print("haha I got it in", tries,"tries")
else:
	print("You lie! I know I'm right!")
input("Press enter to exit.")
