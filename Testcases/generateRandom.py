from random import choice,randint
from string import ascii_letters,digits,punctuation

def printListAsString(text):				# because strings are immutable, concatenating 100s of times didn't seem like a good choice
	for word in text:
		print(word,sep='',end='')
	print()									# newline

#% 3. Random ASCII characters:
characters = []
for i in range(100):						# generate random characters from ASCII
	characters.append(choice(ascii_letters))
	characters.append(choice(punctuation))
	characters.append(choice(digits))

for length in range(250,500,5):			# (25,50,5) for sample
	text = []
	for i in range(length):					# generate random characters from ASCII
		text.append(choice(characters))
	for i in range(0,length,5):
		printListAsString(text)				# print text
		pattern = text[i:i + randint(5,10)]				# slice text to get pattern
		printListAsString(pattern)
	
	printListAsString(text)					# print text one last time
	print("*****")							# Pattern not found case (worst case)
