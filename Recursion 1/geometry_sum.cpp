/*
Geometric Sum

Given k, find the geometric sum i.e.
1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k) 
using recursion. Return the answer.

Sample Input :
3

Sample Output :
1.875
*/

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

double geometricSum(int k) {
    if(k==0){
        return 1;
    }

    double divi=pow(2,k);
    double res=1/divi;
    return res+geometricSum(k-1);

}

int main() {
    int k;
    cin >> k;
    cout << fixed << setprecision(5);
    cout << geometricSum(k) << endl;
}
