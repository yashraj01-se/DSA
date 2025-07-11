#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int arr[8]={1,1,0,1,1,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int counter=0;
    int maxi=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            counter++;
            if(counter>maxi){
               maxi++;
            }
        }
        else{
            counter=0;
        }
         
    }
   cout<<maxi;
   

}