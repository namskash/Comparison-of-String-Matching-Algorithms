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

void runAlgos_English(unordered_map<string,_data> &english)
{
	string text;
	string pattern;
	int comparisons = 0;

	// Initialise all:
	english["Naive"] = {0,0};
	//english["AccelratedNaive"] = {0,0};	// Not a good case for accelerated naive
	english["BoyerMoore"] = {0,0};
	english["RabinKarp"] = {0,0};
	english["FSM"] = {0,0};
	english["KMP"] = {0,0};
	english["SuffixTrie"] = {0,0};

	ifstream fin;
	fin.open("../Testcases/english.txt");

//#1. Naive
	auto start = high_resolution_clock::now();	// get accurate start clock time
	
	while(getline(fin,text))		// get pattern for every string
	{
		getline(fin,pattern);
		Naive(text,pattern,comparisons);
	}

	auto stop = high_resolution_clock::now();	// get accurate stop clock time
	microseconds duration = duration_cast<microseconds>(stop - start);

	english["Naive"].comparisons += comparisons;
	english["Naive"].time += duration.count();

	cout<<"Naive time taken : "<<english["Naive"].time<<" ns\t\t";
	cout<<"Naive comparisons: "<<english["Naive"].comparisons<<"\n";

//#3. Boyer Moore
	fin.clear();
	fin.seekg(0);
	comparisons = 0;
	
	start = high_resolution_clock::now();	// get accurate start clock time
	
	while(getline(fin,text))		// get pattern for every string
	{
		getline(fin,pattern);
		boyerMoore(text,pattern,comparisons);
	}

	stop = high_resolution_clock::now();	// get accurate stop clock time
	duration = duration_cast<microseconds>(stop - start);

	english["BoyerMoore"].comparisons += comparisons;
	english["BoyerMoore"].time += duration.count();

	cout<<"Boyer Moore time taken : "<<english["BoyerMoore"].time<<" ns\t";
	cout<<"Boyer Moore comparisons: "<<english["BoyerMoore"].comparisons<<"\n";

//#4. Rabin Karp
	fin.clear();
	fin.seekg(0);
	comparisons = 0;
	
	start = high_resolution_clock::now();	// get accurate start clock time
	
	while(getline(fin,text))		// get pattern for every string
	{
		getline(fin,pattern);
		rabinKarp(text,pattern,223,comparisons);
	}

	stop = high_resolution_clock::now();	// get accurate stop clock time
	duration = duration_cast<microseconds>(stop - start);

	english["RabinKarp"].comparisons += comparisons;
	english["RabinKarp"].time += duration.count();

	cout<<"Rabin Karp time taken : "<<english["RabinKarp"].time<<" ns\t";
	cout<<"Rabin Karp comparisons: "<<english["RabinKarp"].comparisons<<"\n";

//#5. FSM
	fin.clear();
	fin.seekg(0);
	comparisons = 0;
	
	start = high_resolution_clock::now();	// get accurate start clock time
	
	while(getline(fin,text))		// get pattern for every string
	{
		getline(fin,pattern);
		fsm(text,pattern,comparisons);
	}

	stop = high_resolution_clock::now();	// get accurate stop clock time
	duration = duration_cast<microseconds>(stop - start);

	english["FSM"].comparisons += comparisons;
	english["FSM"].time += duration.count();

	cout<<"FSM time taken : "<<english["FSM"].time<<" ns\t\t";
	cout<<"FSM comparisons: "<<english["FSM"].comparisons<<"\n";

//#6. KMP
	fin.clear();
	fin.seekg(0);
	comparisons = 0;
	
	start = high_resolution_clock::now();	// get accurate start clock time
	
	while(getline(fin,text))		// get pattern for every string
	{
		getline(fin,pattern);
		kmp_match(text,pattern,comparisons);
	}

	stop = high_resolution_clock::now();	// get accurate stop clock time
	duration = duration_cast<microseconds>(stop - start);

	english["KMP"].comparisons += comparisons;
	english["KMP"].time += duration.count();

	cout<<"KMP time taken : "<<english["KMP"].time<<" ns\t\t";
	cout<<"KMP comparisons: "<<english["KMP"].comparisons<<"\n";
	
	fin.close();
}

void runAlgos_Binary(unordered_map<string,_data> &binary)
{
	string text;
	string pattern;
	int comparisons = 0;

	// Initialise all:
	binary["Naive"] = {0,0};
	//binary["AccelratedNaive"] = {0,0};	// Not a good case for accelerated naive
	binary["BoyerMoore"] = {0,0};
	binary["RabinKarp"] = {0,0};
	binary["FSM"] = {0,0};
	binary["KMP"] = {0,0};
	binary["SuffixTrie"] = {0,0};

	ifstream fin;
	fin.open("../Testcases/binary.txt");

//#1. Naive
	auto start = high_resolution_clock::now();	// get accurate start clock time
	
	while(getline(fin,text))		// get pattern for every string
	{
		getline(fin,pattern);
		Naive(text,pattern,comparisons);
	}

	auto stop = high_resolution_clock::now();	// get accurate stop clock time
	microseconds duration = duration_cast<microseconds>(stop - start);

	binary["Naive"].comparisons += comparisons;
	binary["Naive"].time += duration.count();

	cout<<"Naive time taken : "<<binary["Naive"].time<<" ns\t\t";
	cout<<"Naive comparisons: "<<binary["Naive"].comparisons<<"\n";

//#3. Boyer Moore
	fin.clear();
	fin.seekg(0);
	comparisons = 0;

	start = high_resolution_clock::now();	// get accurate start clock time
	
	while(getline(fin,text))		// get pattern for every string
	{
		getline(fin,pattern);
		boyerMoore(text,pattern,comparisons);
	}

	stop = high_resolution_clock::now();	// get accurate stop clock time
	duration = duration_cast<microseconds>(stop - start);

	binary["BoyerMoore"].comparisons += comparisons;
	binary["BoyerMoore"].time += duration.count();

	cout<<"Boyer Moore time taken : "<<binary["BoyerMoore"].time<<" ns\t";
	cout<<"Boyer Moore comparisons: "<<binary["BoyerMoore"].comparisons<<"\n";

//#4. Rabin Karp
	fin.clear();
	fin.seekg(0);
	comparisons = 0;
	
	start = high_resolution_clock::now();	// get accurate start clock time
	
	while(getline(fin,text))		// get pattern for every string
	{
		getline(fin,pattern);
		rabinKarp(text,pattern,223,comparisons);
	}

	stop = high_resolution_clock::now();	// get accurate stop clock time
	duration = duration_cast<microseconds>(stop - start);

	binary["RabinKarp"].comparisons += comparisons;
	binary["RabinKarp"].time += duration.count();

	cout<<"Rabin Karp time taken : "<<binary["RabinKarp"].time<<" ns\t";
	cout<<"Rabin Karp comparisons: "<<binary["RabinKarp"].comparisons<<"\n";

//#5. FSM
	fin.clear();
	fin.seekg(0);
	comparisons = 0;
	
	start = high_resolution_clock::now();	// get accurate start clock time
	
	while(getline(fin,text))		// get pattern for every string
	{
		getline(fin,pattern);
		fsm(text,pattern,comparisons);
	}

	stop = high_resolution_clock::now();	// get accurate stop clock time
	duration = duration_cast<microseconds>(stop - start);

	binary["FSM"].comparisons += comparisons;
	binary["FSM"].time += duration.count();

	cout<<"FSM time taken: "<<binary["FSM"].time<<" ns\t\t";
	cout<<"FSM comparisons: "<<binary["FSM"].comparisons<<"\n";

//#6. KMP
	fin.clear();
	fin.seekg(0);
	comparisons = 0;
	
	start = high_resolution_clock::now();	// get accurate start clock time
	
	while(getline(fin,text))		// get pattern for every string
	{
		getline(fin,pattern);
		kmp_match(text,pattern,comparisons);
	}

	stop = high_resolution_clock::now();	// get accurate stop clock time
	duration = duration_cast<microseconds>(stop - start);

	binary["KMP"].comparisons += comparisons;
	binary["KMP"].time += duration.count();

	cout<<"KMP time taken: "<<binary["KMP"].time<<" ns\t\t";
	cout<<"KMP comparisons: "<<binary["KMP"].comparisons<<"\n";
	
	fin.close();
}

void runAlgos_DNA(unordered_map<string,_data> &DNA)
{
	string text;
	string pattern;
	int comparisons = 0;
	
	// Initialise all:
	DNA["Naive"] = {0,0};
	//DNA["AccelratedNaive"] = {0,0};	// Not a good case for accelerated naive
	DNA["BoyerMoore"] = {0,0};
	DNA["RabinKarp"] = {0,0};
	DNA["FSM"] = {0,0};
	DNA["KMP"] = {0,0};
	DNA["SuffixTrie"] = {0,0};

	ifstream fin;
	fin.open("../Testcases/DNA.txt");

//#1. Naive
	auto start = high_resolution_clock::now();	// get accurate start clock time
	
	while(getline(fin,text))		// get pattern for every string
	{
		getline(fin,pattern);
		Naive(text,pattern,comparisons);
	}

	auto stop = high_resolution_clock::now();	// get accurate stop clock time
	microseconds duration = duration_cast<microseconds>(stop - start);

	DNA["Naive"].comparisons += comparisons;
	DNA["Naive"].time += duration.count();

	cout<<"Naive time taken : "<<DNA["Naive"].time<<" ns\t\t";
	cout<<"Naive comparisons: "<<DNA["Naive"].comparisons<<"\n";

//#3. Boyer Moore
	fin.clear();
	fin.seekg(0);
	comparisons = 0;

	start = high_resolution_clock::now();	// get accurate start clock time
	
	while(getline(fin,text))		// get pattern for every string
	{
		getline(fin,pattern);
		boyerMoore(text,pattern,comparisons);
	}

	stop = high_resolution_clock::now();	// get accurate stop clock time
	duration = duration_cast<microseconds>(stop - start);

	DNA["BoyerMoore"].comparisons += comparisons;
	DNA["BoyerMoore"].time += duration.count();

	cout<<"Boyer Moore time taken : "<<DNA["BoyerMoore"].time<<" ns\t";
	cout<<"Boyer Moore comparisons: "<<DNA["BoyerMoore"].comparisons<<"\n";

//#4. Rabin Karp
	fin.clear();
	fin.seekg(0);
	comparisons = 0;
	
	start = high_resolution_clock::now();	// get accurate start clock time
	
	while(getline(fin,text))		// get pattern for every string
	{
		getline(fin,pattern);
		rabinKarp(text,pattern,223,comparisons);
	}

	stop = high_resolution_clock::now();	// get accurate stop clock time
	duration = duration_cast<microseconds>(stop - start);

	DNA["RabinKarp"].comparisons += comparisons;
	DNA["RabinKarp"].time += duration.count();

	cout<<"Rabin Karp time taken : "<<DNA["RabinKarp"].time<<" ns\t";
	cout<<"Rabin Karp comparisons: "<<DNA["RabinKarp"].comparisons<<"\n";

//#5. FSM
	fin.clear();
	fin.seekg(0);
	comparisons = 0;
	
	start = high_resolution_clock::now();	// get accurate start clock time
	
	while(getline(fin,text))		// get pattern for every string
	{
		getline(fin,pattern);
		fsm(text,pattern,comparisons);
	}

	stop = high_resolution_clock::now();	// get accurate stop clock time
	duration = duration_cast<microseconds>(stop - start);

	DNA["FSM"].comparisons += comparisons;
	DNA["FSM"].time += duration.count();

	cout<<"FSM time taken : "<<DNA["FSM"].time<<" ns\t\t";
	cout<<"FSM comparisons: "<<DNA["FSM"].comparisons<<"\n";

//#6. KMP
	fin.clear();
	fin.seekg(0);
	comparisons = 0;
	
	start = high_resolution_clock::now();	// get accurate start clock time
	
	while(getline(fin,text))		// get pattern for every string
	{
		getline(fin,pattern);
		kmp_match(text,pattern,comparisons);
	}

	stop = high_resolution_clock::now();	// get accurate stop clock time
	duration = duration_cast<microseconds>(stop - start);

	DNA["KMP"].comparisons += comparisons;
	DNA["KMP"].time += duration.count();

	cout<<"KMP time taken : "<<DNA["KMP"].time<<" ns\t\t";
	cout<<"KMP comparisons: "<<DNA["KMP"].comparisons<<"\n";
	
	fin.close();
}

void runAlgos_Random(unordered_map<string,_data> &random)
{
	string text;
	string pattern;
	int comparisons = 0;

	// Initialise all:
	random["Naive"] = {0,0};
	//random["AccelratedNaive"] = {0,0};	// Not a good case for accelerated naive
	random["BoyerMoore"] = {0,0};
	random["RabinKarp"] = {0,0};
	random["FSM"] = {0,0};
	random["KMP"] = {0,0};
	random["SuffixTrie"] = {0,0};

	ifstream fin;
	fin.open("../Testcases/random.txt");

//#1. Naive
	auto start = high_resolution_clock::now();	// get accurate start clock time
	
	while(getline(fin,text))		// get pattern for every string
	{
		getline(fin,pattern);
		Naive(text,pattern,comparisons);
	}

	auto stop = high_resolution_clock::now();	// get accurate stop clock time
	microseconds duration = duration_cast<microseconds>(stop - start);

	random["Naive"].comparisons += comparisons;
	random["Naive"].time += duration.count();

	cout<<"Naive time taken : "<<random["Naive"].time<<" ns\t\t";
	cout<<"Naive comparisons: "<<random["Naive"].comparisons<<"\n";

//#3. Boyer Moore
	fin.clear();
	fin.seekg(0);
	comparisons = 0;

	start = high_resolution_clock::now();	// get accurate start clock time
	
	while(getline(fin,text))		// get pattern for every string
	{
		getline(fin,pattern);
		boyerMoore(text,pattern,comparisons);
	}

	stop = high_resolution_clock::now();	// get accurate stop clock time
	duration = duration_cast<microseconds>(stop - start);

	random["BoyerMoore"].comparisons += comparisons;
	random["BoyerMoore"].time += duration.count();

	cout<<"Boyer Moore time taken : "<<random["BoyerMoore"].time<<" ns\t";
	cout<<"Boyer Moore comparisons: "<<random["BoyerMoore"].comparisons<<"\n";

//#4. Rabin Karp
	fin.clear();
	fin.seekg(0);
	comparisons = 0;
	
	start = high_resolution_clock::now();	// get accurate start clock time
	
	while(getline(fin,text))		// get pattern for every string
	{
		getline(fin,pattern);
		rabinKarp(text,pattern,223,comparisons);
	}

	stop = high_resolution_clock::now();	// get accurate stop clock time
	duration = duration_cast<microseconds>(stop - start);

	random["RabinKarp"].comparisons += comparisons;
	random["RabinKarp"].time += duration.count();

	cout<<"Rabin Karp time taken : "<<random["RabinKarp"].time<<" ns\t";
	cout<<"Rabin Karp comparisons: "<<random["RabinKarp"].comparisons<<"\n";

//#5. FSM
	fin.clear();
	fin.seekg(0);
	comparisons = 0;
	
	start = high_resolution_clock::now();	// get accurate start clock time
	
	while(getline(fin,text))		// get pattern for every string
	{
		getline(fin,pattern);
		fsm(text,pattern,comparisons);
	}

	stop = high_resolution_clock::now();	// get accurate stop clock time
	duration = duration_cast<microseconds>(stop - start);

	random["FSM"].comparisons += comparisons;
	random["FSM"].time += duration.count();

	cout<<"FSM time taken : "<<random["FSM"].time<<" ns\t\t";
	cout<<"FSM comparisons: "<<random["FSM"].comparisons<<"\n";

//#6. KMP
	fin.clear();
	fin.seekg(0);
	comparisons = 0;
	
	start = high_resolution_clock::now();	// get accurate start clock time
	
	while(getline(fin,text))		// get pattern for every string
	{
		getline(fin,pattern);
		kmp_match(text,pattern,comparisons);
	}

	stop = high_resolution_clock::now();	// get accurate stop clock time
	duration = duration_cast<microseconds>(stop - start);

	random["KMP"].comparisons += comparisons;
	random["KMP"].time += duration.count();

	cout<<"KMP time taken : "<<random["KMP"].time<<" ns\t\t";
	cout<<"KMP comparisons: "<<random["KMP"].comparisons<<"\n";
	
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
	fout.open("../Testcases/englishOutput.txt");

	fout.close();
}

int main()
{
	unordered_map<string,_data> english; // Each category: {# of key comparisons, time}
	unordered_map<string,_data> binary;
	unordered_map<string,_data> DNA;
	unordered_map<string,_data> random;

	cout<<"English:\n";
	runAlgos_English(english);
	cout<<"\nBinary:\n";
	runAlgos_Binary(binary);
	cout<<"\nDNA:\n";
	runAlgos_DNA(DNA);
	cout<<"\nRandom:\n";
	runAlgos_Random(random);

	// writeToFile(categories); // Write the output to your file

	return 0;
}
