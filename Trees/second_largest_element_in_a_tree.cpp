/*
Second Largest Element In Tree

Given a generic tree, find and return the node with second largest value in given tree. Return NULL if no node with required value is present.

Input format :
Line 1 : Elements in level order form separated by space (as per done in class). Order is -
Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element 

Output Format :
Second Largest node data

Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 

Sample Output 1 :
40
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
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

template <typename T>
class SecondLargestReturnType {
	public :
	TreeNode<T> *largest;
	TreeNode<T> *secondLargest;

	SecondLargestReturnType(TreeNode<T> *first, TreeNode<T> *second) {
		this -> largest = first;
		this -> secondLargest = second;
	}
};

SecondLargestReturnType<int>* secondLargestHelper(TreeNode<int> *root) {
		if(root == NULL) {
			SecondLargestReturnType<int> *ans = new SecondLargestReturnType<int>(NULL, NULL);
			return ans;
		}
		SecondLargestReturnType<int> *ans = new SecondLargestReturnType<int>(root, NULL);
		for(int i = 0; i < root -> children.size(); i++) {
			SecondLargestReturnType<int> *childAns = secondLargestHelper(root -> children[i]);
			if(childAns -> largest -> data > ans -> largest -> data ) {
				if(childAns -> secondLargest == NULL) {
					ans -> secondLargest = ans -> largest;
					ans -> largest = childAns -> largest;
				}
				else {
					if(childAns -> secondLargest -> data > ans -> largest -> data) {
						ans -> secondLargest = childAns -> secondLargest;
						ans -> largest = childAns -> largest;
					}
					else {
						ans -> secondLargest = ans -> largest;
						ans -> largest = childAns -> largest;
					}
				}
			}
			else {
				if(ans -> largest -> data != childAns -> largest -> data && (ans -> secondLargest == NULL || childAns -> largest -> data > ans -> secondLargest -> data)) {
					ans->secondLargest = childAns -> largest;
				}
			}
		}
		return ans;
}

TreeNode <int>* secondLargest(TreeNode<int> *root) {
	return secondLargestHelper(root) -> secondLargest;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = secondLargest(root);
    if(ans == NULL) {
        cout << INT_MIN << endl;
    }
    else {
        cout << ans -> data << endl;
    }
}
