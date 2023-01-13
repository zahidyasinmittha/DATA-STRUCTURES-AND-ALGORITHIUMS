#include <iostream>
using namespace std;
struct node{
    int data;
    node* lchalid;
    node* rchalid;
};
node* root=NULL;
node* insertion(int n){
    node* temp=new node;
    temp->data=n;
    temp->lchalid=NULL;
    temp->rchalid=NULL;
    return temp;
}
node* insertion(node* r1,int n){
    if(r1==NULL){
        r1=insertion(n);
        return r1;
    }
    else if(n<r1->data){
        r1->lchalid=insertion(r1->lchalid,n);
    }
    else{
        r1->rchalid=insertion(r1->rchalid,n);
    }
    return r1;
}
int maximum=0;
int s_maximum1;
void s_maximum(node* r1){
    if(r1==NULL){
    cout<<"no second nummber exist"<<endl;
    return;
    }
    else if(r1->rchalid->rchalid==NULL || r1->rchalid==NULL){
    cout<<r1->data<<endl;
    return;
    }
    s_maximum(r1->rchalid);
}
int main() {
    root=insertion(root,4); 
    root=insertion(root,5); 
    root=insertion(root,6); 
    root=insertion(root,7); 
    root=insertion(root,2); 
    s_maximum(root);
    return 0;
}