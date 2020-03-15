/*
Replace pi (recursive)

Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".

Sample Input 1 :
xpix

Sample Output 1 :
x3.14x

Sample Input 2 :
pipi

Sample Output 2 :
3.143.14

Sample Input 3 :
pip

Sample Output 3 :
3.14p
*/

#include <iostream>
#include<string.h>
using namespace std;
void shift(char input[]){
    input[0]='3';
    input[1]='.';
    for(int i=strlen(input)-1;i>1;i--){
            input[i+2]=input[i];
    }
    input[2]='1';
    input[3]='4';
}

bool replace(char input[]){
    if(input[0]=='\0'){
        return false;
	}
	bool res=replace(input+1);
	if(input[0]=='i'){
        return true;
	}
	if(input[0]=='p'){
        if(res==true){
            shift(input);
        }
	}
	return false;
}

void replacePi(char input[]) {
	// Write your code here
	replace(input);
}
int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
