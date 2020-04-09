/*
AppendLastNToFirst

Given a linked list and an integer n, append the last n elements of the LL to front.
Indexing starts from 0. You don't need to print the elements, just update the elements and return the head of updated LL.
Assume given n will be smaller than length of LL.

Input format :
Line 1 : Linked list elements (separated by space and terminated by -1)`

Sample Input 1 :
1 2 3 4 5 -1
3

Sample Output 1 :
3 4 5 1 2
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

node* append_LinkedList(node* head,int n)
{
    int l=length(head);
    node *temp=head;
    node *head2=NULL;
    node *end=NULL;
    int count=1;
    while(temp!=NULL){
        if(count==l-n){
            end=temp;
        }
        if(count==l){
            break;
        }
        count++;
        temp=temp->next;
    }
    temp->next=head;
    head2=end->next;
    end->next=NULL;
    return head2;
}

int main()
{
    node* head=takeinput();
    int n;
    cin>>n;
    head=append_LinkedList(head,n);
    print(head);
    return 0;
}
