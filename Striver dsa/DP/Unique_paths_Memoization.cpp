#include<iostream>
#include<vector>
using namespace std;
int solve(int i,int j,int m ,int n , vector<vector<int>>dp_array){
    if(i==0 && j==0)return 1;
    if(i<0 || j<0)return 0;

    if(dp_array[i][j]!=0)return dp_array[i][j];
    int left=solve(i,j-1,m,n,dp_array);
    int up=solve(i-1,j,m,n,dp_array);

    return dp_array[i][j]=left+up;
}
int main(){
    int m=3;
    int n=2;
    vector<vector<int>>dp_array(m,vector<int>(n,0));
    int ans=solve(m-1,n-1,m,n,dp_array);                    
    cout<<ans;
}