/*
Sum of digits (recursive)

Write a recursive function that returns the sum of the digits of a given integer.

Sample Input :
12345

Sample Output :
15
*/

#include <iostream>
using namespace std;

int sumOfDigits(int n) {
    if(n<=9){
        return n;
    }
    int result=n%10;
	
    return result+sumOfDigits(n/10);
}

int main() {
   int n;
   cin >> n;
   cout << sumOfDigits(n) << endl;
}
