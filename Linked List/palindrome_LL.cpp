/*
Palindrome LinkedList

Check if a given linked list is palindrome or not. Return true or false.
Indexing starts from 0.

Input format : Linked list elements (separated by space and terminated by -1)

Sample Input 1 :
9 2 3 3 2 9 -1

Sample Output 1 :
true

Sample Input 2 :
0 2 3 2 5 -1

Sample Output 2 :
false
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

bool check_palindrome(node* head)
{
    node*j,*i=head,*temp=head;
    while(temp!=NULL&&temp->next!=NULL)
    {
        i=i->next;
        temp=temp->next->next;
    }
    j=i;
    node*smallhead=reverse_linked_list(i);
    temp=head;
    while(temp!=NULL&&smallhead!=NULL)
    {
        if(temp->data==smallhead->data)
        {
            temp=temp->next;
            smallhead=smallhead->next;
        }
        else
            return false;
    }
    return true;
}

int main()
{
    node*head=takeinput();
    bool ans=check_palindrome(head);
    if(ans)
        cout<<"true";
    else
        cout << "false";
    return 0;
}
