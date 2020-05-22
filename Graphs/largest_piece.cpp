/*
Largest Piece

Its Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with eachother on the cake. Given the size of cake N and the cake , can you find the size of the biggest piece of '1's for Gary ?

Constraints :
1<=N<=50

Input Format :
Line 1 : An integer N denoting the size of cake 
Next N lines : N characters denoting the cake

Output Format :
Size of the biggest piece of '1's and no '0's

Sample Input :
2
11
01

Sample Output :
3
*/

#include<iostream>
#include<vector>
#define NMAX 55
using namespace std;

int visited[NMAX][NMAX];
char A[NMAX][NMAX];
int cx[]={0,0,-1,1};//change in x while taking four moves
int cy[]={1,-1,0,0};//change in y while taking four moves
//Consider a cake to be connected graph with every vertex connected to its nearby 4 vertices

int dfs(int x,int y,int n)
{
	if(visited[x][y])
		return 0;
	visited[x][y]=1;
	int coun=1;
	for(int i=0;i<4;i++)
	{
		int dx=x+cx[i];
		int dy=y+cy[i];
		if(dx>=0&&dx<n&&dy>=0&&dy<n&&A[dx][dy]=='1')
		{
			coun+=dfs(dx,dy,n);
		}
	}
	return coun;
}
int solve(int n,char cake[NMAX][NMAX])
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			A[i][j]=cake[i][j];
	int maxsize=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(A[i][j]=='1'&&visited[i][j]==0)
			{
				maxsize=max(maxsize,dfs(i,j,n));
			}
		}
	return 	maxsize;
}

char cake[NMAX][NMAX];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%s",cake[i]);
	}
	cout<<solve(n,cake)<<endl;
}
