/*
String to Integer

Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.

Input format :
Numeric string (string, Eg. "1234")

Output format :
Corresponding integer (int, Eg. 1234)

Sample Input 1 :
1231

Sample Output 1:
1231

Sample Input 2 :
12567

Sample Output 2 :
12567
*/

#include <iostream>
#include<string.h>
#include <math.h>
using namespace std;

int stringToNumber(char input[]) {
    // Write your code here
    if(input[0]=='\0'){
        return 0;
    }
    int res=stringToNumber(input+1);
    int l=(strlen(input)-1);
    int mf=floor(pow(10,l));
    int n = input[0] - '0';
    return n*mf+res;
}

int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
