#include <iostream>
using namespace std;
struct node{
    int data;
    node* link;
};
node * curr;
node * l3= NULL;
node* l1=NULL;
node* l2=NULL;

void insertion(int n,node** start){
    if((*start)==NULL){
    node* temp=new node;
    temp->data=n;
    temp->link=NULL;
    *start=temp;
    }
    else{
    node* temp=new node;
    curr=(*start);
    while(curr->link!=NULL)
    curr=curr->link;
    temp->data=n;
    temp->link=NULL;
    curr->link=temp;
    }
}
void uni(){
    node* temp=l1;
    node* temp1;
    temp1=l2;
while(temp!=NULL){
insertion(temp->data,&l3);
temp=temp->link;
}
while(temp1!=NULL){
    insertion(temp1->data,&l3);
    temp1=temp1->link;
}
temp1=l3;
node* temp2;
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
}
}
void display(){
    curr=l3;
    while(curr!=NULL){
        cout<<curr->data<<endl;
        curr=curr->link;
    }
}
int main() {
   insertion(2,&l1);
   insertion(3,&l1);
   insertion(4,&l1);
   insertion(2,&l2);
   insertion(6,&l2);
   insertion(7,&l2);
   uni();
   display();
    return 0;
}