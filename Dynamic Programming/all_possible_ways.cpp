/*
All possible ways

Given two integers a and b. You need to find and return the count of possible ways in which we can represent the number a as the sum of unique integers raise to the power b.

For eg. if a = 10 and b = 2, only way to represent 10 as -
10 = 1^2 + 3^2 
Hence, answer is 1.
Note : x^y represents x raise to the power y

Input Format :
Two integers a and b (separated by space)

Output Format :
Count

Constraints :
1 <= a <= 10^5
1 <= b <= 50

Sample Input 1 :
10 2

Sample Output 1 :
1

Sample Input 2 :
100 2

Sample Output 2 :
3
*/

#include <iostream>
#include<math.h>
using namespace std;

int power(int num, unsigned int n)
{
    if (n == 0)
        return 1;
    else if (n%2 == 0)
        return power(num, n/2)*power(num, n/2);
    else
        return num*power(num, n/2)*power(num, n/2);
}

int allWays(int x, int n, int curr_num = 1,int curr_sum = 0) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */

    int results = 0;

    // Calling power of 'i' raised to 'n'
    int p = power(curr_num, n);
    while (p + curr_sum < x)
    {
        // Recursively check all greater values of i
        results += allWays(x, n, curr_num+1, p+curr_sum);
        curr_num++;
        p = power(curr_num, n);
    }

    // If sum of powers is equal to x
    // then increase the value of result.
    if (p + curr_sum == x)
        results++;

    // Return the final result
    return results;
}

int main()
{
    int x, n;
    cin >> x >> n;
    cout << allWays(x, n);
    return 0;
}
