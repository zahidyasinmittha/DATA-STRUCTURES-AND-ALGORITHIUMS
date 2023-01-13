#include <iostream>
using namespace std;
struct node{
    int data;
    node* lchalid;
    node* rchalid;
};
node* root=NULL;
void search(node* r1,int n){
    if(r1==NULL){
        cout<<"element is not found!!"<<endl;
        return;
    }
    if(r1->data==n){
        cout<<"element found!!"<<endl;
        return;
    }
    if(n<r1->data){
        search(r1->lchalid,n);
    }
    else{
        search(r1->rchalid,n);
    }
}
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
node* in_order_successor(node* r1){
    while(r1->lchalid!=NULL && r1!=NULL){
        r1=r1->lchalid;
    }
    return r1;
}   
node* deletion(node* r1,int n){
    if(r1==NULL){
        cout<<"element is not found so can't delete it"<<endl;
        return r1;
    }
    else if(n>r1->data){
        r1->rchalid=deletion(r1->rchalid,n);
    }
    else if(n<r1->data){
        r1->lchalid=deletion(r1->lchalid,n);
    }
    else{
        if(r1->rchalid==NULL){
            node* temp=r1->rchalid;
            delete r1;
            return temp;
        }
        else if(r1->rchalid==NULL){
            node* temp=r1->lchalid;
            delete r1;
            return temp;
        }
        else{
            node* temp=in_order_successor(r1->rchalid);
            r1->data=temp->data;
            r1->rchalid=deletion(r1->rchalid,temp->data);
            return r1;
        }
    }
    return r1;
}
void display1(node* r1){
    if(r1==NULL)
    return;
    cout<<r1->data<<endl;
    display1(r1->lchalid);
    display1(r1->rchalid);
}
int main() {
    root=insertion(root,4); 
    root=insertion(root,5); 
    root=insertion(root,6); 
    root=insertion(root,7); 
    root=insertion(root,2); 
    root=insertion(root,3); 
    root=insertion(root,1);
    root=deletion(root,4);
    display1(root);
    return 0;
}