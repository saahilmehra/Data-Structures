/*
Coding Ninjas

Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .

There is a path from any cell to all its neighbouring cells. A neighbour may share an edge or a corner.

Input Format :
Line 1 : Two space separated integers N  and M, where N is number of rows and M is number of columns in the matrix.
Next N lines : N rows of the matrix. First line of these N line will contain 0th row of matrix, second line will contain 1st row and so on
Assume input to be 0-indexed based

Output Format :
Return 1 if there is a path which makes the sentence “CODINGNINJA” else return 0.

Constraints :
1 <= N <= 100
1 <= M <= 100

Sample Input :
2 11
CXDXNXNXNXA
XOXIXGXIXJX

Sample Output :
1
*/

#include<bits/stdc++.h>
#define MAXN 102
using namespace std;

int a[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
char pattern[11] = {'C','O','D','I','N','G','N','I','N','J','A'};
int used[MAXN][MAXN];

int validPoint(int x,int y,int N,int M){
	return (x >= 0 && x < N && y >= 0 && y < M);
}

int DFS(char G[][MAXN],int x, int y, int index, int N, int M){

	if(index == 11)
		return 1;

	used[x][y] = 1;
	int i, newx, newy;
	int found = 0;
	for(i = 0; i < 8; i++){

		newx = x + a[i][0];
		newy = y + a[i][1];

		if(validPoint(newx,newy,N,M) && G[newx][newy] == pattern[index] && !used[newx][newy]){
			found = found | DFS(G,newx,newy,index+1,N,M);
		}
	}

	used[x][y] = 0;

	return found;
}

int solve(char Graph[][MAXN] , int N, int M)
{
	int i,j,found;

	for(i = 0;i < N; i++){
		for( j = 0 , found = 0; j < M; j++ ){
			if(Graph[i][j] == 'C'){
				found = DFS(Graph,i,j,1,N,M);
				if(found)
					break;
			}
		}
		if(found)
			break;
	}

	return found;

}

int main()
{
	int N,M,i;
	char Graph[MAXN][MAXN];
	cin>>N>>M;
	for(i = 0;i < N; i++){
		cin>>Graph[i];
	}
	cout<<solve(Graph,N,M)<<endl;
}
