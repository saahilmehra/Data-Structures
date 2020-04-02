/*
Return Keypad Code

Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : The order of strings are not important.

Input Format :
Integer n

Output Format :
All possible strings in different lines

Constraints :
1 <= n <= 10^6

Sample Input:
23

Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/

#include <iostream>
#include <string>
using namespace std;

int keypad(int num, string output[], string options[]){
  if(num == 0){
    output[0] = "";
    return 1;
  }
  int lastDigit = num % 10;
  int smallNumber = num / 10;
   string smallOutput[500];

  int smallCount =  keypad(smallNumber, smallOutput, options);
  string op = options[lastDigit];

  int k = 0;
  for(int i = 0; i < op.length(); i++){
    for(int j = 0; j < smallCount; j++){
      output[k] = smallOutput[j] + op[i];
      k++;
    }
  }
  return k;
}

int keypad(int num, string output[]){
	 string options[] = {"","", "abc", "def", "ghi", "jkl", "mno", "pqrs","tuv","wxyz"};
	return keypad(num, output, options);
}


int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
