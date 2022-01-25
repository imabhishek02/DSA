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

void insertattail(node* &head,int value){
    node* n=new node(value);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }temp->next=n;
}
node* recursivecall(node* &head1,node* &head2){

    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    node* result;
    if(head1->data<head2->data){
        result=head1;
        result->next=recursivecall(head1->next,head2);
    }else{
    result=head2;
    result->next=recursivecall(head1,head2->next);
    }
    return result;
}
void display(node* head){
    node* temp=head;
    while (temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }cout<<"NULL"<<endl;
    
}

int main(){
     node* head1=NULL;
    node* head2=NULL;
    insertattail(head1,1);
    insertattail(head1,3);
    insertattail(head1,9);
    insertattail(head2,4);
    insertattail(head2,5);
    insertattail(head2,6);
    insertattail(head2,7);
   display(head1);
   display(head2);
   node* newhead=recursivecall(head1,head2);
   display(newhead);
    
    return 0;
}