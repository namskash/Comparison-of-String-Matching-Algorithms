#ifndef HEADER_H
#define HEADER_H

using namespace std;

// driver:
typedef struct data
{
	int comparisons;
	long long time;
	int failures;
}_data;

void runAlgos_English(unordered_map<string,vector<_data>> &english, int &comparisons);
void runAlgos_Binary(unordered_map<string,vector<_data>> &binary, int &comparisons);
void runAlgos_DNA(unordered_map<string,vector<_data>> &DNA, int &comparisons);
void runAlgos_Random(unordered_map<string,vector<_data>> &random, int &comparisons);
void writeToFile(
					unordered_map<string,vector<_data>> &english,
					unordered_map<string,vector<_data>> &binary,
					unordered_map<string,vector<_data>> &DNA,
					unordered_map<string,vector<_data>> &random
				);
// server:
void acceleratedNaive(string text,string pattern);
int Naive(string text,string pattern);
void kmp_match(string text,string pattern);
void fsm(string pat, string txt);
void rabinKarp(string pattern,string text,int q);
void boyerMoore(string text, string pat);

#endif