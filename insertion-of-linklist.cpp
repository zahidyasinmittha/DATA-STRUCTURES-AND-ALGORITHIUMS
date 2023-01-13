#include <iostream>
using namespace std;
struct node{
    int data;
    node* link;
};
node* start=NULL;
node* curr;
void insertion(int n){
if(start==NULL){
    start=new node;
    start->data=n;
    start->link=NULL;
}
else{
    node* temp=new node;
    curr=new node;
    curr=start;
    while(curr->link!=NULL)
    curr=curr->link;
    temp->data=n;
    temp->link=NULL;
    curr->link=temp;
}
}
void insertion(int n,int p){
if(p==1){
    node* temp=new node;
    temp->data=n;
    temp->link=start;
    start=temp;
}
else{
    curr=start;
    node* temp=new node;
    temp->data=n;
    for(int i=1;i<p-1;i++)
    curr=curr->link;

    if(curr->link==NULL){
       temp->link=NULL;
       curr->link=temp;
    }
    else{
       temp->link=curr->link;
       curr->link=temp;
    }
}
}
void deletion(int n){
    node* pre=new node;
    node* temp=new node;
    temp=start;
    if(temp->data==n){
        start=temp->link;
        delete temp;
    }
    else{
        while(temp!=NULL && temp->data!=n){
          pre=temp;
          temp=temp->link;       
        }
        if(temp==NULL)
        cout<<"item could not found"<<endl;
        pre->link=temp->link;
        delete temp;
    }
}
void display(){
    curr=start;
    while(curr!=NULL){
        cout<<curr->data<<endl;
        curr=curr->link;
    }
}
int main() {
    insertion(4); 
     insertion(5); 
      insertion(6); 
       insertion(7); 
    display();
  return 0;
}