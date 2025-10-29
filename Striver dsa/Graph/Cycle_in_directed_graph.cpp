#include<iostream>
#include<vector>
using namespace std;
bool dfs(int node,vector<int>&vis,vector<int>&pathvis,vector<vector<int>>&adj){
        vis[node]=1;
        pathvis[node]=1;

        for(auto nei:adj[node]){
            //If the Node is not visisted...
            if(!vis[nei]){
                if(dfs(nei,vis,pathvis,adj)){
                        return true;
                }
            }
            //If the Node is visited and in same path
            else if(vis[nei] && pathvis[nei]){
                return true;
            }
        }
        pathvis[node]=0;
        return false;
}
bool isCycle(int V, vector<vector<int>>&edges){
    //Making Adjacency List:
    vector<vector<int>>adj(V);
    for(auto e:edges){
        int u=e[0];
        int v=e[1];
        adj[u].push_back(v);
    }

    vector<int>vis(V,0);
    vector<int>pathvis(V,0);
    
    //For Connected Componenets:
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(dfs(i,vis,pathvis,adj)){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int V=4;
    vector<vector<int>>edges={{0, 1}, {1, 2}, {2, 0}, {2, 3}};
    bool ans=isCycle(V,edges);
    if(ans){
        cout<<"Cycle Detected";
    }
    else{
        cout<<"No Cycle Detedted";
    }
}