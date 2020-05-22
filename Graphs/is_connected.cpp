/*
Is Connected ?

Given an undirected graph G(V,E), check if the graph G is connected graph or not.

V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.

E is the number of edges present in graph G.

Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.

Output Format :
"true" or "false"

Constraints :
2 <= V <= 1000
1 <= E <= 1000

Sample Input 1:
4 4
0 1
0 3
1 2
2 3

Sample Output 1:
true

Sample Input 2:
4 3
0 1
1 3 
0 3

Sample Output 2:
false 

Sample Output 2 Explanation
The graph is not connected, even though vertices 0,1 and 3 are connected to each other but there isn’t any path from vertices 0,1,3 to vertex 2. 
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void dfs(unordered_map<int, vector<int>* > &adjacencyList, int v1, unordered_map<int, bool> &visited) {
    vector<int> *adjacentVertices = adjacencyList[v1];

    // Mark it visited to avoid calling over this vertex again
    visited[v1] = true;

		// Recursion call
    for(int i = 0; i < adjacentVertices -> size(); i++) {
        if(visited.count(adjacentVertices -> at(i)) == 0) {
            dfs(adjacencyList, adjacentVertices -> at(i), visited);
        }
    }
}

bool isConnected(unordered_map<int, vector<int>* > &adjacencyList) {
    unordered_map<int, bool> visited;
   	int startVertex = adjacencyList.begin()->first;
		dfs(adjacencyList, startVertex, visited);
		return visited.size() == adjacencyList.size();

}

int main() {
    int v, e;
    cin >> v >> e;

    // Taking graph input and creating an adjacency list
    unordered_map<int, vector<int>* > adjacencyList;
    for(int i = 0; i < v; i++) {
        vector<int> *v1 = new vector<int>;
        adjacencyList[i] = v1;
    }

    int count = 1;
    while(count <= e) {
        int source, dest;
        cin >> source >> dest;
        adjacencyList[source] -> push_back(dest);
        adjacencyList[dest] -> push_back(source);
        count++;
    }


    if(isConnected(adjacencyList)) {
        cout<< "true" << endl;
    }
    else {
        cout<< "false" << endl;
    }

    return 0;
}
