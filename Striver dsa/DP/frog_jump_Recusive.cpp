#include<iostream>
#include<vector>
using namespace std;
int frog_jumps(int n,vector<int>&h){
    if(n==0)return 0;
    if(n==1)return abs(h[1]-h[0]);
    int left=frog_jumps(n-1,h)+abs(h[n]-h[n-1]);
    int right=frog_jumps(n-2,h)+abs(h[n]-h[n-2]);
    return min(left,right);
}
int main(){
    vector<int>h={30,10,60,10,60,50};
    int n=h.size()-1;
    int ans=frog_jumps(n,h);
    cout<<ans;
}