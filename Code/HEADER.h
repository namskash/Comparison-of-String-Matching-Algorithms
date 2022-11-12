#ifndef HEADER_H
#define HEADER_H

using namespace std;

// driver:
typedef struct data
{
	int comparisons;
	long long time;
	//int fails;
}_data;

void runAlgos_English(unordered_map<string,_data> &english);
void runAlgos_Binary(unordered_map<string,_data> &binary);
void runAlgos_DNA(unordered_map<string,_data> &DNA);
void runAlgos_Random(unordered_map<string,_data> &random);
void writeToFile(
					unordered_map<string,_data> &english,
					unordered_map<string,_data> &binary,
					unordered_map<string,_data> &DNA,
					unordered_map<string,_data> &random
				);
// server:
int Naive(string text,string pattern,int &comparisons);
int acceleratedNaive(string text,string pattern,int &comparisons);
int boyerMoore(string text, string pattern,int &comparisons);
int rabinKarp(string text,string pattern,int q,int &comparisons);
int fsm(string text, string pattern,int &comparisons);
int kmp_match(string text,string pattern,int &comparisons);
int suffixTrieSearch(string text,string pattern);

// misc:


#endif
