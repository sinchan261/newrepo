#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
    node *previous;
};
void push(node **head_ref,int key){
node *newnode=new node();
newnode->data=key;
newnode->next=*head_ref;
newnode->previous=NULL;
if(*head_ref!=NULL){
(*head_ref)->previous=newnode;
}
(*head_ref)=newnode;
}
void print(node *n){
    int count=0;
    while(n!=NULL){
        cout<<n->data<<endl;
        n=n->next;
    }
    return;
}
void insertafter(node *pre,int key){
    node *newnode=new node();
    newnode->data=key;
    newnode->next=pre->next;
pre->next=newnode;                                        //insertin middle
newnode->previous=pre;
    if(newnode->next!=NULL){
        newnode->next->previous=newnode;
    }
return;
}
void insertlast(node **head_ref,int key){
    node *newnode=new node;
    newnode->data=key;
    newnode->next=NULL;
    if(*head_ref==NULL){
        newnode->previous=NULL;
        *head_ref=newnode;
        return;
    }
    node *last=*head_ref;
    while(last->next!=NULL){
        last=last->next;
    }
    last->next=newnode;
    newnode->previous=last;
    return;
}
int main(){
node *head=NULL;
push(&head,6);
push(&head,7);
push(&head,8);
// 8 7 9 6
//insertafter(head->next->next,9);
insertlast(&head,76);
print(head);
}