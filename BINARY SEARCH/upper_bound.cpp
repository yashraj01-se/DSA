#include<iostream>
using namespace std;
int upper_b(int arr[],int n,int k){
      int lb=0;
      int ub=n-1;
      int ans=n;
      while(lb<=ub){
        int mid=lb+(ub-lb)/2;
        if(arr[mid]>k){
            ans=mid;
            ub=mid-1;
        }
        else{
          lb=mid+1;
        }
      }
      return ans;
}
int main(){
    int arr[10]={2,3,6,7,8,8,11,11,11,12};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=8;
    int u_b=upper_b(arr,n,k);
    cout<<u_b;     // arr[i]>target; // smallest
}