#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int main(){
   int arr[8]={1,1,1,2,3,2,2,1};
   int n=sizeof(arr)/sizeof(arr[0]);
   unordered_map<int,int>mpp;
   vector<int>res;
   int min=(n/3)+1;
   for(auto it:arr){
       mpp[it]++;
       if(mpp[it]==min){
          res.push_back(it);
       }
   }
 

   for(auto it: res){
    cout<<it<<" ";
   }
}