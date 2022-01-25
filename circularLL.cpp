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
void insertathead(node* &head,int value){
    node* n=new node(value);
    if(head==NULL){
        n->next=n;
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }temp->next=n;
    n->next=head;
    head=n;
}

void insertattail(node* &head,int value){
    node* n=new node(value);
    if(head==NULL){
        insertathead(head,value);
        return;
    }
    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }temp->next=n;
    n->next=head;
}
void deleteathead(node* &head){
    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    node* todelete=head;
    head->next=head;
    delete todelete;
}
void deletion(node* &head,int pos){
    if(pos==1){
        deleteathead(head);
        return;
    }
    node* temp=head;
    int count=1;
    while(count!=pos-1){
     temp=temp->next;
     count++;
    } 
    node* todelete= temp->next;
    temp->next=temp->next->next;
    delete todelete;

}

void display(node* head){
    node* temp=head;
    do{
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    while(temp!=head);
       // cout<<temp->data<<"->";
        //temp=temp->next;
    
    
    
}

int main(){
    node* head=NULL;
     insertattail(head,4);
    insertattail(head,5);
    insertattail(head,6);
    insertattail(head,7);
   deletion(head,2);
    display(head);
    
    return 0;
}