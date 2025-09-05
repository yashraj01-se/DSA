#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int solve(int i,int j,int m,vector<vector<int>>&grid,vector<vector<int>>dp_array){
    if(i==m-1)return grid[m-1][j];

    if(dp_array[i][j]!=-1)return dp_array[i][j];
    int bottom=grid[i][j]+solve(i+1,j,m,grid,dp_array);
    int dai=grid[i][j]+solve(i+1,j+1,m,grid,dp_array);

    return dp_array[i][j]=min(bottom,dai);
}
int main(){
    vector<vector<int>>grid={{2},
                            {3,4},
                            {6,5,7},
                            {4,1,8,3}};
    
    int m=grid.size();  // no of rows...

    vector<vector<int>>dp_array(m);
    for(int i=0;i<m;i++){
        dp_array[i].assign(grid[i].size(),-1);
    }
    int ans=solve(0,0,m,grid,dp_array);
    cout<<ans;
    
}