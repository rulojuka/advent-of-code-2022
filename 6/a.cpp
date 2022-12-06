#include<string>
#include<iostream>
#include<regex>

using namespace std;

string inputLine;

/*
This is solved using regexp. This cpp file creates the regexp.

The regexp (for problem 1):
(.)(?!\1)(.)(?!\1|\2)(.)(?!\1|\2|\3)(.)

This uses both
- pattern groups
- negative lookahead

It matches something that, in order:

Regex part : meaning
(.) - is a character: call that group1 
(?!\1)(.) - is a character AND is not a group1: call that group2
(?!\1|\2)(.) - is a character AND (is not a group1 or a group2): call that group3
(?!\1|\2|\3)(.) - is a character AND (is not a group1 or a group2 or a group3): call that group4

For problem 2, it does the equivalent for n=14

*/

string createRegexp(int n){
    string response;
    for(int i=0; i<n; i++){
        if(i!=0){
            response += "(?!";
        }
        for(int j=0;j<i;j++){
            response += "\\";
            response += to_string(j+1);
            if(j<i-1){
                response += "|";
            }
        }
        if(i!=0){
            response += ")";
        }
        response += "(.)";
    }
    return response;
}

int solve(int n){
    smatch m;
    regex patternToMatch(createRegexp(n));
    regex_search(inputLine, m, patternToMatch);
    return m.position(0) + n;
}

int main(){
    cin >> inputLine;
    cout << solve(4) << endl;
    cout << solve(14) << endl;
    return 0;
}