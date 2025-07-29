#include<iostream>
using namespace std;
int smallest(int arr[], int n){
    int lb=0;
    int ub=n-1;
    int index=-1;
    int mini=INT_MAX;
    while(lb<=ub){
        int mid=lb+(ub-lb)/2;
        if(arr[mid]>=arr[lb]){
            if(arr[lb]<mini){
                index=lb;
                mini=arr[lb];
            }
            lb=mid+1;
        }
        else{
            if(arr[mid]<mini){
                index=mid;
                mini=arr[mid];
            }
          
           ub=mid-1;
        }
    }
    return index;
}

int main(){
    int arr[5]={3,4,5,1,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int lowest_index=smallest(arr,n);
    cout<<lowest_index;
}