/*
ZigZag tree

Given a binary tree, print the zig zag order i.e print level 1 from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even level right to left.

Input format :
Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)

Output Format :
Elements are printed level wise, each level in new line (separated by space).

Sample Input :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

Sample Output :
5
10 6
2 3
9
*/

#include <iostream>
#include <queue>
#include <stack>
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

void zigZagOrder(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int>*> pendingNodes;
    stack<BinaryTreeNode<int>*> printNodes;

    pendingNodes.push(root);
    pendingNodes.push(NULL);
    int count=1;

    while(pendingNodes.size() != 0){
        BinaryTreeNode<int>* currNode=pendingNodes.front();
        pendingNodes.pop();
        if(currNode==NULL){
            while (!printNodes.empty())
            {
                BinaryTreeNode<int>* topNode=printNodes.top();
                printNodes.pop();
                cout<<topNode->data<<" ";
            }
            cout<<endl;
            count++;
            if(pendingNodes.empty()){
                break;
            }
            pendingNodes.push(NULL);
        }
        else{
            if(count%2 != 0)
                cout<<currNode->data<<" ";
            else
                printNodes.push(currNode);
        
            if(currNode->left != NULL){
                pendingNodes.push(currNode->left);
            }
            if(currNode->right != NULL){
                pendingNodes.push(currNode->right);
            }
        }
    }
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    zigZagOrder(root);
}
