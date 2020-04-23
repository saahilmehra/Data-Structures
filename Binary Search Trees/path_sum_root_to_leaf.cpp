/*
Path Sum Root to Leaf

Given a binary tree and a number k, print out all root to leaf paths where the sum of all nodes value is same as the given number k.

Input format :
Line 1 : Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Line 2 : k

Output format : 
Print each path in new line, elements separated by space

Sample Input 1 :
5 6 7 2 3 -1 1 -1 -1 -1 9 -1 -1 -1 -1
13

Sample Output 1 :
5 6 2
5 7 1
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

#include <vector>

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, vector<int> &path, int k) {
	if(root == NULL) {
		return;
	}

	k -= root -> data;
	path.push_back(root -> data);

	if(root -> left == NULL && root -> right == NULL) {
		if(k == 0) {
			for(int i = 0; i < path.size(); i++) {
				cout << path[i] << " ";
			}
			cout << endl;
		}
		path.pop_back();
		return;
	}

	rootToLeafPathsSumToK(root -> left, path, k);
	rootToLeafPathsSumToK(root -> right, path, k);
	path.pop_back();
}

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
	vector<int> path;
	rootToLeafPathsSumToK(root, path, k);
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int k;
    cin >> k;
    rootToLeafPathsSumToK(root, k);
    delete root;
}
