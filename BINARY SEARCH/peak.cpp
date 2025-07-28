#include <iostream>
using namespace std;
int peak_(int arr[],int n){
    int lb=0;
    int ub=n-1;
    while(lb<ub){
        int mid=lb+(ub-lb)/2;
        if(arr[mid]<arr[mid+1]){
            lb=mid+1;
        }
        else{
            ub=mid;
        }
    }
    return lb;
}
int main(){
    int arr[4]={1,2,3,1};
    int size=sizeof(arr)/sizeof(arr[0]);
    int peak=peak_(arr,size);
    cout<<peak;
}