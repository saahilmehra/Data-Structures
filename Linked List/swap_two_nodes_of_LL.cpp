/*
Swap two Node of LL

Given a linked list, i & j, swap the nodes that are present at i & j position in the LL. You need to swap the entire nodes, not just the data.
Indexing starts from 0. You don't need to print the elements, just swap and return the head of updated LL.
Assume i & j given will be within limits. And i can be greater than j also.

Input format :
	Line 1 : Linked list elements (separated by space and terminated by -1)
	Line 2 : i and j (separated by space)

Sample Input 1 :
3 4 5 2 6 1 9 -1
3 4

Sample Output 1 :
3 4 5 6 2 1 9

Sample Input 2 :
3 4 5 2 6 1 9 -1
2 4

Sample Output 2 :
3 4 6 2 5 1 9
*/

#include <iostream>
using namespace std;

class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}

void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

node* swap_nodes(node *head,int i,int j)
{
    node *temp = head, *prev = NULL;
    node *node1 = NULL, *node2 = NULL, *node1_prev = NULL, *node2_prev = NULL;
    int pos = 0;
    while(temp != NULL) {
        if(pos == i) {
            node1_prev = prev;
            node1 = temp;
        }
        else if(pos == j) {
            node2_prev = prev;
            node2 = temp;
        }
        prev = temp;
        temp = temp -> next;
        pos++;
    }

    if(node1_prev != NULL) {
        node1_prev -> next = node2;
    }
    else {
        head = node2;
    }

    if(node2_prev != NULL) {
        node2_prev -> next = node1;
    }
    else {
        head = node1;
    }

    node *temp1 = node2 -> next;
    node2 -> next = node1 -> next;
    node1 -> next = temp1;

    return head;
}

int main()
{
    int i,j;
    node* head =takeinput();
    cin>>i;
    cin>>j;
    head=swap_nodes(head,i,j);
    print(head);
    return 0;
}

