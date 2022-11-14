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
	english["BoyerMoore"] = {0,0};
	english["RabinKarp"] = {0,0};
	english["FSM"] = {0,0};
	english["KMP"] = {0,0};

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

	cout<<"Naive\t\t: "<<english["Naive"].time<<"  ns "<<english["Naive"].comparisons<<" comparisons\n";

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

	cout<<"Boyer Moore\t: "<<english["BoyerMoore"].time<<"  ns "<<english["BoyerMoore"].comparisons<<" comparisons\n";

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

	cout<<"Rabin Karp\t: "<<english["RabinKarp"].time<<"  ns "<<english["RabinKarp"].comparisons<<" comparisons\n";

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

	cout<<"FSM\t\t\t: "<<english["FSM"].time<<" ns "<<english["FSM"].comparisons<<" comparisons\n";

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

	cout<<"KMP\t\t\t: "<<english["KMP"].time<<"  ns "<<english["KMP"].comparisons<<" comparisons\n";
	
	fin.close();
}

void runAlgos_Binary(unordered_map<string,_data> &binary)
{
	string text;
	string pattern;
	int comparisons = 0;

	// Initialise all:
	binary["Naive"] = {0,0};
	binary["BoyerMoore"] = {0,0};
	binary["RabinKarp"] = {0,0};
	binary["FSM"] = {0,0};
	binary["KMP"] = {0,0};

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

	cout<<"Naive\t\t: "<<binary["Naive"].time<<"  ns "<<binary["Naive"].comparisons<<" comparisons\n";

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

	cout<<"Boyer Moore\t: "<<binary["BoyerMoore"].time<<"  ns "<<binary["BoyerMoore"].comparisons<<" comparisons\n";

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

	cout<<"Rabin Karp\t: "<<binary["RabinKarp"].time<<"  ns "<<binary["RabinKarp"].comparisons<<" comparisons\n";

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

	cout<<"FSM\t\t\t: "<<binary["FSM"].time<<" ns "<<binary["FSM"].comparisons<<" comparisons\n";

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

	cout<<"KMP\t\t\t: "<<binary["KMP"].time<<"  ns "<<binary["KMP"].comparisons<<" comparisons\n";
	
	fin.close();
}

void runAlgos_DNA(unordered_map<string,_data> &DNA)
{
	string text;
	string pattern;
	int comparisons = 0;
	
	// Initialise all:
	DNA["Naive"] = {0,0};
	DNA["BoyerMoore"] = {0,0};
	DNA["RabinKarp"] = {0,0};
	DNA["FSM"] = {0,0};
	DNA["KMP"] = {0,0};

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

	cout<<"Naive\t\t: "<<DNA["Naive"].time<<"  ns "<<DNA["Naive"].comparisons<<" comparisons\n";

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

	cout<<"Boyer Moore\t: "<<DNA["BoyerMoore"].time<<"  ns "<<DNA["BoyerMoore"].comparisons<<" comparisons\n";

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

	cout<<"Rabin Karp\t: "<<DNA["RabinKarp"].time<<"  ns "<<DNA["RabinKarp"].comparisons<<" comparisons\n";

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

	cout<<"FSM\t\t\t: "<<DNA["FSM"].time<<" ns "<<DNA["FSM"].comparisons<<" comparisons\n";

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

	cout<<"KMP\t\t\t: "<<DNA["KMP"].time<<"  ns "<<DNA["KMP"].comparisons<<" comparisons\n";
	
	fin.close();
}

void runAlgos_Random(unordered_map<string,_data> &random)
{
	string text;
	string pattern;
	int comparisons = 0;

	// Initialise all:
	random["Naive"] = {0,0};
	random["BoyerMoore"] = {0,0};
	random["RabinKarp"] = {0,0};
	random["FSM"] = {0,0};
	random["KMP"] = {0,0};

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

	cout<<"Naive\t\t: "<<random["Naive"].time<<"  ns "<<random["Naive"].comparisons<<" comparisons\n";

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

	cout<<"Boyer Moore\t: "<<random["BoyerMoore"].time<<"  ns "<<random["BoyerMoore"].comparisons<<" comparisons\n";

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

	cout<<"Rabin Karp\t: "<<random["RabinKarp"].time<<"  ns "<<random["RabinKarp"].comparisons<<" comparisons\n";

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

	cout<<"FSM\t\t\t: "<<random["FSM"].time<<" ns "<<random["FSM"].comparisons<<" comparisons\n";

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

	cout<<"KMP\t\t\t: "<<random["KMP"].time<<"  ns "<<random["KMP"].comparisons<<" comparisons\n";
	
	fin.close();
}

static void _write(string path,unordered_map<string,_data> &data)
{

	string t = "_t";	// time
	string c = "_c";	// comparisons
	
//// temp variables that change in every iteration:
	string algoType;
	int time;
	int comparisons;

// uncomment to append to all output text files:
	for(auto i:data)
	{
		algoType = i.first;
		time = i.second.time;
		comparisons = i.second.comparisons;


		ofstream fout_t(path + algoType + t + ".txt",ios_base::app);
		fout_t<<time<<", ";
		fout_t.close();

		ofstream fout_c(path + algoType + c + ".txt",ios_base::app);
		fout_c<<comparisons<<", ";
		fout_t.close();

	}

// uncomment to clear all output text files:
	#if 0
	for(auto i:data)
	{
		algoType = i.first;
		time = i.second.time;
		comparisons = i.second.comparisons;

		ofstream fout_t(path + algoType + t + ".txt",ofstream::out | ofstream::trunc);
		fout_t.close();
	}
	#endif
}

void writeToFile(
					unordered_map<string,_data> &english,
					unordered_map<string,_data> &binary,
					unordered_map<string,_data> &DNA,
					unordered_map<string,_data> &random
				)
{
	_write("../Outputs/english",english);
	_write("../Outputs/binary",binary);
	_write("../Outputs/DNA",DNA);
	_write("../Outputs/random",random);
	
}

int main()
{
	unordered_map<string,_data> english; // Each category: {# of key comparisons  time}
	unordered_map<string,_data> binary;
	unordered_map<string,_data> DNA;
	unordered_map<string,_data> random;

	for(int i=0;i<5;++i)
	{
		cout<<"Iteration "<<i+1<<":\n";
		cout<<"English:\n";
		runAlgos_English(english);
		cout<<"\nBinary:\n";
		runAlgos_Binary(binary);
		cout<<"\nDNA:\n";
		runAlgos_DNA(DNA);
		cout<<"\nRandom:\n";
		runAlgos_Random(random);
		writeToFile(english,binary,DNA,random); // Write the output to your file
		cout<<"\n\n";
	}

	return 0;
}
