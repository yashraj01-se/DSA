#include<iostream>
#include<vector>
using namespace std;  
int solve(int i,int j1,int j2,int m,int n,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp_array){

    //Base Cases:
    if((j1<0 || j1>=n) || (j2<0 || j2>=n)){   //out of bound
      return INT_MIN;
    }
    if(i==m-1){
        if(j1==j2)return grid[i][j1];
        else{
            return grid[i][j1]+grid[i][j2];   //destination
        }
    }

    int val;
    int maxi=INT_MIN;
    if(dp_array[i][j1][j2]!=-1)return dp_array[i][j1][j2];
    for(int dj1=-1;dj1<=1;dj1++){
        for(int dj2=-1;dj2<=1;dj2++){
            val=(j1==j2)?grid[i][j1]:grid[i][j1]+grid[i][j2];
            val+=solve(i+1,j1+dj1,j2+dj2,m,n,grid,dp_array);
            maxi=max(maxi,val);
        }
    }
    return dp_array[i][j1][j2]=maxi;
}      
int main(){
    vector<vector<int>>grid={{2,3,1,2},
                            {3,4,2,2},
                            {5,6,3,5}};

    int m=grid.size();  // no of rows...
    int n=grid[0].size(); // no of cols...

    int ans=0;
    vector<vector<vector<int>>>dp_array(m,vector<vector<int>>(n,vector<int>(n,-1)));

    ans=solve(0,0,n-1,m,n,grid,dp_array);//(i,j1,j2,grid);
    cout<<ans;

}