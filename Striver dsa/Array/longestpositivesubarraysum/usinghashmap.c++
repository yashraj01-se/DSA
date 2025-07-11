#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    int arr[9]={1,2,3,1,1,1,4,2,3};
    int k=3;
    unordered_map<long long,int>prefix_sum;
    long long sum=0;
    int maxlength=0;
    for(int i=0;i<9;i++){
       sum+=arr[i];
       if(sum==k){
        maxlength=max(maxlength,i+1);
       }
       int rem=sum-k;
       if(prefix_sum.find(rem)!=prefix_sum.end()){
        int len=i-prefix_sum[rem];
        maxlength=max(maxlength,len);
       }
       if(prefix_sum.find(sum) == prefix_sum.end()) {
        prefix_sum[sum] = i;
    }
    }
    cout<<maxlength;
}