from random import choice,randint

def printListAsString(text):				# because strings are immutable, concatenating 100s of times didn't seem like a good choice
	for word in text:
		print(word,sep='',end='')
	print()						# newline

#% 2. Binary strings:
binary = ['0','1']

for length in range(250,500,5):				# length of binary string (step by 5)		(25,50,5) for sample
	text = []
	for i in range(length):				# generate random binary string
		text.append(choice(binary))
	for i in range(0,length,5):
		printListAsString(text)			# print text
		pattern = text[i:i + randint(5,10)]	# slice text to get pattern
		printListAsString(pattern)
	
	printListAsString(text)				# print text one last time
	print("0000O")					# Pattern not found case (worst case)
