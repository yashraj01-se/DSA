#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
void path(vector<vector<int>>&maze,vector<string>&ans,string s,int row,int col,vector<vector<int>>&vis,int n){
    if(row==n-1 && col==n-1){
        ans.push_back(s);
        return;
    }
    //rightward-
    if(col+1<n && !vis[row][col+1] &&maze[row][col+1]==1){
        vis[row][col+1]=1;
        path(maze,ans,s+'R',row,col+1,vis,n);
        vis[row][col+1]=0;
    }
    //downward:
    if(row+1<n && !vis[row+1][col] &&maze[row+1][col]==1){
        vis[row+1][col]=1;
        path(maze,ans,s+'D',row+1,col,vis,n);
        vis[row+1][col]=0;
    }
    //leftward:
    if(col-1>=0 && !vis[row][col-1] &&maze[row][col-1]==1){
        vis[row][col-1]=1;
        path(maze,ans,s+'R',row,col-1,vis,n);
        vis[row][col-1]=0;
    }
    //upward
    if(row-1>=0 && !vis[row-1][col] &&maze[row-1][col]==1){
        vis[row-1][col]=1;
        path(maze,ans,s+'R',row-1,col,vis,n);
        vis[row-1][col]=0;
    }

}
int main(){
   vector<vector<int>>maze={
                    {1,0,0,0},
                    {1,1,0,1},
                    {1,1,0,0},
                    {0,1,1,1}
};
int n=maze.size();
vector<string>ans;
vector<vector<int>>vis(n,vector<int>(n,0));
if(maze[0][0]==1){
    vis[0][0]=1;
    path(maze,ans,"",0,0,vis,n);
}
sort(ans.begin(),ans.end());
for(auto it:ans){
    for(auto i:it){
        cout<<i<<" ";
    }cout<<endl;
}
}