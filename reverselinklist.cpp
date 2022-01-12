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
void printk (node* head){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }cout<<"NULL";
    }
node* reversek(node* &head){
    node* preptr=NULL;
    node* cur=head;
    node* nxt;

    while(cur!=NULL){
        nxt=cur->next;
        cur->next=preptr;

        preptr=cur;
        cur=nxt;
    }
    return preptr;


}



int main(){

    node* head=NULL;
    node* first=NULL;
    node* second=NULL;

    head=new node(1);
    first=new node(2);
    second=new node(3);

    head->next=first;
    

    first->next=second;
    

    second->next=NULL;

    node* newhead=reversek(head);
    printk(newhead)
    
  ;  
    return 0;
}