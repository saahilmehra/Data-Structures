/*
LCA of Binary Tree

Given a binary tree and two nodes, find LCA (Lowest Common Ancestor) of the given two nodes in Binary Tree. Read about LCA if you are having doubts about the definition.
If out of 2 nodes only one node is present, return that node.
If both are not present, return -1.

Input format :
Line 1 :  Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Line 2 : Two integers, Node 1 and Node 2 (separated by space)

Output Format :
LCA

Constraints :
1 <= N <= 1000

Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
2 10

Sample Output 1:
10

Sample Input 2:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
2 6

Sample Output 2:
5

Sample Input 3:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
12 78

Sample Output 3:
-1
*/

#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode() {
    	if(left)
       		delete left;
    	if(right)
       		delete right;
    }
};

BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

BinaryTreeNode<int>* lcaBinaryTreeHelper(BinaryTreeNode<int> *root , int a, int b){
    if(!root) {
        return NULL;
    }
    if(root -> data == a || root -> data == b) {
        return root;
    }
    BinaryTreeNode<int> *left_lca = lcaBinaryTreeHelper(root -> left, a, b);
    BinaryTreeNode<int> *right_lca = lcaBinaryTreeHelper(root -> right, a, b);
    if(left_lca && right_lca){
        return root;
    }
    if(left_lca) return left_lca;
    return right_lca;

}

int lcaBinaryTree(BinaryTreeNode <int> *root , int val1, int val2){
    BinaryTreeNode<int> *node = lcaBinaryTreeHelper(root, val1, val2);
    if(node != NULL)
    	return node -> data;
    else
    	return -1;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int a, b;
    cin >> a >> b;
    cout << lcaBinaryTree(root, a, b);
    delete root;
}
