/*
Largest BST

Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree.
Return the height of largest BST.

Input format :
Line 1 : Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)

Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1

Sample Output 1:
2
*/

#include <iostream>
#include <queue>
#include <climits>
#include <cmath>
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

class bstSubtreeReturn {
	public :
	int max;
	int min;
	int height;
	bool isBST;
};

bstSubtreeReturn largestBSTSubtreeHelper(BinaryTreeNode<int> *root) {
	if(root == NULL) {
		bstSubtreeReturn ans;
		ans.max = INT_MIN;
		ans.min = INT_MAX;
		ans.isBST = true;
		ans.height = 0;
		return ans;
	}
	bstSubtreeReturn left = largestBSTSubtreeHelper(root -> left);
	bstSubtreeReturn right = largestBSTSubtreeHelper(root -> right);
	if (!(right.isBST && right.min > root -> data)) {
		right.isBST = false;
	}
	if (!(left.isBST && left.max < root -> data)) {
		left.isBST = false;
	}
	bstSubtreeReturn ans;
	if(!left.isBST || !right.isBST || root -> data < left.max || root -> data > right.min) {
		if(left.height > right.height) {
            left.isBST = false;
			return left;
		}
		else {
            right.isBST = false;
			return right;
		}
	}
	ans.isBST = true;
	ans.min = min(left.min, min(right.min, root -> data));
	ans.max = max(left.max, max(right.max, root -> data));
	ans.height = max(left.height, right.height) + 1;
	return ans;
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
	return largestBSTSubtreeHelper(root).height;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << largestBSTSubtree(root);
    delete root;
}
