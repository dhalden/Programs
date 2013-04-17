#Flip a coin 100 times
#Derek Halden
#simulates flipping a coin 100 times

import random
count = 0
heads = 0
tails = 0

while count != 10000:
	count += 1
	coin_flip = random.randint(1,2)
	if coin_flip == 1:
		heads += 1
tails = count - heads
print("Heads came up: ",heads," times")
print("tails came up: ",tails," times")

