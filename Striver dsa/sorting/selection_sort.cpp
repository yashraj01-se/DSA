#include<iostream>
#include<vector>
using namespace std;
int mini(vector<int>&arr,int i,int j){
    int m=arr[i];
    int index=i;
    for(int k=i;k<=j;k++){
        if(m>arr[k]){
            m=arr[k];
            index=k;
        }
       
    }
    return index;
}
int main(){
    vector<int>arr={1,4,1,2,14,21,1,3,2,1};
    int n=arr.size();
    
    for(int i=0;i<=n;i++){
        int min=mini(arr,i,n-1);
        swap(arr[min],arr[i]);
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}