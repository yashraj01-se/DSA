#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int solve(int i,int j,int m ,int n, vector<vector<int>>&grid){
        if(i==0 && j==0)return grid[i][j];
        if(i<0 || j<0) return INT_MAX;

        int left=(j>0)?grid[i][j]+solve(i,j-1,m,n,grid):INT_MAX;
        int up=(i>0)?grid[i][j]+solve(i-1,j,m,n,grid):INT_MAX;

        return min(left,up);
}
int main(){
    vector<vector<int>>grid={{5,9,6},
                            {11,5,2},
                            {4,7,1}};
    int m=grid.size();
    int n=grid[0].size();
                                          ////////This will not work and will explode in large grids.....
    int ans=solve(m-1,n-1,m,n,grid);
    cout<<ans;
    
}