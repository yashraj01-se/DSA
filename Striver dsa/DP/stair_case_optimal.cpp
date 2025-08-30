#include<iostream>
#include<vector>
using namespace std;
int staircase(int n){
   int prev1=1;
   int prev2=1;
   int curr;
   for(int i=2;i<=n;i++){
       curr=prev2+prev1;
       prev2=prev1;
       prev1=curr;
   }
   return prev1;
}
int main(){
    int n=3;
    int ans=staircase(n);
    cout<<ans;
}
