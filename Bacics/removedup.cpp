#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
int main(){
    int arr[5]={1,2,1,3,1}; // output should be 1 , 2 , 3...
    unordered_set<int>sst;
    int n=sizeof(arr)/sizeof(arr[0]);
    //best approach-
    for(int i=0;i<n;i++){
        if(sst.find(arr[i])==sst.end()){
              sst.insert(arr[i]);
        }
    }

    for(auto i:sst){
        cout<<i;
    }

     

}