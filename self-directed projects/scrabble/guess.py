import random
number = random.randint(0,100)
guess = int(input("guess my number: "))

while(guess != number):
    if(guess < number):
        print("that number is too low!")
    else:
        print("that number is too high!")
    guess = int(input("guess my number: "))

print("congratulations! You've guessed my number!")
