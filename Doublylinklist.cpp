#include <iostream>
using namespace std;

class node{
    public:

   int data;
   node* next;
   node* prev;

   node(int value){
       data=value;
       next=NULL;
       prev=NULL;
   }
};

void insertathead(node* &head,int value){
    node* n=new node(value);
    n->next=head;
    if(head!=NULL){
        head->prev=n;
    }
    head=n;

}

void insertattail(node* &head,int value){

    if(head==NULL){
        insertathead(head,value);
        return;
    }
    node* n= new node(value);
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}
void deletathead(node* &head){
    node* todelete=head;
   head=head->next;
    head->prev=NULL;
    delete todelete;
}

void deletepos(node* &head,int pos){

    if( pos==1){
        deletathead(head);
        return;
    }
    node* temp=head;
    int count=1;
    while(temp!=NULL&&count!=pos){
        temp=temp->next;
        count++;
    }
    temp->prev->next=temp->next;
    if( temp->next!=NULL){
       temp->next->prev=temp->prev;
    }
    delete temp;
}

void  print(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }cout<<"NULL";
}

int main(){

    node* head=NULL;
    insertathead(head,6);
    insertattail(head,2);
     insertattail(head,3);
      insertattail(head,4);
       insertattail(head,5);
      // deletepos(head,3);

       print(head);

    
    return 0;
}