/*
Code: Midpoint of LL

Given a linked list, find and return the midpoint.
If the length of linked list is even, return the first mid point.

Input format : Linked list elements (separated by space and terminated by -1)`

Sample Input 1 :
1 2 3 4 5 -1

Sample Output 1 :
3

Sample Input 2 :
1 2 3 4 -1

Sample Output 2 :
2
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

int length(node *head) {
    if(head==NULL){
        return 0;
    }
    return 1+length(head->next);
}

node* midpoint_linkedlist(node *head)
{
    int len=length(head);
    int mid=len/2;
    node *temp=head;
    int count=1;
    while(temp!=NULL){
        if(count==mid){
            return temp;
        }
        count++;
        temp=temp->next;
    }
    return head;
}

int main(){
    node*head=takeinput();
    node* mid=midpoint_linkedlist(head);
    cout<<mid->data;
    return 0;
}


