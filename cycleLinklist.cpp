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

void printk( node* &head){
    node* temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }cout<<"NULL"<<endl;
    
}
void makecycle(node* &head,int pos){
     node* temp=head;
     node* startnode;

    int count=1;
     while(temp->next!=NULL){
         if(count==pos){
             startnode=temp;
         }
         temp=temp->next;
         count++;
     }temp->next=startnode;
}
bool detectcycle(node* &head){
    node* slow=head;
    node* fast=head;

    while(fast!=NULL && fast->next!=NULL){
         slow=slow->next;
         fast=fast->next->next;

         if(fast==slow){
             return true;
             
         }
    }return false;
}
void removecycle(node* &head){
    node* slow=head;
    node* fast=head;
    do{
        slow=slow->next;
        fast=fast->next->next;
    }while(fast!=slow);
    fast=head;

    while(fast->next!=slow->next){
        fast=fast->next;
        slow=slow->next;
    } slow->next=NULL;
}

int main(){

    node* head=NULL;
    node* first=NULL;
    node* second=NULL;
    node* third=NULL;
    node* fourth=NULL;
    node* five=NULL;
    
    head= new node(1);
    first=new node(2);
    second=new node(3);
    third=new node(4);
    fourth=new node(5);
    five=new node(6);

    head->next=first;
    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=five;
    five->next=NULL;

    printk(head);
    makecycle(head,3);
   // printk(head);
   detectcycle(head);
   cout<<detectcycle(head)<<endl;
   removecycle(head);
   printk(head);
   cout<<detectcycle(head)<<endl;
    return 0;
}