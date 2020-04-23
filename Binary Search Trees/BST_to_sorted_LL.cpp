/*
BST to Sorted LL

Given a BST, convert it into a sorted linked list. Return the head of LL.

Input format :
Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)

Output Format :
Linked list elements (separated by space)

Sample Input :
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1

Sample Output :
2 5 6 7 8 10
*/

#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class Node{
public:
    T data;
    Node<T> *next;
    Node(T data){
        this -> data = data;
        this -> next = NULL;
    }
};

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

Node<int>* constructBST(BinaryTreeNode<int>* root) {
    if(root==NULL)
        return NULL;

    Node<int>* head=NULL;
    Node<int>* currNode=NULL;

    currNode=constructBST(root->left);

    Node<int>* newNode=new Node<int>(root->data);

    if(currNode != NULL){
        //temp;
        head=currNode;
        while(currNode->next != NULL){
            currNode=currNode->next;
        }

        currNode->next=newNode;
        currNode=currNode->next;
    }
    else{
        currNode=newNode;
        head=currNode;
    }

   Node<int>* rightChildNode=constructBST(root->right);
   if(rightChildNode != NULL)
        currNode->next=rightChildNode;
        currNode=currNode->next;

    return head;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    Node<int>* head = constructBST(root);
    cout<<endl;
    while(head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
    }
}
