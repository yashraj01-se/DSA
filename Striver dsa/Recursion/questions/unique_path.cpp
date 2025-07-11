#include<vector>
#include<iostream>
using namespace std;
void path(int &count,int m, int n,int row,int col,vector<vector<int>>&vis){
      if(row==m-1 && col==n-1){
        count++;
        return;
      }
      //rightward:
      if(col+1<n && !vis[row][col+1]){
        vis[row][col+1]=1;
        path(count,m,n,row,col+1,vis);
        vis[row][col+1]=0;
      }
      //downward:
      if(row+1<m &&  !vis[row+1][col]){
        vis[row+1][col]=1;
        path(count,m,n,row+1,col,vis);
        vis[row+1][col]=0;
      }
}
int main(){
    int m=23;
    int n=12;
    int count=0;
    vector<vector<int>>vis(m,vector<int>(n,0));
    vis[0][0]=1;
    path(count,m,n,0,0,vis);
    cout<<count;
}