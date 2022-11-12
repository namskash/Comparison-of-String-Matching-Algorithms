from string import printable

def printListAsString(text):				# because strings are immutable, concatenating 100s of times didn't seem like a good choice
	for char in text:
		print(char,sep='',end='')
	print()									# newline

text = []
for char in printable:
	if char not in ('\n','','','\t',' ','\r'):
		text.append(char)

for i in range(len(text) - 6):
	printListAsString(text)
	pattern = text[i:i+5]
	printListAsString(pattern)
