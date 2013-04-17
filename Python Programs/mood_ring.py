#Else if alternative than his program

import random

print("I sense your energy. Your true emotions are coming across my screen.")
print("you are...")

mood = random.randint(1,6)

if mood == 1:
    print("Happy")

elif mood == 2:
    print("sad")
elif mood == 3:
    print("angry!")
elif mood == 4:
    print("indifferent")
elif mood == 5:
    print("disatisfied")
elif mood == 6:
    print("I can't help you... your aura is gone... you must be dead.")
    input("To prove me wrong, press enter")
else:
    input("press enter to exit")

input("press enter to exit")
