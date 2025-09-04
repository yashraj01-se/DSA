#include<iostream>
#include<vector>
using namespace std;
int solve(int i,int j,int m ,int n ,vector<vector<int>>& grid){
        if(i==0 && j==0) return grid[0][0]==1?0:1;
        if(grid[i][j]==1) return 0;

        int left=(j>0)?solve(i,j-1,m,n,grid):0;
        int up=(i>0)?solve(i-1,j,m,n,grid):0;

        return left+up;
}    
int main(){
    vector<vector<int>>grid={{0,0,0},
                            {0,1,0},
                            {0,0,0}};
    int m=grid.size();
    int n=grid[0].size();

    int ans=solve(m-1,n-1,m,n,grid);
    cout<<ans;
}