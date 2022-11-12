from random import choice,randint

def printListAsString(text):				# because strings are immutable, concatenating 100s of times didn't seem like a good choice
	for word in text:
		print(word,sep='',end='')
	print()									# newline

#% 4. DNA sequence:
DNA = ['A','T','G','C']

for length in range(250,500,5):			# (25,50,5) for sample
	text = []
	for i in range(length):
		text.append(choice(DNA))
	for i in range(0,length,5):
		printListAsString(text)				# print text
		pattern = text[i:i + randint(5,10)]				# slice text to get pattern
		printListAsString(pattern)
	
	printListAsString(text)					# print text one last time
	print("ACGTB")							# Pattern not found case (worst case)
