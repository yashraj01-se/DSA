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

    //Step 2:Initailize the queue
    queue<int>q;
    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    //step 3:Make the ans array:

    vector<int>ans;
    while (!q.empty())
    {
        int node=q.front();
        q.pop();
        ans.push_back(node);

        for(auto it:graph[node]){
            indegree[it]--;
            if(indegree[it]==0)q.push(it);
        }
    }

    for(auto it:ans){
        cout<<it<<" ";
    }

    return 0;
    
}