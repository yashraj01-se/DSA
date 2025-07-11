#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int main(){
       vector<int>arr={1,1,1};
       int k=2;
       unordered_map<int,int>mpp;
       mpp[0]=1; //remeber important;
       int prefix_sum=0;
       int count=0;
       for(int i=0;i<arr.size();i++){
           prefix_sum+=arr[i];
           int left_over=prefix_sum-k;
           count+=mpp[left_over];
           mpp[prefix_sum]+=1;
       }
       cout<<count;
}