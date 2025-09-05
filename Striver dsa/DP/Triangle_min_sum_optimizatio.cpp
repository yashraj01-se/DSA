#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int solve(int i,int j,int m,vector<vector<int>>&grid,vector<int>&dp_array){
    for(int j=0;j<grid[m-1].size();j++){
        dp_array[j]=grid[m-1][j];
    }

   int up=0;
   int dai=0;

   for(int i=m-2;i>=0;i--){
    vector<int>curr(i+1);
    for(int j=0;j<=i;j++){
        up=grid[i][j]+dp_array[j];
        dai=grid[i][j]+dp_array[j+1];
        curr[j]=min(up,dai);
    }
    dp_array=curr;
   }

    return dp_array[0];
}
int main(){
    vector<vector<int>>grid={{2},
                            {3,4},
                            {6,5,7},
                            {4,1,8,3}};
    
    int m=grid.size();  // no of rows...

    vector<int>dp_array(grid[m-1].size(),-1);
    int ans=solve(0,0,m,grid,dp_array);
    cout<<ans;
    
}