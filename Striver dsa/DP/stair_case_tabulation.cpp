#include<iostream>
#include<vector>
using namespace std;
int staircase(int n ,vector<int>&dp_array){
    dp_array[0]=1;
    dp_array[1]=1;
    for(int i=2;i<=n;i++){
        dp_array[i]=dp_array[i-1]+dp_array[i-2];
    }
    return dp_array[n];
}
int main(){
    int n=3;
    vector<int>dp_array(n+1,-1);
    int ans=staircase(n,dp_array);
    cout<<ans;
}
