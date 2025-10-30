//Topological sort using DFS
//Topological sort is possible only in Directed Acyclic Graph(DAG)
//Topological sort is a linear ordering of vertices such that for every directed edge u->v, vertex u comes before v in the ordering.

#include<iostream>
#include<vector>   
#include<stack>
using namespace std;
void dfs(int node,vector<int>&vis,stack<int>&st,vector<vector<int>>&adj){
     vis[node]=1;

     for(auto nei:adj[node]){
        if(!vis[nei]){
            dfs(nei,vis,st,adj);
        }
    }
    st.push(node);
}
vector<int>topologicalsort(int V,stack<int>&st,vector<int>&vis,vector<vector<int>>&graph){
     
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs(i,vis,st,graph);
        }
    }

    vector<int>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    return ans;

}
int main(){
    vector<vector<int>> graph = {{1, 2}, {2, 3}, {3}, {} }; // Directed Acyclic Graph
    int V = graph.size();

    vector<int> vis(V, 0);
    stack<int> st;
    
    vector<int>ans=topologicalsort(V,st,vis,graph);
    for(auto it: ans){
        cout<<it<<" ";
    }
    return 0;   
}