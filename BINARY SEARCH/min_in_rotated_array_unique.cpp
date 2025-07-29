#include<iostream>
using namespace std;
int smallest(int arr[],int mini, int n){
    int lb=0;
    int ub=n-1;
    while(lb<=ub){
        int mid=lb+(ub-lb)/2;
        if(arr[mid]>=arr[lb]){
            mini=min(mini,arr[lb]);
            lb=mid+1;
        }
        else{
           mini=min(mini,arr[mid]);
           ub=mid-1;
        }
    }
    return mini;
}
int main(){
    int arr[7]={6,67,67,4567,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int mini=INT_MAX;
    int lowest=smallest(arr,mini,n);
    cout<<lowest;
}