#include <iostream>
using namespace std;
struct node{
    int data;

    node *address;
};
node *top=NULL;

void insertion(int x){
    if(top==NULL){
      top=new node;
      top->data=x;
      top->address=NULL; 
    }
    else{
        node *temp=new node;
        temp->data=x;
        temp->address=top;
        top=temp;
    }
}
    void display(){
        node *temp;
        temp=top;
        while(temp!=NULL){
            cout<<temp->data<<endl;
            temp=temp->address;
        }

    }
    void dletion(){
        if(top==NULL){
            cout<<"empty"<<endl;
        }
        else{
        node *temp;
        temp=top;
        top=top->address;
        delete temp;
        }
    }
int main() {
    
   insertion(3);
insertion(4);
insertion(7);
dletion();
dletion();
display();
    return 0;
}