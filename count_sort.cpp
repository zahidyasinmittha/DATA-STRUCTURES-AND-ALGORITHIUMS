#include <iostream>
using namespace std;
int main(){
    int size,maximum;
    cout<<"enter the number of element in array:";
    cin>>size;
    int array[size];
    for(int i=0;i<size;i++){
        cout<<"enter the "<<i+1<<" element of array:";
        cin>>array[i];
    }
    maximum=array[0];
    for(int i=1;i<size;i++){
        if(maximum<array[i])
        maximum=array[i];
    }
    int array1[maximum+1];
    for(int i=0;i<maximum+1;i++){
        array1[i]=0;
    }
    for(int i=0;i<size;i++){
        int temp=array[i];
        array1[temp]+=1;;
    }
    int sum=0;
    for(int i=1;i<maximum+1;i++){
        array1[i]+=array1[i-1];
    }
    int sorted_array[size];
    for(int i=0;i<size;i++){
        sorted_array[array1[array[i]]-1]=array[i];
        (array1[array[i]])--;
    }
    for(int i=0;i<size;i++){
        cout<<"The "<<i+1<<" element of array is:"<<sorted_array[i]<<endl;;
    }
}