/*
Number of balanced BTs

Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so return output modulus 10^9 + 7.
Time complexity should be O(h).

Input Format :
Integer h

Output Format :
Count % 10^9 + 7

Input Constraints :
1 <= h <= 10^7

Sample Input 1:
3

Sample Output 1:
15

Sample Input 2:
4

Sample Output 2:
315
*/

#include <iostream>
#include <cmath>
using namespace std;

int binaryTreesOfHeightH(int h) {
    int *a = new int[h + 1];
    if(h == 0) {
        return 1;
    }
    if(h == 1) {
        return 1;
    }
    a[0] = 1;
    a[1] = 1;
    int mod = (int)(pow(10, 9)) + 7;
    for(int i = 2; i <= h; i++) {
    	long temp1 = (long) (a[i-1]) * a[i-1];
    	temp1 = temp1 % mod;

    	long temp2 = 2 * (long)(a[i-1]) * a[i-2];
    	temp2 = temp2 % mod;

        a[i] = (temp1 + temp2) % mod;
    }

    int ans = a[h];

    delete [] a;

    return ans;
}

int main() {
    int h;
    cin >> h;
    int ans = binaryTreesOfHeightH(h);
    ans = ans % ((int)(pow(10, 9)) + 7);
    cout << ans << endl;
}
