#include<iostream>
#include<vector>
using namespace std;
void dfs(int row,int col,int inicolor,int newcolor,int n,int m,vector<vector<int>>&image,vector<vector<int>>&ans,int delrow[],int delcol[]){
    ans[row][col]=newcolor;

    //Checking Neighbour:
    for(int i=0;i<4;i++){
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];

        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol]!=newcolor && image[nrow][ncol]==inicolor){
           dfs(nrow,ncol,inicolor,newcolor,n,m,image,ans,delrow,delcol);
        }
    }
}
vector<vector<int>>floodFill(vector<vector<int>>&image,int sr,int sc,int newColor,int n,int m){
      int inicolor=image[sr][sc];
      vector<vector<int>>ans=image;

      int delrow[4]={-1,0,+1,0};
      int delcol[4]={0,+1,0,-1};

      dfs(sr,sc,inicolor,newColor,n,m,image,ans,delrow,delcol);
      return ans;
}
int main(){
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    int sr = 1, sc = 1, newColor = 2;
    int n = image.size();
    int m = image[0].size();
    vector<vector<int>>ans=floodFill(image, sr, sc, newColor,n,m);
    cout<<"Flood Filled Image: "<<endl;
    for(auto row: ans){
        for(auto col: row){
            cout<<col<<" ";
        }
        cout<<endl;
    }
}