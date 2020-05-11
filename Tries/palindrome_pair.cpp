/*
Palindrome Pair

Givan n number of words, you need to find if there exist any two words which can be joined to make a palindrome or any word itself is a palindrome.
Return true or false.

Input Format :
Line 1 : Integer n
Line 2 : n words (separated by space)

Output Format :
true ot false

Sample Input 1 :
4
abc def ghi cba

Sample Output 2 :
true

Sample Output 1 Expalanation :
"abc" and "cba" forms a palindrome

Sample Input 2 :
4
abc def ghi hg

Sample Output 2 :
true

Sample Output 2 Expalanation :
"ghi" and "hg" forms a palindrome
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;
	int childCount;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
		childCount = 0;
	}
};

class Trie {
	TrieNode *root;

	public :
	int count;

	Trie() {
		this->count = 0;
		root = new TrieNode('\0');
	}

	bool insertWord(TrieNode *root, string word) {
		// Base case
		if(word.size() == 0) {
			if (!root->isTerminal) {
				root -> isTerminal = true;
				return true;
			} else {
				return false;
			}
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			child = new TrieNode(word[0]);
			root -> children[index] = child;
			root->childCount++;
		}

		// Recursive call
		return insertWord(child, word.substr(1));
	}

	// For user
	void insertWord(string word) {
		if (insertWord(root, word)) {
			this->count++;
		}
	}

	/*
	is all child of a root is empty
	return true if all child empty
	return false if atleast one child is not empty
	*/
	bool isAllChildEmpty(TrieNode *root) {
		for (int i = 0; i < 26; i++) {
			if (root->children[i] != NULL) {
				return false;
			}
		}
		return true;
	}

	/*
	checks if given string is palindrome
	*/
	bool isPalindrome(string word) {
		for (int i = 0, j = word.length()-1; i <= j; i++, j--) {
			if (word[i] != word[j]) {
				return false;
			}
		}
		return true;
	}

	/*
	return index of childrens of a given
	*/
	int getIndex(TrieNode *root) {
		for (int i = 0; i < 26; i++) {
			if (root->children[i] != NULL) {
				return i;
			}
		}
		return -1;
	}

	/*
	function to check if remaining nodes in the trie is palindrome
	*/
	bool checkRemaningNodes(TrieNode *root, string str) {
		if (root->childCount == 0) {
			if (isPalindrome(str)) {
				return true;
			}
			return false;
		}

		int childIndex = getIndex(root);
		TrieNode *child = root->children[childIndex];
		// root->children[childIndex] = NULL;
		char s = childIndex + 'a';
		str += s;

		return checkRemaningNodes(child, str);
	}

	bool newSearch(TrieNode *root, string word) {
		if(word.size() == 0) {
			//return root -> isTerminal;
			if (root->childCount == 0) {
				return true;
			} else {
				return checkRemaningNodes(root, "");
			}
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			return false;
		}

		// Recursive call
		return newSearch(child, word.substr(1));
	}


	bool newSearch(string word) {
		return newSearch(root, word);
	}

	bool searchPalindromeTrie(vector<string> arr) {
		for (int i = 0; i < arr.size(); i++) {
			string str = arr[i];
			string reverseStr = "";
			for (int j = str.length()-1; j >= 0; j--) {
				reverseStr += str[j];
			}

			if (newSearch(reverseStr)) {
				return true;
			}
		}
		return false;
	}

	bool findIfPalindromePair(vector<string> arr) {
		vector<string> new_arr;
		for (int i = 0; i < arr.size(); i++) {
			string s = arr[i];
			insertWord(s);
		}
		return searchPalindromeTrie(arr);
	}
};

int main() {
    Trie t;
    vector <string> vect;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        vect.push_back(word);
    }

    bool ans = t.findIfPalindromePair(vect);
    if (ans){
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}
