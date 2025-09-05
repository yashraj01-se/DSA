#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int solve(int i,int j,int m,int n,vector<vector<int>>&grid){
    if(i==m-1)return grid[m-1][j];

    int bottom=grid[i][j]+solve(i+1,j,m,n,grid);
    int dai=grid[i][j]+solve(i+1,j+1,m,n,grid);

    return min(bottom,dai);
}
int main(){
    vector<vector<int>>grid={{2},
                            {3,4},
                            {6,5,7},
                            {4,1,8,3}};
    
    int m=grid.size();
    int n=grid[0].size();

    int ans=solve(0,0,m,n,grid);
    cout<<ans;
    
}