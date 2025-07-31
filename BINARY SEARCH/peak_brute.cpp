#include<iostream>
using namespace std;
int peak_(int arr[],int size){
    for(int i=0;i<size;i++){
        if((i==0 || arr[i-1]<arr[i]) && (i==size-1 || arr[i]>arr[i+1])){
            return arr[i];
        }
    }
    return 0;
}
int main(){
    int arr[4]={1,2,3,1};
    int size=sizeof(arr)/sizeof(arr[0]);
    int peak=peak_(arr,size);
    cout<<peak;
}