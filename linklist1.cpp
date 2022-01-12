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
 void nodeattail(node* &head,int value){
        node* n=new node(value);
        if (head==NULL){
            head=n;
            return;
        }
        
        node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        } temp->next=n;
    }
    void print(node*head){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }cout<<"NULL";
    }
    void insertathead(node* &head,int value){
        node* n=new node(value);
        n->next=head;
        head=n;
    }
    void todelete(node* &head,int value){
        node* temp=head;
      
        
        while(temp->next->data!=value){
            temp=temp->next;
        }
        node* deletion=temp->next;
        temp->next=temp->next->next;
        delete deletion;

       
    }
    

int main(){

    
    node* head = NULL;
    node* second = NULL;
    node* third = NULL;
 
    // allocate 3 nodes in the heap
    head = new node(1);
    second = new node(2);
    third = new node(3);
 
   // head->data = 1; // assign data in first node
    head->next = second; // Link first node with second
 
    //second->data = 2; // assign data to second node
    second->next = third;
 
    //third->data = 3; // assign data to third node
    third->next = NULL;
 
   // nodeattail(head,1);
    nodeattail(head,4);
    insertathead(head,5);
    todelete(head,2);
    print(head);

   
    return 0;
}