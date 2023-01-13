#include <iostream>
using namespace std;
struct node
{
    int data;
    node* pre;
    node* next;
};
void insertion(int n,int p,int *count,node** start,node** last)
{
    if(p>(*count))
    {
        cout<<"out of bound"<<endl;
    }
    else if(p==1 && *start==NULL)
    {
        node* temp=new node;
        temp->data=n;
        temp->pre=temp;
        temp->next=temp;
        *start=temp;
        *last=temp;
        (*count)++;
    }
    else if(p==1)
    {
        node* temp=new node;
        temp->data=n;
        temp->pre=*last;
        temp->next=*start;
        (*start)->pre=temp;
        (*last)->next=temp;
        *start=temp;
        (*count)++;
    }
    else
    {
        if(p==(*count))
        {
            node* temp=new node;
            temp->data=n;
            temp->pre=*last;
            temp->next=(*start);
            (*start)->pre=temp;
            (*last)->next=temp;
            *last=temp;
        }
        else
        {
            node* curr=*start;
            for(int i=1;i<p-1;i++)
            curr=curr->next;
            node* temp=new node;
            temp->data=n;
            temp->pre=curr;
            temp->next=curr->next;
            curr->next->pre=temp;
            curr->next=temp;
        }
        (*count)++;
    }
}
void deletion(int p,int *count,node** start,node** last){
    if(p>(*count))
    {
        cout<<"out of bound"<<endl;
    }
    else if((*count)==1)
    {
        cout<<"no node exist"<<endl;
    }
    else if(p==1)
    {
        node* temp=(*start);
        *start=temp->next;
        (*start)->pre=*last;
        (*last)->next=*start;
        delete temp;
        (*count)--;
    }
    else if(p==(*count))
    {
        node* temp=(*last);
        *last=temp->pre;
        (*last)->next=*start;
        (*start)->pre=*last;
        delete temp;
        (*count)--;
    }
    else{
        node* temp=(*start);
        for(int i=1;i<p;i++)
        temp=temp->next;
        temp->pre->next=temp->next;
        temp->next->pre=temp->pre;
        delete temp;
        (*count)--;
    }
}
void display(node** start,int count)
{
    node* curr=*start;
    for(int i=1;i<count;i++)
    {
        cout<<curr->data<<endl;
        curr=curr->next;
    }
}
int main(){
    node *a=NULL;
    node *a_last;
    int a_count=1;
    insertion(22,1,&a_count,&a,&a_last);
    insertion(1,2,&a_count,&a,&a_last);
    insertion(4,2,&a_count,&a,&a_last);
    insertion(5,4,&a_count,&a,&a_last);
    insertion(7,5,&a_count,&a,&a_last);
    deletion(5,&a_count,&a,&a_last);
    display(&a,a_count);
    return 0;
}