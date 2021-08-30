/*

  There is a collection of input strings and a collection of query strings. For each query string, determine how many times it occurs in the list of input strings. Return an array of the results.

Example



There are  instances of ',  of '' and  of ''. For each query, add an element to the return array, .

Function Description

Complete the function matchingStrings in the editor below. The function must return an array of integers representing the frequency of occurrence of each query string in strings.

matchingStrings has the following parameters:

string strings[n] - an array of strings to search
string queries[q] - an array of query strings
Returns

int[q]: an array of results for each query
Input Format

The first line contains and integer , the size of .
Each of the next  lines contains a string .
The next line contains , the size of .
Each of the next  lines contains a string .

Constraints



 .

Sample Input 1

CopyDownload
Array: strings
aba
baba
aba
xzxb

 



Array: queries
aba
xzxb
ab

 
4
aba
baba
aba
xzxb
3
aba
xzxb
ab
Sample Output 1

2
1
0
Explanation 1

Here, "aba" occurs twice, in the first and third string. The string "xzxb" occurs once in the fourth string, and "ab" does not occur at all.


Sample Input 2

CopyDownload
Array: strings
def
de
fgh

 



Array: queries
de
lmn
fgh

 
3
def
de
fgh
3
de
lmn
fgh
Sample Output 2

1
0
1

Sample Input 3

CopyDownload
Array: strings
abcde
sdaklfj
asdjf
na
basdn
sdaklfj
asdjf
na
asdjf
na
basdn
sdaklfj
asdjf

 



Array: queries
abcde
sdaklfj
asdjf
na
basdn

 
13
abcde
sdaklfj
asdjf
na
basdn
sdaklfj
asdjf
na
asdjf
na
basdn
sdaklfj
asdjf
5
abcde
sdaklfj
asdjf
na
basdn
Sample Output 3

1
3
4
3
2



*/


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'matchingStrings' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY strings
 *  2. STRING_ARRAY queries
 */

vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    
     
    vector<int> vec( queries.size() ,0) ;
    for( int i = 0 ; i < queries.size() ;  i++ )
    {
        for(int j = 0 ; j < strings.size(); j++ )
        {
            if( queries[i] == strings[j]  )
            {
                vec[i]++ ; 
            }
        }
    }   
    return vec ;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string strings_count_temp;
    getline(cin, strings_count_temp);

    int strings_count = stoi(ltrim(rtrim(strings_count_temp)));

    vector<string> strings(strings_count);

    for (int i = 0; i < strings_count; i++) {
        string strings_item;
        getline(cin, strings_item);

        strings[i] = strings_item;
    }

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<string> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item;
        getline(cin, queries_item);

        queries[i] = queries_item;
    }

    vector<int> res = matchingStrings(strings, queries);

    for (size_t i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

