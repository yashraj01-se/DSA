#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>&arr,int low, int mid, int high){
    int left=low;
    int right=mid+1;
    vector<int>temp;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
           temp.push_back(arr[left]);
           left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
         temp.push_back(arr[left]);
           left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}
void mergesort(vector<int>&arr,int low, int high){
    if(low==high){
        return;
    }
    int mid=low+(high-low)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);

}
int main(){
    vector<int>arr={1,4,1,2,14,21,1,3,2,1};
    int n=arr.size()-1;
    mergesort(arr,0,n);
    for(int i=0;i<=n;i++){
        cout<<arr[i]<<" ";
    }
}