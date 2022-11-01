#include<iostream>
#include<fstream>
#include<unordered_map>
#include<vector>
#include<assert.h>
#include<stdbool.h>
#include"HEADER.h"

#include <chrono>	// time measurement

using namespace std::chrono;
using namespace std;

void func(string text,string pattern,int &count)
{
	
}

void runAlgos_English(unordered_map<string,_data> &english, int &comparisons)
{
	string text;
	string pattern;
	int pos;
	int fails;

	// Initialise all:
	english["Naive"] = {0,0,0};
	//english["AccelratedNaive"] = {0,0,0};	// Not a good case for accelerated naive
	english["BoyerMoore"] = {0,0,0};
	english["RabinKarp"] = {0,0,0};
	english["FSM"] = {0,0,0};
	english["KMP"] = {0,0,0};
	english["SuffixTrie"] = {0,0,0};

	ifstream fin;
	fin.open("D:/NK/PES CS Engineering/Sem V/AA/Project/Testcases/english.txt");

//#1. Naive
	auto start = high_resolution_clock::now();	// get accurate start clock time
	
	while(getline(fin,text))		// get pattern for every string
	{
		getline(fin,pattern);
		Naive(text,pattern);
	}

	auto stop = high_resolution_clock::now();	// get accurate stop clock time
	microseconds duration = duration_cast<microseconds>(stop - start);

	//english["Naive"].comparisons += comparisons;
	english["Naive"].time += duration.count();

	cout<<"Naive time taken: "<<english["Naive"].time<<endl;

//#3. Boyer Moore
	fin.clear();
	fin.seekg(0);

	start = high_resolution_clock::now();	// get accurate start clock time
	
	while(getline(fin,text))		// get pattern for every string
	{
		getline(fin,pattern);
		boyerMoore(text,pattern);
	}

	stop = high_resolution_clock::now();	// get accurate stop clock time
	duration = duration_cast<microseconds>(stop - start);

	//english["BoyerMoore"].comparisons += comparisons;
	english["BoyerMoore"].time += duration.count();

	cout<<"Boyer Moore time taken: "<<english["BoyerMoore"].time<<endl;

	rabinKarp("thisistext","text",13);
	fsm("thisistext","text");

//#4. Rabin Karp
	fin.clear();
	fin.seekg(0);
	
	start = high_resolution_clock::now();	// get accurate start clock time
	
	while(getline(fin,text))		// get pattern for every string
	{
		getline(fin,pattern);
		rabinKarp(text,pattern,223);
	}

	stop = high_resolution_clock::now();	// get accurate stop clock time
	duration = duration_cast<microseconds>(stop - start);

	//english["RabinKarp"].comparisons += comparisons;
	english["RabinKarp"].time += duration.count();

	cout<<"Rabin Karp time taken: "<<english["RabinKarp"].time<<endl;

//#5. FSM
	fin.clear();
	fin.seekg(0);
	
	start = high_resolution_clock::now();	// get accurate start clock time
	
	while(getline(fin,text))		// get pattern for every string
	{
		getline(fin,pattern);
		fsm(text,pattern);
	}

	stop = high_resolution_clock::now();	// get accurate stop clock time
	duration = duration_cast<microseconds>(stop - start);

	//english["RabinKarp"].comparisons += comparisons;
	english["FSM"].time += duration.count();

	cout<<"FSM time taken: "<<english["FSM"].time<<endl;

//#5. KMP
	fin.clear();
	fin.seekg(0);
	
	start = high_resolution_clock::now();	// get accurate start clock time
	
	while(getline(fin,text))		// get pattern for every string
	{
		getline(fin,pattern);
		kmp_match(text,pattern);
	}

	stop = high_resolution_clock::now();	// get accurate stop clock time
	duration = duration_cast<microseconds>(stop - start);

	//english["RabinKarp"].comparisons += comparisons;
	english["KMP"].time += duration.count();

	cout<<"KMP time taken: "<<english["KMP"].time<<endl;


	fin.close();
}

void runAlgos_Binary(unordered_map<string,_data> &binary, int &comparisons)
{
	ifstream fin;
	fin.open("D:/NK/PES CS Engineering/Sem V/AA/Project/Testcases/binarySample.txt");

	string text;
	string pattern;
	int count = 0;
	while(getline(fin,text))		// get pattern for every string
	{
		getline(fin,pattern);
		int pos = Naive(text,pattern);	// pass to function
	}
	fin.close();
}

void runAlgos_DNA(unordered_map<string,_data> &DNA, int &comparisons)
{
	ifstream fin;
	fin.open("D:/NK/PES CS Engineering/Sem V/AA/Project/Testcases/DNASample.txt");

	string text;
	string pattern;
	int count = 0;
	while(getline(fin,text))		// get pattern for every string
	{
		getline(fin,pattern);
		func(text,pattern,count);	// pass to function
	}
	fin.close();
}

void runAlgos_Random(unordered_map<string,_data> &random, int &comparisons)
{
	ifstream fin;
	fin.open("D:/NK/PES CS Engineering/Sem V/AA/Project/Testcases/randomSample.txt");

	string text;
	string pattern;
	int count = 0;
	while(getline(fin,text))		// get pattern for every string
	{
		getline(fin,pattern);
		func(text,pattern,count);	// pass to function
	}
	fin.close();
}

void writeToFile(
					unordered_map<string,_data> &english,
					unordered_map<string,_data> &binary,
					unordered_map<string,_data> &DNA,
					unordered_map<string,_data> &random
				)
{
	ofstream fout;
	fout.open("D:/NK/PES CS Engineering/Sem V/AA/Project/Testcases/englishOutput.txt");

	fout.close();
}

int main()
{
	unordered_map<string,_data> english; // Each category: {# of key comparisons, time}
	unordered_map<string,_data> binary;
	unordered_map<string,_data> DNA;
	unordered_map<string,_data> random;
	int comparisonsEnglish = 0;
	int comparisonsBinary = 0;
	int comparisonsDNA = 0;
	int comparisonsRandom = 0;

	cout<<"English:\n";
	runAlgos_English(english,comparisonsEnglish);
	//runAlgos_Binary(binary,comparisonsBinary);
	//runAlgos_DNA(DNA,comparisonsDNA);
	//runAlgos_Random(random,comparisonsRandom);

	// writeToFile(categories); // Write the output to your file

	return 0;
}
