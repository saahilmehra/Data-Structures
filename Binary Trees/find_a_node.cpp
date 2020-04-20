/*
Find a node

Given a Binary Tree and an integer x, check if node with data x is present in the input binary tree or not. Return true or false.

Input format :
Line 1 : Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Line 2 : Integer x

Output Format :
true or false

Sample Input :
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
7

Sample Output :
true
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

bool isNodePresent(BinaryTreeNode<int>* root, int x) {
    if(root==NULL)
        return false;

    if(root->data == x)
        return true;

    bool lres=isNodePresent(root->left, x);
    if(lres)
        return true;

    bool Rres=isNodePresent(root->right, x);
    if(Rres)
        return true;

    return false;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int x;
    cin >> x;
    if(isNodePresent(root, x)) {
        cout << "true";
    }
    else {
        cout << "false";
    }

}
