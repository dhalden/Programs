import random
hangmen = [
""" 
 ________
|        |
|
|
|
|
|
|
|_________
|         |
""",
""" 
 ________
|        |
|        O
|
|
|
|
|
|_________
|         |
""",
""" 
 ________
|        |
|        O
|        |
|
|
|
|
|_________
|         |
""",
"""
 ________
|        |
|       \O
|        |
|
|
|
|
|_________
|         |
""",
"""
 ________
|        |
|       \O/
|        |
|
|
|
|
|_________
|         |
""",
"""
 ________
|        |
|       \O/ 
|        | 
|         \\
| 
|
|
|_________
|         |
""",
"""
 ________
|        |
|       \O/ 
|        |  
|       / \\ 
| 
|
|
|_________
|         |

Game Over! You Lose!
"""]

#choose a word
words = ["hello", "magic", "purple", "bunnies", "onomatopoeia","susurrus"]
choice = random.randint(0, len(words)-1)
wchoice = words[choice]
word = []
for j in range(len(wchoice)):
    word.append('_')

#initial settings
letters_guessed = ''
i = 0
print(hangmen[i])
print("".join(word))
while(i != len(hangmen) - 1):
    #take a guess
    guess = raw_input("guess a letter: ")
    while(len(guess) > 1):
        guess = raw_input("that's too many letters, guess 1 letter: ")
    check = 0
    
    #find out if the letter is in the word
    for j in range(len(wchoice)):
        if wchoice[j] == guess and (guess not in letters_guessed):
            word[j] = guess
            check = 1

    #find out if the letter wasn't in the word, or was already guessed
    if guess in letters_guessed:
        print("you've already guessed that letter!")
    elif(check == 0):
        i+=1
        letters_guessed += guess
    else:
        letters_guessed += guess

    #check to see if you've won
    if("".join(word) == wchoice):
        print("correct, the word was '"+"".join(word) + "'")
        print("you win!")
        break

    #print the correct iteration of the hangman + word
    print(hangmen[i])
    print("".join(word))
    print("letters guessed: " + letters_guessed)
