/*
Split Array

Given an integer array A of size N, check if the input array can be splitted in two parts such that -

- Sum of both parts is equal
- All elements in the input, which are divisible by 5 should be in same group.
- All elements in the input, which are divisible by 3 (but not divisible by 5) should be in other group.
- Elements which are neither divisible by 5 nor by 3, can be put in any group.

Groups can be made with any set of elements, i.e. elements need not to be continuous. And you need to consider each and every element of input array in some group.

Return true, if array can be split according to the above rules, else return false.

Note : You will get marks only if all the test cases are passed.

Input Format :
Line 1 : Integer N (size of array)
Line 2 : Array A elements (separated by space)

Output Format :
true or false

Constraints :
1 <= N <= 50

Sample Input 1 :
2
1 2

Sample Output 1 :
false

Sample Input 2 :
3
1 4 3

Sample Output 2 :
true
*/

#include <iostream>
using namespace std;

bool check(int *input, int size, int startIndex, int lSum, int rSum){
    if(startIndex==size){
        return lSum==rSum;
    }
    if(input[startIndex]%5==0){
        lSum+=input[startIndex];
    }
    else if(input[startIndex]%3==0){
        rSum+=input[startIndex];
    }
    else{
        bool leftAns=check(input, size, startIndex+1, lSum+input[startIndex], rSum);
        bool rightAns=check(input, size, startIndex+1, lSum, rSum+input[startIndex]);
        return leftAns || rightAns;
    }
    return check(input, size, startIndex+1, lSum, rSum);
}

bool splitArray(int *input, int size) {
    return check(input, size, 0, 0, 0);
}

int main() {

	int size;
	cin>>size;
	int *input=new int[1+size];

	for(int i=0;i<size;i++)
		cin>>input[i];

    if(splitArray(input, size)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

	return 0;

}
