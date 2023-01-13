#include <iostream>
using namespace std;
int main(){
    int size;
    int j;
    cout<<"enter the number of element in array:";
    cin>>size;
    int array[size];
    for(int i=0;i<size;i++){
        cout<<"enter the "<<i+1<<" element of array:";
        cin>>array[i];
    }
    for(int i=1;i<size;i++){
        int key=array[i];
        for(j=i-1;j>=0 && array[j]>key ;j--){
            array[j+1]=array[j];
        }
        array[j+1]=key;
    }
    for(int i=0;i<size;i++){
        cout<<"The "<<i+1<<" element of array is:"<<array[i]<<endl;;
    }
}