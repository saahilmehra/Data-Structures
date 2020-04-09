/*
kReverse

Implement kReverse( int k ) in a linked list i.e. you need to reverse first K elements then reverse next k elements and join the linked list and so on.
Indexing starts from 0. If less than k elements left in the last, you need to reverse them as well. If k is greater than length of LL, reverse the complete LL.
You don't need to print the elements, just return the head of updated LL.

Input format :
	Line 1 : Linked list elements (separated by space and terminated by -1)
	Line 2 : k

Sample Input 1 :
1 2 3 4 5 6 7 8 9 10 -1
4

Sample Output 1 :
4 3 2 1 8 7 6 5 10 9

Sample Input 2 :
1 2 3 4 5 -1
2

Sample Output 2 :
2 1 4 3 5 

Sample Input 3 :
1 2 3 4 5 6 7 -1
3

Sample Output 3 :
3 2 1 6 5 4 7
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

node *reverse_linked_list(node *head)
{
    if(head==NULL||head->next==NULL)
        return head;
    node* smallhead=reverse_linked_list(head->next);
    head->next->next=head;
    head->next=NULL;
    return smallhead;
}

node* kReverse(node*head,int n)
{
    if(n==1)
        return head;
    int i=1;
    node*temp=head,*head1=head,*head2=head;
    while(temp!=NULL)
    {
        if(i%n==0||temp->next==NULL)
        {
            node*head3=temp->next;
            temp->next=NULL;
            node*h=head2;
            head2=reverse_linked_list(head2);
            if(head1==head){
                head1=head2;
                head=head2;
            }
                else
                    head1->next=head2;
            h->next=head3;
            head1=h;
            head2=head3;
            temp=head3;
        }
        else{
            temp=temp->next;
        }
        i++;
    }
    return head;
}

int main()
{
    node* head=takeinput();
    int n;
    cin>>n;
    head=kReverse(head,n);
    print(head);
    return 0;
}
