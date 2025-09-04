#include<iostream>
#include<vector>
using namespace std;
int solve(int i,int j,int m ,int n ,vector<vector<int>>& grid,vector<vector<int>>&dp_array){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)dp_array[i][j]=0;
                else if(i==0 && j==0)dp_array[i][j]=1;
                else{
                    int left=(j>0)?dp_array[i][j-1]:0;
                    int uper=(i>0)?dp_array[i-1][j]:0;
                    dp_array[i][j]=left+uper;
                }
            }
        }

        return dp_array[m-1][n-1];
}    
int main(){
    vector<vector<int>>grid={{0,0,0},
                            {0,1,0},
                            {0,0,0}};
    int m=grid.size();
    int n=grid[0].size();

    vector<vector<int>>dp_array(m,vector<int>(n,-1));
    int ans=solve(0,0,m,n,grid,dp_array);
    cout<<ans;
}