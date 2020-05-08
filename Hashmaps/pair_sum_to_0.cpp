/*
Pair Sum to 0

Given a random integer array A of size N. Find and print the pair of elements in the array which sum to 0.
Array A can contain duplicate elements.
While printing a pair, print the smaller element first.
That is, if a valid pair is (6, -6) print "-6 6". There is no constraint that out of 5 pairs which have to be printed in 1st line. You can print pairs in any order, just be careful about the order of elements in a pair.

Input format :
Line 1 : Integer N (Array size)
Line 2 : Array elements (separated by space)

Output format :
Line 1 : Pair 1 elements (separated by space)
Line 2 : Pair 2 elements (separated by space)
Line 3 : and so on

Constraints :
0 <= N <= 10^4

Sample Input:
5
2 1 -2 2 3

Sample Output :
-2 2
-2 2
*/

#include<iostream>
#include<unordered_map>
#include<cmath>
using namespace std;

void PairSum(int *input, int n)
{
    unordered_map<int, int> m;
    for(int i=0; i<n; i++)
    {
        int key = input[i];
        if(m.count(key)==0)
        {
            m[key]=1; //initializing frequency value to 1 if key is not already present in hashmap
        }
        else
        {
            m[key]++; //incrementing frequency value by 1 if key is already present in hashmap
        }
    }

    //traversing the array and checking if -key is present in hashmap
    for(int i=0; i<n; i++)
    {
        int key = input[i];
        if(m.count(-key)!=0 && m[key]!=0)
        {
            int times = m[key] * m[-key];
            while(times!=0)
            {
                cout<<min(key, (-key));
                cout<<" "<<max(key, (-key))<<"\n";
                times--;
            }
            m[key]=0;
            m[-key]=0;
        }
    }
}

int main()
{
    int n;
    int arr[100000];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    PairSum(arr, n);
    return 0;
}
