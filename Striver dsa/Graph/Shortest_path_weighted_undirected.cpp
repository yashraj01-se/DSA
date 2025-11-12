#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int main(){
    int n=5;
    int m=6;
    vector<vector<int>> edges={{1,2,2},{1,4,1},{2,4,3},{2,5,10},{4,5,2},{3,5,6}};
    // Making Adjacency List
    vector<vector<pair<int,int>>> adj(n+1);
    for(auto &e:edges){
        int u=e[0],v=e[1],wt=e[2];
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    // Initialization:
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,1});
    vector<int> dis(n+1,INT_MAX);
    dis[1]=0;
    vector<int> parent(n+1);
    for(int i=1;i<=n;i++) parent[i]=i;

    // Dijkstra's Algorithm
    while(!pq.empty()){
        auto it=pq.top();
        int node=it.second;
        int wt=it.first;
        pq.pop();

        for(auto it:adj[node]){
            int Adjnode=it.first;
            int adjW=it.second;

            if(dis[node]+adjW<dis[Adjnode]){
                dis[Adjnode]=dis[node]+adjW;
                pq.push({dis[Adjnode],Adjnode});
                parent[Adjnode]=node;
            }
        }
    }
    // Print shortest distance from source
    int dest=5;
    if(dis[dest]==INT_MAX){
        cout<<"-1"<<endl;
    }
    else{
        cout<<"Shortest distance from source to destination is: "<<dis[dest]<<endl;
        // Print path
        vector<int> path;
        int curr=dest;
        while(parent[curr]!=curr){
            path.push_back(curr);
            curr=parent[curr];
        }
        path.push_back(1); // source node
        reverse(path.begin(),path.end());
        cout<<"Path is: ";
        for(int i=0;i<=path.size();i++){
            cout<<path[i]<<" ";
        }   
        cout<<endl;
    }

}