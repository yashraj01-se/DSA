#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>
using namespace std;
int solve(int i,int j,int m ,int n, vector<vector<int>>&grid,vector<vector<int>>&dp_array){
        if(i==0 && j==0)return grid[i][j];
        if(i<0 || j<0) return INT_MAX;

        if(dp_array[i][j]!=-1)return dp_array[i][j];
        int left=(j>0)?grid[i][j]+solve(i,j-1,m,n,grid,dp_array):INT_MAX;
        int up=(i>0)?grid[i][j]+solve(i-1,j,m,n,grid,dp_array):INT_MAX;

        return dp_array[i][j]=min(left,up);
}
int main(){
    vector<vector<int>>grid={{5,9,6},
                            {11,5,2},
                            {4,7,1}};
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>>dp_array(m,vector<int>(n,-1));
    int ans=solve(m-1,n-1,m,n,grid,dp_array);
    cout<<ans;
    
}