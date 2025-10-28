#include<iostream>
#include<queue>
#include<vector>
using namespace std;

bool isdetect(int src,vector<vector<int>>&adj,vector<int>&vis){
    vis[src]=1;
    queue<pair<int,int>>q;
    q.push({src,-1});

    //BFS:
    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();

        for(auto adjnode:adj[node]){
            if(!vis[adjnode]){
                vis[adjnode]=1;
                q.push({adjnode,node});
            }
            else if(parent!=adjnode){
                return true;
            }
        }
    }
    return false;
}

bool iscycle(int V, vector<vector<int>>&adj){
    vector<int>vis(V,0);

    //For Connected Components:
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(isdetect(i,adj,vis)==true){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int V=4, E=4;
    int edg[4][4]={{0, 1}, {0, 2}, {1, 2},{2, 3}};

    //Making Adjacency list:
    vector<vector<int>>adj(V);
    for(auto&e:edg){
        int u=e[0],v=e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool ans=iscycle(V,adj);
    if(ans){
        cout<<"Cycle is detected";
    }
    else{
        cout<<"No cycle id detected";
    }
}
