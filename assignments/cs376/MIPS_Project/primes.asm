.text

	la $a0, request			# print string requesting value from user
	addi $v0, $0, 4
	syscall
	
	    la       $s4, size		# size of n
	    lw       $s4, 0($s4)       	# s4 = size
	    addi $v0,$0, 5		# syscall to read int
	    syscall			# v0 has value read
	    add  $s4,$0,$v0		# just up to the user value (s4)    
	    add      $s0, $0, $0       	# i = 0
	    la       $s1, array         # start address of array
	    addi $s6,$0,1		# 1 to store in each location
loop1:
	sll     $s2, $s0, 2       # byte offset for ith element
	add     $s2, $s2, $s1     # address of array[i]
	sw      $s6, 0($s2)       # put i into array[i]
	addi    $s0, $s0, 1       # increment i
	slt     $s5, $s0, $s4     # is $s0 < $s4 ?
	bne	$s5, $0, loop1    # branch if so

	# You have an array initialized to a bunch of 1s at this point.  The rest is up to you.
	# Restriction - you MUST make a function call to a special method which handles marking values as
	# not primes.  The stub for that method appears below.	
	jal cleanmult

# exit (syscall 10)
addi $v0, $zero, 10
syscall


# top of the stack has n (the value to eliminate multiples of), the array base address, and the size of the array 
cleanmult:
        #You'll need to put code here to "clean up multiples", i.e. remove any number which is the multiple of a value passed to you.  
        sll	$t3, $s4, 2	#set t3 to be in bytes
	add     $t3, $t3, $s1 	#t3 equals the end of the array (in bytes)
	addi	$t5, $zero, 4   #t5 = 1
	addi	$t0, $0, 1	#set $t0 to a comparison value of 1
	
	
	
loop2:
	addi    $t1, $s1, 0	#t1 equals address of array[i], (i.e. i = 0)
	srl	$t5, $t5, 2	#make t5 the correct size to add 1
	addi	$t5, $t5, 1	#t5 = the increment value for i.
	sll	$t5, $t5, 2	#make t5 the correct size for incrementing
	add	$t6, $t1, $t5	#check to see if the next value in the list is prime
	beq	$t6, $t3, lastcheck #if $t5 is equal to the size of the array, we need to exit the array.
	lw	$t6, 0($t6)	#check if the next value in the list is a 1 (i.e. prime)
	bne 	$t0, $t6, loop2	#If statement to check if the orignal address plus t5 is prime, if not, increment again.
	srl	$t5, $t5, 2	#set t5 to actual increment value for printing.
	li	$v0, 1		#print increment value
	move 	$a0, $t5	
	syscall
	addi 	$v0, $zero, 4	#print new line
	la	$a0, newline
	syscall
	sll	$t5, $t5, 2	#set t5 back to bytes
	
nestl2:

	sw 	$0, 0($t1)	#set the array[i] equal to 0.
	slt	$t4, $t3, $t1   #while i is less than end of the array, loop.
	add	$t1, $t5, $t1	#increment i.
	beq     $t4, $0, nestl2	#if i < t3(end of the array) i+=t5; else loop
	add	$t7, $s1, $t5	#i += t5 (increment value)
	bne	$t7, $t3, loop2 #while the increment value is less than the input value, loop.
lastcheck:
	beq	$t0, $t6, btp 	#check if the last value is prime Jump to btp (back to program) if it's not.
	srl	$t5, $t5, 2	#divide by 4 before printing the value
	li	$v0, 1		#print the last value if it is prime
	move 	$a0, $t5	
	syscall

btp:
	jr	$ra
	

.data
newline:  .asciiz "\n"		#store the newline character, for output format. When I stored this at the bottom of .data, it got overrun by the array.
size:          .word  10000			  # size = 10000
			.align 4              # align a to start on an even word boundary
                                  #    this is important!
array:          .space 40000			  # Allocate 1000 words (4000 bytes)
request:  .ascii  "Please enter the max number (up to 10000):  "

