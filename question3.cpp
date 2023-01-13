#include <iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
int counter=0;
node* start=NULL;
node* last=start;
void insertion(int n){
if(start==NULL){
    start=new node;
    start->data=n;
    start->next=start;
    last=start;
    counter++;
}
else{
    node* temp=new node;
    temp->data=n;
    temp->next=last;
    last->next=temp;
    last=temp;
    counter++;
}
}
void second_maximum(){
    node* cur=start;
    int maximum=cur->data;
    int s_maximum;
    for(int i=1;i<=counter;i++){
        if (cur->data > maximum) {
        s_maximum = maximum;
        maximum = cur->data;
    }
    else if (cur->data > s_maximum)
        s_maximum = cur->data;
        cur = cur->next;
    }
    cout<<"second higest number is:"<<s_maximum<<endl;
}
int main(){
insertion(3);
insertion(9);
insertion(4);
insertion(6);
insertion(1);
second_maximum();
return 0;
}