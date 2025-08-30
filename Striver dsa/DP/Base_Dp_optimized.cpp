#include<iostream>
#include<vector>
using namespace std;
int fibo(int n){
    int prev2=0;
    int prev1=1;
    int curr;
    for(int i=2;i<=n;i++){
        curr=prev2+prev1;
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}
int main(){
    int n;
    cin>>n;
    int ans=fibo(n);
    cout<<ans;
}