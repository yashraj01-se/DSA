#include<vector>
#include<iostream>
using namespace std;
int kth(vector<int>& arr1, vector<int> &arr2,int k){
    int n=arr1.size();
    int m=arr2.size();
    if(n>m) return(arr2,arr1,k);
    int low=0;
    int high=min(k,n);
    while (low<=high)
    {
        int mid1=low+(high-low)/2;
        int mid2=k-mid1;
        int l1=(mid1==0)?INT_MIN:arr1[mid1-1];
        int r1=(mid1==n)?INT_MAX:arr1[mid1];
        int l2=(mid2==0)?INT_MIN:arr2[mid2-1];
        int r2=(mid2==m)?INT_MAX:arr2[mid2];
        if(l1<=r2 && l2<=r1){
            return max(l1,l2);
        }
        else if(l1>r2){
            high=mid1-1;
        }
        else{
            low=mid1+1;
        }
    }
    return -1;
    
}
int main(){
   vector<int>arr1={7,12,14,15};
   vector<int>arr2={1,2,3,4,9,11};
   int k=5;
   int ans=kth(arr1,arr2,k);
   cout<<ans;
}