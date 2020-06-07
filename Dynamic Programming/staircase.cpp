/*
Staircase

A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.
Time complexity of your code should be O(n).

Input format :
Integer n (No. of steps)

Constraints :
n <= 70

Sample Input 1:
4

Sample Output 1:
7
*/

#include<iostream>
#include<climits>
using namespace std;

long staircase(int n){

  long a[n+1];
  a[0]=1;
  a[1]=1;
  a[2]=2;
  for(long i=3;i<n+1;i++){
    long x=a[i-1];
    long y=a[i-2];
    long z=a[i-3];
    if(i==3)
      a[i]=4;
    else
    a[i]=x+y+z;
  }
return a[n];
}

int main(){

  int n;
  cin >> n ;
  cout << staircase(n) << endl;

}
