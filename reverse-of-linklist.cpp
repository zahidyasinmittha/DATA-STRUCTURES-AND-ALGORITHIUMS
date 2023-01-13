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
void reverse(){
    node* pre=NULL;
    node* next;
    curr=start;
    if(curr->link==NULL && curr==NULL){
        cout<<"reverse cannot possible"<<endl;
    }
    else{
        next=curr->link;
        while(next!=NULL){
        curr->link=pre;
        pre=curr;
        curr=next;
        next=next->link;
        if(curr->link==NULL)
        curr->link=pre;
        }
        start=curr;
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
       reverse(); 
    display();
  return 0;
}