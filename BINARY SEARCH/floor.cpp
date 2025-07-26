#include<iostream>
using namespace std;
int floor(int arr[],int n,int k){
    int lb=0;
      int ub=n-1;
      int ans=-1;
      while(lb<=ub){
        int mid=lb+(ub-lb)/2;
        if(arr[mid]>k){
            ub=mid-1;
        }
        else{
            ans=mid;
            lb=mid+1;
        }
      }
      return ans;
}
int main(){
    int arr[10]={2,3,6,7,8,8,11,11,11,12};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=5;
    int f=floor(arr,n,k);
    cout<<f;    //largest of the array<=x... 
}