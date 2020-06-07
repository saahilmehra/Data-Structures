/*
Maximum Square Matrix With All Zeros

Given a n*m matrix which contains only 0s and 1s, find out the size of maximum square sub-matrix with all 0s. You need to return the size of square with all 0s.

Input format :
Line 1 : n and m (space separated positive integers)
Next n lines : m elements of each row (separated by space).

Output Format:
Line 1 : Size of maximum square sub-matrix

Sample Input :
3 3
1 1 0
1 1 1
1 1 1

Sample Output :
1
*/

#include<iostream>
using namespace std;

int findMaxSquareWithAllZeros(int** arr, int row, int col){
    /* Given a n*m matrix which contains only 0s and 1s, find out the size of
     * maximum square sub-matrix with all 0s. You need to return the size of
     * square with all 0s. */
    int **storage;
    storage = new int*[row+1];
    for(int i=0; i<=row; i++)
    {
        storage[i] = new int[col+1];
        for(int j=0; j<=col; j++)
            storage[i][j] = 0;
    }
    for(int i=row-1; i>=0; i--)
        for(int j=col-1; j>=0; j--)
        {
            int maximum = storage[i][j] = max(storage[i+1][j], storage[i][j+1]);

            if(min(row-i, col-j)<=maximum)
                continue;

            bool foundOne = false;
            for(int p=0; p<=maximum; p++)
                for(int q=0; q<=maximum; q++)
                    if(arr[i+p][j+q]==1){
                        foundOne = true;
                        p = q = maximum+1;
                    }
            if(foundOne==false)
                storage[i][j] += 1;
        }
    int ans = storage[0][0];
    for(int i=0; i<=row; i++)
        delete [] storage[i];
    delete [] storage;
    return ans;
}

int main()
 {
  int **arr,n,m,i,j;
  cin>>n>>m;
  arr=new int*[n];
  for(i=0;i<n;i++)
      {
       arr[i]=new int[m];
      }
  for(i=0;i<n;i++)
     {
      for(j=0;j<m;j++)
	    {
	     cin>>arr[i][j];
	    }
     }
  cout << findMaxSquareWithAllZeros(arr,n,m) << endl;
  delete arr;
  return 0;
}
