#include<iostream>
#include<vector>
using namespace std;
int frog_jumps(int n,vector<int>&h){
    int prev2=0;
    int prev1=abs(h[1]-h[0]);
    int curr;
    for(int i=2;i<=n;i++){
       int onestep=prev1+abs(h[i]-h[i-1]);
       int twostep=prev2+abs(h[i]-h[i-2]);
       curr=min(onestep,twostep);
       prev2=prev1;
       prev1=curr;            
    }
    return prev1;
}
int main(){
    vector<int>h={30,10,60,10,60,50};
    int n=h.size()-1;
    int ans=frog_jumps(n,h);
    cout<<ans;
}