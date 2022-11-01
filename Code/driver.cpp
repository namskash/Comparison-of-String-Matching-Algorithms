#include<iostream>
#include<fstream>
#include<unordered_map>
#include<vector>
#include<assert.h>
#include"HEADER.h"

#include <chrono>	// time measurement

using namespace std::chrono;
using namespace std;

void func(string text,string pattern,int &count)
{
	
}

void runAlgos_English(unordered_map<string,vector<_data>> &english, int &comparisons)
{
	string text;
	string pattern;
	int pos;
	int failures;

	ifstream fin;
	fin.open("D:/NK/PES CS Engineering/Sem V/AA/Project/Testcases/englishSample.txt");

	auto start = high_resolution_clock::now();	// get accurate start clock time

	while(getline(fin,text))		// get pattern for every string
	{
		getline(fin,pattern);
		int pos = 0;
		
		if(Naive(text,pattern) != pos)
		{
			
		}
	}
	fin.close();

	auto stop = high_resolution_clock::now();	// get accurate stop clock time
	microseconds duration = duration_cast<microseconds>(stop - start);
	cout<<"Naive time taken: "<<duration.count()<<endl;
	english["Naive"].push_back({comparisons,duration.count()});

}

void runAlgos_Binary(unordered_map<string,vector<_data>> &binary, int &comparisons)
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

void runAlgos_DNA(unordered_map<string,vector<_data>> &DNA, int &comparisons)
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

void runAlgos_Random(unordered_map<string,vector<_data>> &random, int &comparisons)
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
					unordered_map<string,vector<_data>> &english,
					unordered_map<string,vector<_data>> &binary,
					unordered_map<string,vector<_data>> &DNA,
					unordered_map<string,vector<_data>> &random
				)
{
	ofstream fout;
	fout.open("D:/NK/PES CS Engineering/Sem V/AA/Project/Testcases/englishOutput.txt");

	fout.close();
}

int main()
{
	unordered_map<string,vector<_data>> english; // Each category: {# of key comparisons, time}
	unordered_map<string,vector<_data>> binary;
	unordered_map<string,vector<_data>> DNA;
	unordered_map<string,vector<_data>> random;
	int comparisonsEnglish = 0;
	int comparisonsBinary = 0;
	int comparisonsDNA = 0;
	int comparisonsRandom = 0;

	runAlgos_English(english,comparisonsEnglish);
	//runAlgos_Binary(binary,comparisonsBinary);
	//runAlgos_DNA(DNA,comparisonsDNA);
	//runAlgos_Random(random,comparisonsRandom);

	// writeToFile(categories); // Write the output to your file

	return 0;
}