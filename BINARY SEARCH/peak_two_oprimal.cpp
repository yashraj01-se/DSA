#include<iostream>
using namespace std;
int peak_(int arr[],int size){
    if(size==1)return 0;
    if(arr[0]>arr[1])return 0;
    if(arr[size-1]>arr[size-2])return size-1;
    int lb=2;
    int ub=size-2;
    while(lb<=ub){
        int mid=lb+(ub-lb)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])return mid;
        else if(arr[mid]>arr[mid-1])lb=mid+1;
        else if(arr[mid]>arr[mid+1])ub=mid-1;
        else lb=mid+1;                        // for valley....
    }
    return -1;
}
int main(){
    int arr[6]={1,2,3,1,5,1};
    int size=sizeof(arr)/sizeof(arr[0]);
    int peak=peak_(arr,size);
    cout<<peak;
}