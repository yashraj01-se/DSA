
//Logic For all 8 direction...

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void bfs(int row,int col,vector<vector<char>>&grid,vector<vector<int>>&vis){
    queue<pair<int,int>>q;
    q.push({row,col});
    vis[row][col]=1;
    int n=grid.size();
    int m=grid[0].size();

    while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        q.pop();

        //Checking Neighbours:
        for(int delrow=-1;delrow<=1;delrow++){
            for(int delcol=-1;delcol<=1;delcol++){
                int nrow=row+delrow;
                int ncol=col+delcol;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='L' && !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
}
int noofislands(vector<vector<char>>&grid){
    int n=grid.size();
    int m=grid[0].size();
    int count=0;

    vector<vector<int>>vis(n,vector<int>(m,0));

    for(int row=0;row<n;row++){
        for(int col=0;col<m;col++){
            if(!vis[row][col] && grid[row][col]=='L'){
                count++;
                bfs(row,col,grid,vis);
            }
        }
    }
    return count;
}
int main(){
    vector<vector<char>> grid = {
        {'L', 'L', 'W', 'W', 'W'},
        {'L', 'L', 'W', 'W', 'W'},
        {'W', 'W', 'L', 'W', 'W'},
        {'W', 'W', 'W', 'L', 'L'}
    };
    int count=noofislands(grid);
    cout<<"Number of islands: "<<count<<endl;
    return 0;   
}