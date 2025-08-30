#include<iostream>
#include<vector>
using namespace std;
int staircase(int n ,vector<int>&dp_array){
    if(n==0 || n==1)return 1;
    if(dp_array[n]!=-1)return dp_array[n];
    return dp_array[n]=staircase(n-1,dp_array)+staircase(n-2,dp_array);
}
int main(){
    int n=3;
    vector<int>dp_array(n+1,-1);
    int ans=staircase(n,dp_array);
    cout<<ans;
}
