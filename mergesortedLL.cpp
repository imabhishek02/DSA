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
        head =n;
        return ;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    } temp->next=n;
}
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }cout<<"NULL"<<endl;
}
node* mergek(node* &head1,node* &head2){
    node* dumy=new node(-1);
    node* ptr1=head1;
    node* ptr2=head2;
    node* ptr3=dumy;

    while(ptr1!=NULL&&ptr2!=NULL){
        if(ptr1->data < ptr2->data){
          ptr3->next=ptr1;
          ptr1=ptr1->next;
        }
        else{
            ptr3->next=ptr2;
            ptr2=ptr2->next;
        }
        ptr3=ptr3->next;
        
    }
    while(ptr1!=NULL){
        ptr3->next=ptr1;
        ptr1=ptr1->next;
        ptr3=ptr3->next;
    }
    while(ptr2!=NULL){
        ptr3->next=ptr2;
        ptr2=ptr2->next;
        ptr3=ptr3->next;
    }
    return dumy->next;

}

int main(){
    node* head1=NULL;
    node* head2=NULL;
    insertattail(head1,1);
    insertattail(head1,2);
    insertattail(head1,3);
    insertattail(head2,4);
    insertattail(head2,5);
    insertattail(head2,6);
    insertattail(head2,7);
   display(head1);
   display(head2);
    //mergek(head1,head2);
    node* newhead=mergek(head1,head2);
    display(newhead);
    
    return 0;
}