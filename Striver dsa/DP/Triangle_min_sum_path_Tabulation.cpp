#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int solve(int i,int j,int m,vector<vector<int>>&grid,vector<vector<int>>dp_array){
    for(int j=0;j<grid[m-1].size();j++){
        dp_array[m-1][j]=grid[m-1][j];
    }

   int up=0;
   int dai=0;

   for(int i=m-2;i>=0;i--){
    for(int j=0;j<=i;j++){
        up=grid[i][j]+dp_array[i+1][j];
        dai=grid[i][j]+dp_array[i+1][j+1];
        dp_array[i][j]=min(up,dai);
    }
   }

    return dp_array[0][0];
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