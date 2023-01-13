#include <iostream>
using namespace std;
int main(){
    int size;
    cout<<"enter the number of element in array:";
    cin>>size;
    int array[size];
    for(int i=0;i<size;i++){
        cout<<"enter the "<<i+1<<" element of array:";
        cin>>array[i];
    }
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(array[i]>array[j]){
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
    for(int i=0;i<size;i++){
        cout<<"The "<<i+1<<" element of array is:"<<array[i]<<endl;;
    }
}