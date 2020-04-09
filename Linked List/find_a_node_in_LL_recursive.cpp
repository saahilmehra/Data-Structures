/*
Find a node in LL (recursive)

Given a linked list and an integer n you need to find and return index where n is present in the LL. Do this recursively.
Return -1 if n is not present in the LL.
Indexing of nodes starts from 0.

Input format :
Line 1 : Linked list elements (separated by space and terminated by -1)
Line 2 : Integer n 

Output format :
Index

Sample Input 1 :
3 4 5 2 6 1 9 -1
5

Sample Output 1 :
2

Sample Input 2 :
3 4 5 2 6 1 9 -1
6

Sample Output 2 :
4
*/

#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int indexOfNRecursive(Node *head, int n) {
  if(head==NULL)
    return -1;
  if(head->data==n)
    return 0;
  int s=indexOfNRecursive(head->next,n);
  if(s==-1)
    return -1;
  else return s+1;

}

int main() {
    Node *head = takeinput();
    int n;
    cin >> n;
    cout << indexOfNRecursive(head, n);

}

