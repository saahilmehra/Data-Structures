/*
Construct BST from a Sorted Array

Given a sorted integer array A of size n which contains all unique elements. You need to construct a balanced BST from this input array. Return the root of constructed BST.
Note : If array size is even, take first mid as root.

Input format :
Line 1 : Integer n (Size of array)
Line 2 : Array elements (separated by space)

Output Format :
BST elements (in pre order traversal, separated by space)

Sample Input :
7
1 2 3 4 5 6 7

Sample Output :
4 2 1 3 6 5 7 
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

void preOrder(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        return;
    }
    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}

BinaryTreeNode<int>* constructTree(int *input, int n) {
    if(n==0)
        return NULL;

    int mid=n/2;
    if(n%2==0)
        mid--;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(input[mid]);

    root->left=constructTree(input, mid);
    root->right=constructTree(input+mid+1, n-mid-1);

    return root;
}

int main() {
    int size;
    cin>>size;
    int *input=new int[1+size];

    for(int i=0;i<size;i++)
        cin>>input[i];

    BinaryTreeNode<int>* root = constructTree(input, size);
    preOrder(root);

}
