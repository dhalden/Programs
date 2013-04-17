#Word Jumble
#The computer picks a random word and then "jumbles" it, the player
#has to pick the original word

import random

WORDS = ("python", "jumble", "easy", "difficult", "answer", "xylophone", "purple", "onomatopoeia", "egregious","susurrus","parachute","strongest","queueing","perfidious","parallel","quixotic","spontaneity","deciduous","phytoplankton",
"enzyme","liter","chupacabra","barista","piano","stop","beginner","unicorn","irony","simple")
HINTS = ("this program", "this game", "do you really need help?", "the opposite of easy", "what you're trying to come up with",
"It starts with x and is an instrument","my favorite color", "blam!", "like an ____ error","shwshshwsh","skydiving", "The champion of an arm wrestling contest is _____", "Present progressive of 'to order'","deceitful and untrustworthy",
"antonym of perpindicular","delusional","mmmmm tea, einstein's","loses it's leaves","blue-green algae","ATP synthase",
"unit of measurement","a mexican goat monster","Similar to a mexican goat monster, but in a coffee shop","keyboard","octagon","starting","one horn","not 10000 spoons","ummmmm figure it out yourself")

#pick one word randomly from the sequence
rangeOfWords = len(WORDS) - 1
decision = random.randint(0,rangeOfWords)
word = WORDS[decision]
hint = HINTS[decision]

#create a variable to use later to see if the guess is correct
correct = word

# create a jumbled version of the word
jumble = ""
while word:
	position = random.randrange(len(word))
	jumble += word[position]
	word = word[:position] + word[(position + 1):]
#Scoring variable (i'll be using a deductive scoring system)
score = 10

#Start the game
print(
"""
		Welcome to Word Jumble!

   Unscramble the letters to make a word.
(Press the enter key at the prompt to quit.)
"""
)
print("The jumble is:", jumble)
print("enter 'hint' for a hint")
#explain the scoring system
print("\n\nnote that a hint will result in a 3 point deduction")
print("wrong guesses will result in 1 point deductions")
print("A perfect score is 10")

guess = input("\nYour guess: ")

	
while guess != correct and guess != "":
	#checks if they asked for a hint
	if guess == "hint":
		print(hint)
		score -= 3
	else:
		print("sorry, That's not it.")
		score -= 1
	guess = input("Your guess: ")
	if score <= 0:
		break
	
if guess == correct:
	print("That's it! You guessed it!\n")
#introduce scoring element. Score is out of ten, this tells them
#their score
if score == 10:
	print("You got a perfect score! Congratulations!")
elif score > 0:
	print("you got a score of", score," out of 10")
else:
	print("You fail!")

print("Thanks for playing!")

input("\n\nPress the enter key to exit")
