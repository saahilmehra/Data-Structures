/*
Check if a Binary Tree is BST

Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree) or not. If yes, return true, return false otherwise.
Duplicate elements should be in right subtree.

Input format :
Line 1 : Nodes in level order form (separated by space). If any node does not have left or right child, take -1 in its place

Output format :
true or false

Constraints :
1 <= N <= 10^5

Sample Input 1 :
3 1 5 -1 2 -1 -1 -1 -1

Sample Output 1 :
true

Sample Input 2 :
5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1

Sample Output 2 :
false
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

#include<climits>
bool isBST(BinaryTreeNode<int> *root, int minima=INT_MIN, int maxima=INT_MAX)
{
  if(root==NULL)
  {
    return true;
  }
  if(root->data<minima || root->data>maxima)
    return false;

  bool leftSearch=isBST(root->left,minima,root->data);
  bool rightSearch=isBST(root->right,root->data,maxima);

  return leftSearch && rightSearch;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    if(isBST(root)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    delete root;
}
