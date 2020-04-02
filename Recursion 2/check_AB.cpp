/*
Check AB

Suppose you have a string made up of only 'a' and 'b'. Write a recursive function that checks if the string was generated using the following rules:
a. The string begins with an 'a'
b. Each 'a' is followed by nothing or an 'a' or "bb"
c. Each "bb" is followed by nothing or an 'a'
If all the rules are followed by the given string, return true otherwise return false.

Sample Input:
abb

Sample Output:
true
*/

#include <iostream>
using namespace std;

bool check_ab(char input[], int startIndex){
    if(input[startIndex]=='\0'){
        return true;
    }
    if(input[startIndex]!='a'){
        return false;
    }
    if(input[startIndex+1]!='\0' && input[startIndex+2]!='\0'){
        if(input[startIndex+1]=='b' && input[startIndex+2]=='b'){
            return check_ab(input, startIndex+3);
        }
    }
    return check_ab(input, startIndex+1);
}

bool checkAB(char input[]) {
    return check_ab(input, 0);
}

int main() {
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
}
