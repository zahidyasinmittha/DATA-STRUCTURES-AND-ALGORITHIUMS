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
    curr=start;
    while(curr->link!=NULL)
    curr=curr->link;
    temp->data=n;
    temp->link=NULL;
    curr->link=temp;
}
}
void deletion(){
    node* temp,*temp2,*temp1;
    temp1=start;
    while(temp1 != NULL){
    temp2=temp1;
    while(temp2->link != NULL){
    if(temp1->data==temp2->link->data){
        temp=temp2->link;
        temp2->link=temp2->link->link;
        delete (temp);
        }
        else
        temp2=temp2->link;
    }
    temp1=temp1->link;
}}
void display(){
    curr=start;
    while(curr!=NULL){
        cout<<curr->data<<endl;
        curr=curr->link;
    }
}
int main() {
    insertion(4); 
    insertion(4); 
    insertion (3);
    insertion (7);
    insertion (7);
    insertion (7);
    insertion (7);
    insertion (3);
    deletion();    
    display();
  return 0;
}