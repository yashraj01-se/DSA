// A safe node is one whose every node path ends at the terminal node.
// A terminal node is node which has zero outdegree.

/// Simple just remember that All the nodes that are the part of the cycle and nodes that lead to the cycle acn never be the safe nodes...
// apart from that all are safe nodes...

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int>topo_safe(int v,vector<vector<int>>graph){
    //step 1:Making reverese adjacemcy list:
    vector<vector<int>>revadj(v);
    for(int i=0;i<v;i++){
        for(auto it:graph[i]){
            revadj[it].push_back(i);
        }
    }
    
    //Step 2:Making indegree array:
    vector<int>indegree(v,0);
    for(int i=0;i<v;i++){
        for(auto it:revadj[i]){
            indegree[it]++;
        }
    }

    //Step 3:Initialize the Queue:
    queue<int>q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    //Step 4:Topo sort:
    vector<int>ans;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);

        for(auto it:revadj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }

    return ans;

}
int main()
{
    vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {},{}}; // Directed Graph
    int V = graph.size();
    vector<int> ans = topo_safe(V, graph);

   for(int i:ans){
    cout<<i<<" ";
   }
}