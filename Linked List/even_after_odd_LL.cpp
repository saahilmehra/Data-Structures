/*
Even after Odd LinkedList

Arrange elements in a given Linked List such that, all even numbers are placed after odd numbers. Respective order of elements should remain same.
Note: Input and Output has already managed for you. You don't need to print the elements, instead return the head of updated LL.

Input format:
Linked list elements (separated by space and terminated by -1)

Output format:
Print the elements of updated Linked list. 

Sample Input 1 :
1 4 5 2 -1

Sample Output 1 :
1 5 4 2 

Sample Input 2 :
1 11 3 6 8 0 9 -1

Sample Output 2 :
1 11 3 9 6 8 0
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

node* arrange_LinkedList(node* head)
{
    if(head==NULL){
        return head;
    }
    node* temp=head;
    node* even=NULL;
    node* odd=NULL;
    node* evenHeader=NULL;
    node* oddHeader=NULL;
    while(temp!=NULL){
        if(temp->data%2==0){
            if(evenHeader==NULL){
                even=temp;
                evenHeader=even;
            }
            else{
                even->next=temp;
                even=even->next;
            }
        }
        else{
            if(oddHeader==NULL){
                odd=temp;
                oddHeader=odd;
            }
            else{
                odd->next=temp;
                odd=odd->next;
            }
        }
        temp=temp->next;
    }

    if(evenHeader==NULL){
        return oddHeader;
    }

    if(oddHeader==NULL){
        return evenHeader;
    }

    even->next=NULL;
    odd->next=NULL;
    node* temp1=oddHeader;
    while(temp1!=NULL){
        if(temp1->next==NULL){
            temp1->next=evenHeader;
            return oddHeader;
        }
        temp1=temp1->next;
    }
    return oddHeader;
}

int main()
{
    node*head=takeinput();
    head=arrange_LinkedList(head);
    print(head);
    return 0;
}
