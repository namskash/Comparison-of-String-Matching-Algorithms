#include <bits/stdc++.h>
#define NO_OF_CHARS 256
#define MAX_CHAR 256
#define d 256
using namespace std;

bool unique(string pattern)
{
    unordered_map<char,bool> mp;
    int m = pattern.size();
    for(int i = 0;i < m;++i)
    {
        if(mp[pattern[i]] == 1)
        {
            return 0;
        }
        mp[pattern[i]] = 1;
    }
    return 1;
}

void acceleratedNaive(string text,string pattern)
{
    int n = text.length();
    int m = pattern.length();
    int i = 0;
    int j = 0;
    while(i < n)
    {
        if(pattern[j] == text[i])
        {
            if(j == (m - 1))
            {
                cout<<"Pattern found at "<<i - (m - 1)<<endl;
                return;
            }
            else
            {
                j += 1;
            }
        }
        else
        {
            j = 0;
        }
        i += 1;
    }
    cout<<"Pattern not found"<<endl;
}

void Naive(string text,string pattern)
{
    int n = text.length();
    int m = pattern.length();
    for(int i = 0;i <= (n - m);++i)
    {
        int j;
        for(j = 0;j < m;++j)
        {
            if(text[i + j] != pattern[j])
            {
                break;
            }
        }
        if(j == m)
        {
            cout << "Pattern found at index " << i << endl;
            return;
        }
    }
    cout<<"Pattern not found"<<endl;
}

vector<int> kmp_prefix_function(string pattern)
{
    int m = pattern.size();
    pattern = ' ' + pattern;
    vector<int> prefix(m + 1,0);
    prefix[1] = 0;
    int k = 0;
    for(int q = 2;q <= m;++q)
    {
        while((k > 0) && (pattern[k + 1] != pattern[q]))
        {
            k = prefix[k];
        }
        if(pattern[k + 1] == pattern[q])
        {
            k = k + 1;
        }
        prefix[q] = k;
    }
    return prefix;
}

void kmp_match(string text,string pattern)
{
    int n = text.length();
    int m = pattern.length();
    vector<int> prefix = kmp_prefix_function(pattern);
    int j = 0;
    text = ' ' + text;
    pattern = ' ' + pattern;
    for(int i = 1;i <= n;++i)
    {
        while((j > 0) && (pattern[j + 1] != text[i]))
        {
            j = prefix[j];
        }
        if(pattern[j + 1] == text[i])
        {
            j = j + 1;
        }
        if(j == m)
        {
            cout<<"Pattern found at "<<i - m<<endl;
            return;
        }
    }
    cout<<"Pattern not found"<<endl;
}

int getNextState(string pat, int M, int state, int x)
{
    
    if (state < M && x == pat[state])
        return state+1;
 
    int ns, i;
 
    for (ns = state; ns > 0; ns--)
    {
        if (pat[ns-1] == x)
        {
            for (i = 0; i < ns-1; i++)
                if (pat[i] != pat[state-ns+1+i])
                    break;
            if (i == ns-1)
                return ns;
        }
    }
 
    return 0;
}

void computeTF(string pat, int M, int TF[][NO_OF_CHARS])
{
    int state, x;
    for (state = 0; state <= M; ++state)
        for (x = 0; x < NO_OF_CHARS; ++x)
            TF[state][x] = getNextState(pat, M, state, x);
}

void fsm(string pat, string txt)
{
    int M = pat.size();
    int N = txt.size();
 
    int TF[M+1][NO_OF_CHARS];
 
    computeTF(pat, M, TF);
 
    int i, state=0;
    for (i = 0; i < N; i++)
    {
        state = TF[state][txt[i]];
        if (state == M)
        {
            cout<<" Pattern found at index "<< i-M+1<<endl;
            return;
        }
    }
    cout<<"Pattern not found"<<endl;
}

void rabinKarp(string pattern,string text,int q)
{
    int m = pattern.size();
    int n = text.size();
    int i, j;
    long long p = 0; // hash value for pattern
    long long t = 0; // hash value for txt
    int h = 1;
    
    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;
    
     for (i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }
    
    for(i = 0;i <= n - m;++i)
    {
        if(p == t)
        {
            for(j = 0;j < m;++j)
            {
                if(text[i + j] != pattern[j])
                {
                    break;
                }
            }
            if(j == m)
            {
                cout<<"Pattern found at index at "<<i<<endl;
                return;
            }
        }
        if(i < (n - m))
        {
            t = (d*(t - text[i] * h) + text[i + m]) % q;
            if(t < 0)
            {
                t += q;
            }
        }
    }
    cout<<"Pattern not found"<<endl;
}

void preprocess_strong_suffix(int *shift, int *bpos,
                                string pat, int m)
{
    // m is the length of pattern 
    int i=m, j=m+1;
    bpos[i]=j;
  
    while(i>0)
    {
        /*if character at position i-1 is not equivalent to
          character at j-1, then continue searching to right
          of the pattern for border */
        while(j<=m && pat[i-1] != pat[j-1])
        {
            /* the character preceding the occurrence of t in 
               pattern P is different than the mismatching character in P, 
               we stop skipping the occurrences and shift the pattern
               from i to j */
            if (shift[j]==0)
                shift[j] = j-i;
  
            //Update the position of next border 
            j = bpos[j];
        }
        /* p[i-1] matched with p[j-1], border is found.
           store the  beginning position of border */
        i--;j--;
        bpos[i] = j; 
    }
}

void preprocess_case2(int *shift, int *bpos,
                      string pat, int m)
{
    int i, j;
    j = bpos[0];
    for(i=0; i<=m; i++)
    {
        /* set the border position of the first character of the pattern
           to all indices in array shift having shift[i] = 0 */ 
        if(shift[i]==0)
            shift[i] = j;
  
        /* suffix becomes shorter than bpos[0], use the position of 
           next widest border as value of j */
        if (i==j)
            j = bpos[j];
    }
}

void boyerMoore(string text, string pat)
{
    // s is shift of the pattern with respect to text
    int s=0, j;
    int m = pat.size();
    int n = text.size();
  
    int bpos[m+1], shift[m+1];
  
    //initialize all occurrence of shift to 0
    for(int i=0;i<m+1;i++) shift[i]=0;
  
    //do preprocessing
    preprocess_strong_suffix(shift, bpos, pat, m);
    preprocess_case2(shift, bpos, pat, m);
  
    while(s <= n-m)
    {
  
        j = m-1;
  
        /* Keep reducing index j of pattern while characters of
             pattern and text are matching at this shift s*/
        while(j >= 0 && pat[j] == text[s+j])
            j--;
  
        /* If the pattern is present at the current shift, then index j
             will become -1 after the above loop */
        if (j<0)
        {
            cout<<"pattern occurs at shift = "<<s<<endl;
            return;
            //s += shift[0];
        }
        else
            /*pat[i] != pat[s+j] so shift the pattern
              shift[j+1] times  */
            s += shift[j+1];
    }
    cout<<"Pattern not found"<<endl;
}

class SuffixTrieNode
{
private:
    SuffixTrieNode *children[MAX_CHAR];
    list<int> *indexes;
public:
    SuffixTrieNode() // Constructor
    {
        // Create an empty linked list for indexes of
        // suffixes starting from this node
        indexes = new list<int>;
 
        // Initialize all child pointers as NULL
        for (int i = 0; i < MAX_CHAR; i++)
          children[i] = NULL;
    }
 
    // A recursive function to insert a suffix of the txt
    // in subtree rooted with this node
    void insertSuffix(string suffix, int index);
 
    // A function to search a pattern in subtree rooted
    // with this node.The function returns pointer to a linked
    // list containing all indexes where pattern is present.
    // The returned indexes are indexes of last characters
    // of matched text.
    list<int>* search(string pat);
};

class SuffixTrie
{
private:
    SuffixTrieNode root;
public:
    // Constructor (Builds a trie of suffixes of the given text)
    SuffixTrie(string txt)
    {
        // Consider all suffixes of given string and insert
        // them into the Suffix Trie using recursive function
        // insertSuffix() in SuffixTrieNode class
        for (int i = 0; i < txt.length(); i++)
            root.insertSuffix(txt.substr(i), i);
    }
 
    // Function to searches a pattern in this suffix trie.
    void search(string pat);
};

void SuffixTrieNode::insertSuffix(string s, int index)
{
    // Store index in linked list
    indexes->push_back(index);
 
    // If string has more characters
    if (s.length() > 0)
    {
        // Find the first character
        char cIndex = s.at(0);
 
        // If there is no edge for this character, add a new edge
        if (children[cIndex] == NULL)
            children[cIndex] = new SuffixTrieNode();
 
        // Recur for next suffix
        children[cIndex]->insertSuffix(s.substr(1), index+1);
    }
}

list<int>* SuffixTrieNode::search(string s)
{
    // If all characters of pattern have been processed,
    if (s.length() == 0)
        return indexes;
 
    // if there is an edge from the current node of suffix trie,
    // follow the edge.
    if (children[s.at(0)] != NULL)
        return (children[s.at(0)])->search(s.substr(1));
 
    // If there is no edge, pattern doesn’t exist in text
    else return NULL;
}

void SuffixTrie::search(string pat)
{
    // Let us call recursive search function for root of Trie.
    // We get a list of all indexes (where pat is present in text) in
    // variable 'result'
    list<int> *result = root.search(pat);
 
    // Check if the list of indexes is empty or not
    if (result == NULL)
        cout << "Pattern not found" << endl;
    else
    {
       list<int>::iterator i;
       int patLen = pat.length();
       for (i = result->begin(); i != result->end(); ++i)
         cout << "Pattern found at position " << *i - patLen<< endl;
         return;
    }
}

int main()
{
    cout<<"String Matching Algorithms"<<endl;
    string text,pattern;
    while(true)
    {
		fflush(stdin);
        cout<<"Enter text"<<endl;
        getline(cin,text);
        cout<<"Enter Pattern"<<endl;
        getline(cin,pattern);
        cout<<"1.Naive Algorithm for pattern matching"<<endl;
        cout<<"2.Accelerated Naive for pattern matching"<<endl;
        cout<<"3.Pattern matching using Boyer Moore"<<endl;
        cout<<"4.Pattern matching using Rabin Karp"<<endl;
        cout<<"5.Pattern matching using KMP"<<endl;
        cout<<"6.Pattern matching using Finite State Automata"<<endl;
        cout<<"7.Pattern matching using Suffix Trie"<<endl;
        cout<<"8.Pattern matching using Suffix Tree"<<endl;
        cout<<"Enter Choice"<<endl;
        int choice;
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Naive Algorithm for pattern matching"<<endl;
                Naive(text,pattern);
                break;  
            case 2:
                cout<<"Accelerated Naive for pattern matching"<<endl;
                if(unique(pattern))
                {
                    acceleratedNaive(text,pattern);
                }
                else
                {
                    cout<<"Pattern is not unique"<<endl;
                }
                break;
            case 3:
                cout<<"Pattern matching using Boyer Moore"<<endl;
                boyerMoore(text,pattern);
                break;
                
            case 4:
                cout<<"Pattern matching using Rabin Karp"<<endl;
                cout<<"Enter a prime number"<<endl;
                int q;
                cin>>q;
                rabinKarp(pattern,text,q);
                break;
            case 5:
                cout<<"Pattern matching using KMP"<<endl;
                kmp_match(text,pattern);
                break;
            case 6:
                cout<<"Pattern matching using Finite State Automata"<<endl;
                fsm(pattern,text);
                break;
            case 7:
                cout<<"Pattern matching using Suffix Trie"<<endl;
                SuffixTrie S(text);
                S.search(pattern);
                break;
        }
    }
    return 0;
}