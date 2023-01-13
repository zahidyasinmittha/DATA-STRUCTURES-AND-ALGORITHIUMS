#include <iostream>
using namespace std;
int siz;
int element;
int front=-1;
int rear=-1;
int itemcount=0;
bool empty(){
    if(front==-1 && rear==-1){
        return true;
    }
    else{
        return false;
    }
}
bool full(){
    if(((rear+1)%siz)==front){
        return true;
    }
    else{
        return false;
    }
}
void enqueue(int queue[]){
    if(full()){
    cout<<"queue is full"<<endl;
    }
    else if(empty()){
        front=rear=0;
        queue[rear]=element;
        itemcount++;
    }
    else{
        rear=(rear+1)%siz;
        queue[rear]=element;
        itemcount++;
    }
    }
void dequeue(int queue[]){
    if(empty()){
        cout<<"queue is empty"<<endl;
    }
    else if(rear==front){
        front=rear=-1;
        itemcount=0;
    }
    else{
        front=(front+1)%siz;
        itemcount--;
    }
}
void display(int queue[]){
    if(empty()){
        cout<<"queue is empty"<<endl;
    }
    else{
    cout<<"element of queue are:"<<endl;
    int j=front;
    for(int i=0;i<itemcount;i++){
        cout<<queue[j]<<endl;
        j=(j+1)%siz;
    }
    }
}
int main() {
int choice;
cout <<"enter the size of queue:";
cin>>siz;
int a[siz];
while(1){
cout<<"\npress 1 to check queue is full or not"<<endl;
cout<<"press 2 to check queue is empty or not"<<endl;
cout<<"press 3 to insert element in queue"<<endl;
cout<<"press 4 to remove element in queue"<<endl;
cout<<"press 5 to display element of queue"<<endl;
cin>>choice;
switch(choice){
case 1:
if(full()){
cout<<"queue is full!"<<endl;
}
else{
cout<<"queue is not full!"<<endl;
}
break;
case 2:
if(empty()){
cout<<"queue is empty!"<<endl;
}
else{
cout<<"queue is not empty!"<<endl;
}
break;
case 3:
cout<<"enter the element you enter:";
cin>>element;
enqueue(a);
break;
case 4:
dequeue(a);
break;
case 5:
display(a);
break;
case 6:
break;
default:
cout<<"invalid input!"<<endl;
break;
}
}
  return 0;
}
