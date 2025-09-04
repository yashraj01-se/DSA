#include<iostream>
#include<vector>
using namespace std;
int solve(int i,int j,int m ,int n ,vector<vector<int>>& grid,vector<int>&prev){
        for(int i=0;i<m;i++){
            vector<int>curr(n,0);
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)curr[j]=0;
                else if(i==0 && j==0)curr[j]=1;
                else{
                    curr[j]=prev[j]+(j>0?curr[j-1]:0);
                }
            }
            prev=curr;
        }

        return prev[n-1];
}    
int main(){
    vector<vector<int>>grid={{0,0,0},
                            {0,1,0},
                            {0,0,0}};
    int m=grid.size();
    int n=grid[0].size();

    vector<int>prev(n,0);
    int ans=solve(0,0,m,n,grid,prev);
    cout<<ans;
}