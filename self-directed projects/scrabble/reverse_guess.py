guess = 64
n_of_g = 1
guesses = 0
print("think of a number between 1 and 100")
print("my guess is " + str(guess) + ": ")
l_or_h = (raw_input("was my guess low, high, or correct? "))

while(l_or_h != "correct"):
    if(l_or_h == "low"):
        n_of_g *= 2
        guess = guess + 64/n_of_g
        print("my new guess is " + str(guess) + ": ")
        guesses += 1
    elif(l_or_h == "high"):
        n_of_g *= 2
        guess = guess - 64/n_of_g
        print("my new guess is " + str(guess) + ": ")
        guesses += 1
    else:
        print("I'm sorry, I don't recognize that input")
    l_or_h = (raw_input("was my guess low, high, or correct? "))

print("yay! I got it in " + str(guesses) + " guesses.")
