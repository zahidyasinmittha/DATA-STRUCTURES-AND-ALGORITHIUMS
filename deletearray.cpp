#include <iostream>
using namespace std;

int main() {
    int siz=5;
  int a[siz]={1,2,3,4,5};
  int b[4];
  for(int i=2;i<siz-1;i++){
    a[i]=a[i+1];
    cout<<a[i];
  }
  for(int i=0;i<4;i++){
    cout<<a[i];
  }
  return 0;
}