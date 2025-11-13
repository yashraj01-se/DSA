#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int minimum_effort_path(vector<vector<int>>&heights,int n, int m){
    // Initialization:
    priority_queue<pair<int,pair<int,int>>,
    vector<pair<int,pair<int,int>>>,
    greater<pair<int,pair<int,int>>>>pq;
    pq.push({0,{0,0}});
    vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
    dis[0][0]=0;

    //direction:
    int delrow[4]={-1,0,+1,0};
    int delcol[4]={0,+1,0,-1};

    // Dijkstra algo:
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int diff=it.first;
        int row=it.second.first;
        int col=it.second.second;

        if(row==n-1 && col==m-1)return diff;

        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                int newEffort=max(abs(heights[nrow][ncol]-heights[row][col]),diff);
                if(newEffort<dis[nrow][ncol]){
                    dis[nrow][ncol]=newEffort;
                    pq.push({newEffort,{nrow,ncol}});
                }
            }
        }
    }
    return 0;
}
int main(){
    vector<vector<int>> heights={{1,2,2},{3,8,2},{5,3,5}};
    int n=heights.size();
    int m=heights[0].size();
    int ans=minimum_effort_path(heights,n,m);
    cout<<ans;
}