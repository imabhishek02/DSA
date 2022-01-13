#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int value){
        data= value;
        next=NULL;
    }
};

node* reverseknode(node* &head,int k){
    node* pre=NULL;
    node* curr=head;
    node* nextp;
     int count=0;
     while(curr!=NULL&&count<k){
         nextp=curr->next;
         curr->next=pre;
         pre=curr;
         curr=nextp;
         count++;
     }
     if(nextp!=NULL){
     head->next=reverseknode(nextp,k);
     } return pre;
     
     
}
void printk(node* head){
    node* temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }cout<<"NULL";
    
}

int main(){


    node* head=NULL;
    node* second=NULL;
    node* third=NULL;
    node* fourth=NULL;
    node* five=NULL;

    head=new node(1);
    second=new node(2);
    third=new node(3);
    fourth=new node(4);
    five=new node(5);

    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=five;
    five->next=NULL;

    node* newhead=reverseknode(head,2);
    printk(newhead);



    return 0;
}