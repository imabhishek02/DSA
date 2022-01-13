#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int value){
     data=value;
     next=NULL;
    }
};

void printk(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }cout<<"NULL"<<endl;
}
node* reverserecursive(node* &head){

    if(head==NULL || head->next==NULL){
        return head;
    }
    node* newhead=reverserecursive(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}

int main(){

node* head=NULL;
node* second=NULL;
node* third=NULL;

head=new node(1);
second=new node(2);
third=new node(3);

head->next=second;
second->next=third;
third->next=NULL;

printk(head);


node* newhead=reverserecursive(head);

printk(newhead);

    return 0;
}