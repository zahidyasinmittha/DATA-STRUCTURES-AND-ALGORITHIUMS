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
void mid(){
node *temp1=start;
node *temp2=start;
if(start->link!=NULL && (start->link)->link!=NULL ){
while(temp2!=NULL  && temp2->link!=NULL)
{
temp2=temp2->link;
temp2=temp2->link;
temp1=temp1->link;
}
cout<<temp1->data<<endl;
}
else
cout<<"NO mid exsist"<<endl;
}
int main(){
  insertion(4); 
  insertion(5); 
  insertion(6);
  insertion(7); 
  insertion(8); 
        
  mid();
  return 0;}