/*
Height of Binary Tree

Given a binary tree, find and return the height of given tree.

Input format :
Nodes in the level order form (separated by space). If any node does not have left or right child, take -1 in its place

Output format :
Height

Constraints :
1 <= N <= 10^5

Sample Input :
10 9 4 -1 -1  5  8 -1 6 -1 -1 3 -1 -1 -1

Sample Output :
5
*/

#include <iostream>
#include <queue>
#include<cmath>
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

int height(BinaryTreeNode<int> *root) {
    if(root == NULL){
        return 0;
    }
    return max(height(root -> left), height(root -> right))+1;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << height(root) << endl;
}
