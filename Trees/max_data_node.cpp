/*
Max data node

Given a generic tree, find and return the node with maximum data. You need to return the complete node which is having maximum data.
Return null if tree is empty.

Input format :
Elements in level order form separated by space (as per done in class). Order is - 
Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element 

Output Format :
Node with largest data

Sample Input :
10 3 20 30 40 2 40 50 0 0 0 0 

Sample Output :
50
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) {
        this->data = data;
    }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    if(root==NULL)
        return root;

    TreeNode<int>* max=root;

    for(int i=0; i<root->children.size(); i++){
        TreeNode<int>* res = maxDataNode(root->children[i]);
        if(res->data > max->data){
            max=res;
        }
    }
    return max;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = maxDataNode(root);
    if(root != NULL) {
       	cout << ans -> data;
    }
}
