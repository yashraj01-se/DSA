#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>arr={1,4,1,2,14,21,1,3,2,1};
    int n=arr.size()-1;
    
    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }


    for(int i=0;i<=n;i++){
        cout<<arr[i]<<" ";
    }
}