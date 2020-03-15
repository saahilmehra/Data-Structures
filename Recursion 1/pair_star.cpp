/*
Pair star

Given a string, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".

Sample Input 1 :
hello

Sample Output 1:
hel*lo

Sample Input 2 :
xxyy

Sample Output 2:
x*xy*y

Sample Input 3 :
aaaa

Sample Output 3:
a*a*a*a
*/

#include <iostream>
#include<string.h>
using namespace std;

void insertStar(char input[]){
    int l=strlen(input);
    input[l+1]='\0';
    for(int i=l-1;i>0;i--){
            input[i+1]=input[i];
    }
    input[1]='*';
}

void pairStar(char input[]) {
    // Write your code here
    if(input[0]=='\0'){
        return;
    }
    pairStar(input+1);
    if(input[0]==input[1]){
        insertStar(input);
    }
    return;
}

int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}
