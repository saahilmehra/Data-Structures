/*
Remove Duplicates Recursively

Given a string S, remove consecutive duplicates from it recursively.

Input Format :
String S

Output Format :
Output string

Constraints :
1 <= Length of String S <= 10^3

Sample Input :
aabccba

Sample Output :
abcba
*/

#include <iostream>
using namespace std;

void removeConsecutiveDuplicates(char *input) {
    if(input[0]=='\0'){
        return;
    }
    removeConsecutiveDuplicates(input+1);
    if(input[0]==input[1]){
        for(int i=0;input[i]!='\0';i++){
            input[i]=input[i+1];
        }
    }
    return;
}

int main() {
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}
