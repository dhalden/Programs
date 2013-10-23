#Hangman Game
#
#The classic game of Hangman. The computer picks a random word and
#The player guess letters one at a time.

#imports
import random

#constants
HANGMAN = (
"""
    ------
   |	  |
   |
   |
   |
   |
   |
   |
   |
  ----------
""",
"""
    ------
   |	  |
   |	  0
   |
   |
   |
   |
   |
   |
  ----------
""",
"""
    ------
   |	  |
   |	  0
   |	 -+-
   |
   |
   |
   |
   |
  ----------
""",
"""
    ------
   |	  |
   |	  0
   |	/-+-
   |
   |
   |
   |
   |
  ----------
""",
"""
    ------
   |	  |
   |	  0
   |    /-+-/
   |
   |
   |
   |
   |
  ----------
""",
"""
    ------
   |	  |
   |	  0
   | 	/-+-/
   |	  |
   |	  
   |
   |
   |
  ----------
""",
"""
    ------
   |	  |
   |	  0
   | 	/-+-/
   |	  |
   |	  |
   |	 |
   |	 |
   |
  ----------
""",
"""
    ------
   |	  |
   |	  0
   | 	/-+-/
   |	  |
   |	  |
   |	 | |
   |	 | |
   |
  ----------
""")

MAX_WRONG = len(HANGMAN) - 1
difficulty = 0
while difficulty > 3 or difficulty < 1:
	difficulty = int(input("choose your difficulty 1-3, 1 being the easiest,"+ 
												   "and 3 being the hardest:"))
#Easy Words
WORDS1 = ("OVERUSED","CLAM","GUAM", "TAFFETA","PYTHON","LAMPSHADE","PARACHUTE",
"ONOMATOPOEIA","PRECISE","CREATION","XYLOPHONE","GRAMOPHONE","PURPLE","GREEN",
"ORANGE","BLUE","YELLOW","RED","DIVIDE","MULTIPLY","ADD","SUBTRACT","OR",
"EXCOMMUNICATE")

#Medium words
WORDS2 = ("ZAMBONI","SUSURRUS","ITERATE","IRROTATE","OXYGEN","SULFUR","BORON",
"BERYLIUM", "HYDROGEN","HELIUM","GALLIUM","GRAVITATE","QUIET","QUITE",
"EXQUISITE","EXCRUCIATING")

#Difficult Words
WORDS3 = ("SILICON","NITROGEN","PERISTERONIC","ZENITH","QUEUEING","CHUPACABRA",
"QUIXOTIC","PHYTOPLANKTON","RACECAR","ELOQUENT")

if  difficulty == 1: 
	WORDS = WORDS1
elif difficulty == 2:
	WORDS = WORDS2
elif difficulty == 3:
	WORDS = WORDS3
else:
	WORDS = WORDS3
#Initialize variables
word = random.choice(WORDS) #The word guessed

so_far = "-" * len(word) #one dash for each letter in word to be guessed


wrong = 0 #number of wrong guesses the player has made

used_letters = [] #letters already guessed

print("Welcome to Hangman. Good Luck!")

while wrong < MAX_WRONG and so_far != word:
	print(HANGMAN[wrong])
	print("So far, the word is:\t", so_far)
	print("\nYou've used the folowing letters:\n", used_letters)

	guess = input("\n\nEnter your guess:")
	guess = guess.upper()
	while len(guess) > 1 or guess == "" or guess == " ":
		print("that is not the right amount of letters")
		guess = input("Enter your guess:")
		guess = guess.upper()
	while guess in used_letters:
		print("You've already guessed the letter", guess)
		guess = input("Enter your guess: ")
		guess = guess.upper()
	print("\n\n\n")
	used_letters.append(guess)
	if guess in word:
		print("\nYes!", guess, "is in the word!")
		#Create a new so_far to include guess
		new = ""
		for i in range(len(word)):
			if guess == word[i]:
				new += guess
			else:
				new += so_far[i]
		so_far = new
	else:
		print("\nSorry,", guess,"isn't in the word.")
		wrong += 1
if wrong == MAX_WRONG:
	print("\n\n\n\n\n\n",HANGMAN[wrong])
	print("\nYou've been hanged!")
else:
	print("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nYou guessed it!")

print("\nThe word was", word)

input("\n\nPress the enter key to exit")
				



































