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
    while (temp->next!=NULL){
    temp=temp->next;
    }
    temp->next=n;
    }

int length(node* head){
    node* temp=head;
    int l=0;
    while(temp!=NULL){
       l++;
    temp=temp->next;
    }
    return l;
}
node* kappend(node* &head,int k){
    node* newhead;
    node* newtail;
    node* tail=head;
   

    int l=length(head);
    k=k%l;
    int count=1;
    while (tail->next!=NULL)
    {
        if(count==l-k){
            newtail=tail;
        }
        if(count==l-k+1){
            newhead=tail;
        }
        tail=tail->next;
        count++;
       
    }
    newtail->next=NULL;
    tail->next=head;
    
    
    return newhead;

}


void printk(node* head){
    node* temp=head;

    while( temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }cout<<"NULL"<<endl;
}
int main(){
    node* head=NULL;
    insertattail(head,1);
    insertattail(head,2);
    insertattail(head,3);
    insertattail(head,4);
    insertattail(head,5);
   
    insertattail(head,6);
    printk(head);
    node* Newhead=kappend(head,3);
    printk(Newhead);
  //  printk Newhead(head);
   
   
  
    
    return 0;
}