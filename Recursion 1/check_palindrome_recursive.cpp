/*
Check Palindrome (recursive)

Check if a given String S is palindrome or not (using recursion). Return true or false.

Input Format :
String S

Output Format :
true or false

Sample Input 1 :
racecar

Sample Output 1:
true

Sample Input 2 :
ninja

Sample Output 2:
false
*/

#include <iostream>
#include <string.h>

using namespace std;

bool check(char input[], int start, int end){
    if(start==end){
        return true;
    }

    if(input[start] != input[end]){
        return false;
    }
    if (start < end + 1) {
        return check(input, start + 1, end - 1);
    }
    return true;
}

bool checkPalindrome(char input[]) {
    return check(input, 0, strlen(input)-1);
}

int main() {
    char input[50];
    cin >> input;

    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
