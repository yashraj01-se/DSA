#include<iostream>
#include<vector>
using namespace std;
int partitio(vector<int>&arr, int low, int high){
      int pivot=arr[low];
      int i=low;
      int j=high;

      while(i<j){
         while(arr[i]<=pivot && i<=high){
            i++;
         }
         while(arr[j]>pivot && j>low){
            j--;
         }
         if(i<j){
            swap(arr[i],arr[j]);
         }
      }
      swap(arr[low],arr[j]);
      return j;
}
void quicksort(vector<int>&arr,int low, int high){
    if(low<high){
      int partition=partitio(arr,low,high);
      quicksort(arr,low,partition-1);
      quicksort(arr,partition+1,high);
    }
}
int main(){
    vector<int>arr={1,4,1,2,14,21,1,3,2,1};
    int n=arr.size()-1;
    quicksort(arr,0,n);
    for(int i=0;i<=n;i++){
        cout<<arr[i]<<" ";
    }
}