#include<iostream>
#include<vector>
using namespace std;
bool solve(int index,int sum,int total_sum,vector<int>&arr){
        if(sum*2==total_sum)return true;
        if(index<0)return false;
        
        int pick=solve(index-1,sum+arr[index],total_sum,arr);
        int not_pick=solve(index-1,sum,total_sum,arr);

        return pick || not_pick;
}
int main(){
    vector<int>arr={1,5,11,5};
    int n=arr.size();
    int sum=0;
    int total_sum=0;
    for(int i=0;i<n;i++){
        total_sum+=arr[i];
    }
    bool ans=solve(n-1,sum,total_sum,arr);
    if(ans){
        cout<<"Divide it"<<endl;
    }
    else{
        cout<<"Not possible"<<endl;
    }
}