/*
Delete every N nodes

Given a linked list and two integers M and N. Traverse the linked list such that you retain M nodes then delete next N nodes, continue the same until end of the linked list. That is, in the given linked list you need to delete N nodes after every M nodes.

Input format :
	Line 1 : Linked list elements (separated by space and terminated by -1)\
	Line 2 : M
	Line 3 : N

Sample Input 1 :
1 2 3 4 5 6 7 8 -1
2
2

Sample Output 1 :
1 2 5 6

Sample Input 2 :
1 2 3 4 5 6 7 8 -1
2
3

Sample Output 2 :
1 2 6 7
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

node* skipMdeleteN(node *head, int M, int N) {
    if(M==0){
        return NULL;
    }
    if(N==0){
        return head;
    }
    node *temp=head;
    node *final=NULL, *finalHeader=NULL;
    int count=0;
    int skip=0;
    while(temp!=NULL){
        if(count==M){
            skip++;
            if(skip==N){
                skip=0;
                count=0;
            }
        }
        else{
            if(finalHeader==NULL){
                final=temp;
                finalHeader=final;
            }
            else{
                final->next=temp;
                final=final->next;
            }
            count++;
        }
        temp=temp->next;
    }
    final->next=NULL;
    return finalHeader;
}

int main()
{
    node* head=takeinput();
    int m,n;
    cin>>m >> n;
    head= skipMdeleteN(head,m,n);
    print(head);
    return 0;
}
