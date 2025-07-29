#include<iostream>
using namespace std;
int smallest(int arr[],int mini, int n){
    int lb=0;
    int ub=n-1;
    while(lb<=ub){
        int mid=lb+(ub-lb)/2;
        if(arr[mid]>arr[ub]){
           lb=mid+1;
        }
        else if(arr[mid]<arr[ub]){
          ub=mid;
        }else{
            ub--;
        }
    }
    return arr[lb];
}

int main(){
    int arr[5]={10,1,10,10,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    int mini=INT_MAX;
    int lowest=smallest(arr,mini,n);
    cout<<lowest;
}