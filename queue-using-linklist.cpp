#include <iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
node* front=NULL;
node* rear=NULL;
void insertion(int n){
if(rear==NULL){
    rear=new node;
    rear->data=n;
    rear->next=NULL;
    front=rear;
}
else{
    node* temp=new node;
    temp->data=n;
    temp->next=NULL;
    rear->next=temp;
    rear=temp;
}
}
void deletion(){
    if(front==NULL){
        cout<<"empty"<<endl;
    }
    else if(rear==front){
        node* temp=front;
        front=NULL;
        rear=NULL;
        delete temp;
    }
    else{
        node* temp=front;
        front=front->next;
        delete temp;
    }
}
void display(){
    if(front==NULL){
        cout<<"empty"<<endl;
    }
    else{
    node* temp =front;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }}
}
int main() {
   insertion(3);
   insertion(4);
   insertion(5);
   display();
   deletion();
   deletion();
   deletion();
   display();
    return 0;
}