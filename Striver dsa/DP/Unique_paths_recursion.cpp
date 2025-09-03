#include<iostream>
#include<vector>
using namespace std;
int solve(int i,int j,int m ,int n){
    if(i==0 && j==0)return 1;
    if(i<0 || j<0)return 0;

    int left=solve(i,j-1,m,n);
    int up=solve(i-1,j,m,n);

    return left+up;
}
int main(){
    int m=3;
    int n=2;
    int ans=solve(m-1,n-1,m,n);                       // Will not pass all test case...
    cout<<ans;
}