# The goal overall goal of this project, is to create a program that outputs an
# orbit diagram. This part of the program will have the simple task of creating
# a list of the iterations, as it iterates them.
import math
import numpy as np
import matplotlib.pyplot as plt
from pylab import *

def iterate(r):
	#This will iterate the function and create a list of the fixed points or 
	#the periodic orbit.
	
	#keeps track of how many iterations have occured
	iteration = 0
	nthIterate = .2
	#this is the variable that will change, and be logged in to a list
	#note that this will be the seed.
	
	fixedPoints = []
	orbit = []
	#If the answer can't be decided within a certain number of iterations the 
	#program will stop iterating
	inconclusive = False
	ordered = 0
	attractToZero = False
	oneHalf = False
	while orbit.count(nthIterate) == 0:
		
		
		#add the iterate to the list
		orbit.append(nthIterate)
		#print(nthIterate)
		
		#actual iteration
		#note that this line should be able to use any equation to iterate
		#currenlty this is the logistic equation, but again, it should be
		#able to use anything
		nthIterate = r*nthIterate - (r*math.pow(nthIterate, 2)) 
		iteration += 1
		
		if abs(nthIterate - .5) <= .0000001:
			oneHalf = True
			break
		
		if iteration >= 500:
			inconclusive = True
			break
			
		if nthIterate <= .01:
			attractToZero = True
			break
	
	if oneHalf == True:
		orbit.append(nthIterate)
		fixedPoints = orbit[(orbit.index(nthIterate)):]
	elif attractToZero == True:
		fixedPoints.append(0)
	
		
	return fixedPoints
	
	
def checkForPeriod(orbit):
	check = .000000000001
	beginningOfPeriod = 0
	endOfPeriod = len(orbit)
	for t in range(len(orbit)):
		for s in range(t + 1,len(orbit) , 1):
			if abs((orbit[t] - orbit[s])) <= check:
				check = abs(orbit[t] - orbit[s])
				if t >= 0:
					beginningOfPeriod = t
				if s <= len(orbit):
					endOfPeriod = s
	orbit = orbit[beginningOfPeriod:endOfPeriod]
	return orbit
				

	
	

i = 3.23
fixedPoints = {}
feigenbaumlist = {}
referenceToFeigenbaumList = []
#insure that orbits are periodic, or if they aren't it makes them
#periodic (unless they're chaotic)
while i < 3.5706:
#first the equation needs to be iterated
 	fixedPoints[i] = iterate(i)
 	if len(fixedPoints[i]) > 1 and len(fixedPoints[i]) < 129:
 		fixedPoints[i] = checkForPeriod(fixedPoints[i])
 	if len(fixedPoints[i]) < 129:
 		for s in range(len(fixedPoints[i])):
 			checkForOneHalf = fixedPoints[i]
 			if abs(checkForOneHalf[s] - .5) <= .000001:
 				feigenbaumlist[i] = checkForOneHalf[s]
 				referenceToFeigenbaumList.append(i)
 				
 				
 		
 			
 	print(i)
 	i += .000001
t = 0
for t in range(len(referenceToFeigenbaumList)):
	print(referenceToFeigenbaumList[t], ':',feigenbaumlist[referenceToFeigenbaumList[t]])
	
 	
 	
