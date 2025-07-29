#include<iostream>
using namespace std;
int smallest(int arr[], int n){
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
    return lb;
}

int main(){
    int arr[5]={3,4,5,1,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int lowest_index=smallest(arr,n);
    cout<<lowest_index;
}