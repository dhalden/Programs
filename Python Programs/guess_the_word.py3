#guess the computers word when it only tells you yes or no
#questions about what letters are in the word
#the computer will also tell you how many letters there are in the
#word

import random

WORDS = ("purple", "green", "orange", "blue","xylophone","bassoon")

word = random.choice(WORDS)
wordLength = len(word)
print("there are", wordLength,"letters in the word")

for i in range (0,5):
	guessl = str(input("give me a letter note that if you give me more than one,\nI will only use the first: "))
	
	for letter in guessl:
		if letter not in word:
			print("NO")
		else:
			print("Yes ")
		break
	
	
guess = input("guess the word: ")

if guess == word:
	print("You're right!")
else:
	print("nope! Better luck next time.")

