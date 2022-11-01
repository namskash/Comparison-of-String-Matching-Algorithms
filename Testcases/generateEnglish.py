from random import sample

def printListAsString(text):		# because strings are immutable, concatenating 100s of times didn't seem like a good choice
	for word in text[:-1]:
		print(word,sep='',end=' ')
	print(text[-1])					# to avoid empty space after last word

#% 1. English words:
f = open("englishWords.txt")
words = []
for line in f:						# read ALL 1000 words from englishWords.txt
	line = line.strip()				# removes \n
	words.append(line)

for length in range(5,10):			# length of text in words
	text = sample(words,length)		# generate random text with "length" number of words
	for pattern in text:
		printListAsString(text)		# print text every time 
		print(pattern)				# print pattern

	printListAsString(text)			# print text one last time
	print("patternn")				# Pattern not found case (worst case)