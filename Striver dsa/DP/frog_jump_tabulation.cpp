#include<iostream>
#include<vector>
using namespace std;
int frog_jumps(int n,vector<int>&h,vector<int>&dp_array){
    dp_array[0]=0;
    dp_array[1]=abs(h[1]-h[0]);
    for(int i=2;i<=n;i++){
        dp_array[i]=min(dp_array[i-1]+abs(h[i]-h[i-1]),dp_array[i-2]+abs(h[i]-h[i-2]));
    }
    return dp_array[n];
}
int main(){
    vector<int>h={30,10,60,10,60,50};
    int n=h.size()-1;
    vector<int>dp_array(n+1,-1);
    int ans=frog_jumps(n,h,dp_array);
    cout<<ans;
}