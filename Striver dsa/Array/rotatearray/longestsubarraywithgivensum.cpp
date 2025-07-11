#include<iostream>
#include<vector>
using namespace std;
int main(){
    int arr[9]={1,2,3,1,1,1,4,2,3};
    int k=3;
     int maxi=-1;
     
    for(int i=0;i<9;i++){
        int sum=0;
        for(int j=i;j<9;j++){
             sum+=arr[j];
             if(sum==k){
                maxi=max(maxi,j-i+1);
             }
        }
        
    }
cout<<maxi;
}