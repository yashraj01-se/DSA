#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    vector<vector<int>> graph = {{1, 2}, {2, 3}, {3}, {} }; // Directed Acyclic Graph
    int V = graph.size();

    // Step 1: Calculate in-degrees of all vertices
    vector<int>indegree(V,0);
    for(int i=0;i<V;i++){
        for(auto it:graph[i]){
            indegree[it]++;
        }
    }

    vector<int>ans;
    queue<int>q;

    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);

        for(auto nei:graph[node]){
            indegree[nei]--;
            if(indegree[nei]==0){
                q.push(nei);
            }
        }
    }

    int n=ans.size();
    if(n<V){
        cout<<"Cycle detected";
    }
    else{
        cout<<"No Cycle detected";
    }
}