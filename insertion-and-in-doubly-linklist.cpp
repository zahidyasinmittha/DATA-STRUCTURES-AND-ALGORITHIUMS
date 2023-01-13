//A CODE BY ERROR
#include <iostream>
using namespace std;
struct node{
    int data;
    node* next;
    node* pre;
    public:
    node(){
        next=NULL;
        pre=NULL;
    }
};
node* start=NULL;
node* curr;
int count=1;
void insertion(int n,int p){
if(p==1 && start==NULL){
    start=new node;
    start->data=n;
    count++;
}
else if(p==1){
    node* temp=new node;
    temp->data=n;
    start->pre=temp;
    temp->next=start;
    start=temp;
    count++;
}
else{
    node* temp=new node;
    temp->data=n;
    if(p==count && start!=NULL){
    curr=start;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    temp->next=NULL;
    temp->pre=curr;
    curr->next=temp;
    }
    else{
    curr=start;
    for(int i=1;i<p;i++){
    curr=curr->next;
    }
    temp->next=curr;
    temp->pre=curr->pre;
    curr->pre=temp;
    }
    count++;
}
}
void deletion(int n){
    if(count==1){
        cout<<"there no node present first make the node \n"<<endl;
    }
    else{
    node* temp=start;
    if(temp->data==n){
        count--;
        start=temp->next;
        if(start!=NULL)
        start->pre=NULL;
        delete temp;
    }
    else{
        while(temp!=NULL && temp->data!=n){
          temp=temp->next;       
        }
        if(temp==NULL){
        cout<<"item could not found"<<endl;
        }
        else if(temp->next==NULL){
            count--;
            (temp->pre)->next=NULL;
            delete temp;
        }
        else{
            count--;
            (temp->pre)->next=temp->next;
            (temp->next)->pre=temp->pre;
            delete temp;
        }
    }
}
}
void display(){
    if(count==1){
        cout<<"there no node present first insert the element\n"<<endl;
    }
    else{
    curr=start;
    while(curr!=NULL){
        cout<<curr->data<<endl;
        curr=curr->next;
    }
    }
}
int main() {
    int choice;
    int p;
    int element;
    start:
    cout<<"Press 1 for insert element in link list"<<endl;
    cout<<"Press 2 for delete element in link list"<<endl;
    cout<<"Press 3 for display element in link list"<<endl;
    cout<<"press any number to exist other than that:"<<endl;
    cin>>choice;
    switch(choice){
        case 1:
        cout<<"enter the element"<<endl;
        cin>>element;
        do{
            cout<<"enter the position of insertion of element"<<endl;
            cin>>p;
        }while(p>count);
        insertion(element,p);
        cout<<"element is inserted"<<endl;
        goto start;
        case 2:
        cout<<"enter the element"<<endl;
        cin>>element;
        deletion(element);
        goto start;
        break;
        case 3:
        display();
        goto start;
        default:
        break;
    }
  return 0;
}