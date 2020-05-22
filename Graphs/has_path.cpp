/*
Has Path

Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), check if there exists any path between them or not. Print true or false.

V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.

E is the number of edges present in graph G.

Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)

Output Format :
true or false

Constraints :
2 <= V <= 1000
1 <= E <= 1000
0 <= v1, v2 <= V-1

Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3

Sample Output 1 :
true

Sample Input 2 :
6 3
5 3
0 1
3 4
0 3

Sample Output 2 :
false
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool hasPath_DFS(unordered_map<int, vector<int>* > &adjacencyList, int v1, int v2, unordered_map<int, bool> &visited) {
    vector<int> *adjacentVertices = adjacencyList[v1];

    // Check if v1 and v2 are directly connected
    for(int i = 0; i < adjacentVertices -> size(); i++) {
        if(adjacentVertices -> at(i) == v2) {
            return true;
        }
    }

    // Mark it visited to avoid calling over this vertex again
    visited[v1] = true;

    // Recursion call
    for(int i = 0; i < adjacentVertices -> size(); i++) {
        if(visited.count(adjacentVertices -> at(i)) == 0) {
            bool ans = hasPath_DFS(adjacencyList, adjacentVertices -> at(i), v2, visited);
            if(ans) {
                return true;
            }
        }
    }
    return false;
}

bool hasPath_DFS(unordered_map<int, vector<int>* > &adjacencyList, int v1, int v2) {
    unordered_map<int, bool> visited;
    return hasPath_DFS(adjacencyList, v1, v2, visited);
}

int main() {
    int n, e;
    cin >> n >> e;

    // Taking graph input and creating an adjacency list
    unordered_map<int, vector<int>* > adjacencyList;
    for(int i = 0; i < n; i++) {
        vector<int> *v = new vector<int>;
        adjacencyList[i] = v;
    }

    int count = 1;
    while(count <= e) {
        int source, dest;
        cin >> source >> dest;
        adjacencyList[source] -> push_back(dest);
        adjacencyList[dest] -> push_back(source);
        count++;
    }

    int v1, v2;
    cin >> v1 >> v2;

    if(hasPath_DFS(adjacencyList, v1, v2)) {
        cout<< "true" << endl;
    }
    else {
        cout<< "false" << endl;
    }

    return 0;
}
