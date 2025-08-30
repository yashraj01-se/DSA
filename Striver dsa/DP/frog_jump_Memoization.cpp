#include<iostream>
#include<vector>
using namespace std;
int frog_jumps(int n,vector<int>&h,vector<int>&dp_array){
    if(n==0)return 0;
    if(n==1)return abs(h[1]-h[0]);
    if(dp_array[n]!=-1)return dp_array[n];
    return min(frog_jumps(n-1,h,dp_array)+abs(h[n]-h[n-1]),frog_jumps(n-2,h,dp_array)+abs(h[n]-h[n-2]));
}
int main(){
    vector<int>h={30,10,60,10,60,50};
    int n=h.size()-1;
    vector<int>dp_array(n+1,-1);
    int ans=frog_jumps(n,h,dp_array);
    cout<<ans;
}