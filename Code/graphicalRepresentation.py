import matplotlib.pyplot as plt
import pandas as pd
import json

#! Time taken:
print("Time taken:")
def getAvg(path,category):
	algos = ['Naive','BoyerMoore','RabinKarp','KMP']
	d = []
	for algo in algos:
		f = open(path + category + algo + '_t.txt','r')
		line = f.read().split(',')[:-1]
		vals = [int(x) for x in line]
		avg = sum(vals) / len(vals)
		d.append(avg)
		#print(algo,":",avg,' ns')
	#print()

	return d

#// Get a list of avg of all iterations for ALL algos, for ALL categories:
path = "../Outputs/"
english = getAvg(path,"english")
binary = getAvg(path,"binary")
DNA = getAvg(path,"DNA")
random = getAvg(path,"random")

df = pd.DataFrame(
	[['English'] + english, 
	['Binary'] + binary, 
	['DNA'] + DNA, 
	['Random'] + random], 
	columns=['Category','Naive','BoyerMoore','RabinKarp','KMP'])
print(df)

df.plot(x='Category',
		kind='bar',
		stacked=False,
		title='Time taken (ns)')

plt.show(block=True)


#! Comparisons:
print("\nComparisons:")
f = open('../Outputs/comparisons.json')
comparisons = json.loads(f.read())

english = comparisons['English']
english = [english['Naive'],english['BoyerMoore'],english['RabinKarp'],english['KMP']]

binary = comparisons['Binary']
binary = [binary['Naive'],binary['BoyerMoore'],binary['RabinKarp'],binary['KMP']]

DNA = comparisons['DNA']
DNA = [DNA['Naive'],DNA['BoyerMoore'],DNA['RabinKarp'],DNA['KMP']]

random = comparisons['Random']
random = [random['Naive'],random['BoyerMoore'],random['RabinKarp'],random['KMP']]

df = pd.DataFrame(
	[['English'] + english, 
	['Binary'] + binary, 
	['DNA'] + DNA, 
	['Random'] + random], 
	columns=['Category','Naive','BoyerMoore','RabinKarp','KMP'])
print(df)

df.plot(x='Category',
		kind='bar',
		stacked=False,
		title='Comparisons (Millions)')

plt.show(block=True)
