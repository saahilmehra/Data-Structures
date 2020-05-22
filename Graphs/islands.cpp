/*
Islands

An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given N islands (numbered from 1 to N) and two lists of size M (u and v) denoting island u[i] is connected to island v[i] and vice versa . Can you count the number of connected groups of islands.

Constraints :
1<=N<=100
1<=M<=(N*(N-1))/2
1<=u[i],v[i]<=N

Input Format :
Line 1 : Two integers N and M
Line 2 : List u of size of M
Line 3 : List v of size of M

Output Return Format :
The count the number of connected groups of islands

Sample Input :
2 1
1
2

Sample Output :
1 
*/

#include<iostream>
#include<vector>
using namespace std;

#define NM 105
vector<int>adj[NM];
int visited[NM];
void dfs(int u,int p)
{
	if(visited[u])
		return ;
	visited[u]=1;
	for(int i=0;i<adj[u].size();i++)
	if(adj[u][i]!=p)
	{
		dfs(adj[u][i],u);
	}
}
int solve(int n,int m,vector<int>u,vector<int>v)
{
	for(int i=0;i<m;i++)
	{
		adj[u[i]].push_back(v[i]);
		adj[v[i]].push_back(u[i]);
	}
	int connected_groups=0;
	for(int i=1;i<=n;i++)
	if(!visited[i])
	{
		dfs(i,i);
		connected_groups++;
	}
	return connected_groups;
}

int main()
{
	int n,m;
	vector<int>u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		u.push_back(x);
	}
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<solve(n,m,u,v)<<endl;
}
