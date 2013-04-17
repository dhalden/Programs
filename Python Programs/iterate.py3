# The goal overall goal of this project, is to create a program that outputs an
# orbit diagram. This part of the program will have the simple task of creating
# a list of the iterations, as it iterates them.
import math


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
	while orbit.count(nthIterate) == 0:
		
		
		#add the iterate to the list
		orbit.append(nthIterate)
		#print(nthIterate)
		
		#actual iteration
		#note that this line should be able to use any equation to iterate
		nthIterate = r*nthIterate - (r*math.pow(nthIterate, 2)) 
		iteration += 1
		
		
		if iteration >= 10000:
			inconclusive = True
			break
			
		if nthIterate <= .00001:
			attractToZero = True
			break
	
	if orbit.count(nthIterate) != 0 and iteration - orbit.index(nthIterate) == 1:
		fixedPoints.append(nthIterate)		
	
	elif inconclusive == True:
		fixedPoints = orbit
		
	elif attractToZero == True:
		fixedPoints = 0
		print("Attracting to zero")
	else:
		fixedPoints = orbit[(orbit.index(nthIterate)):]
	
		
	return fixedPoints
def checkForPeriod(orbit):
	check = .000000001
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
				
	
	

i = 3.2
fixedPoints = {}
while i < 3.5:
 	fixedPoints[i] = iterate(i)
 	if len(fixedPoints[i]) > 1 and len(fixedPoints[i]) < 10000:
 		fixedPoints[i] = checkForPeriod(fixedPoints[i])
 		
 	i += .01
s = 3.2
while s < 3.5:
	print(s,":",fixedPoints[s])
	s += .01		
		
		 
	
	
	


