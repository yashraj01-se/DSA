#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int>sche(int v,vector<vector<int>>&prere){
    //Step 1:Make Graph:
    vector<vector<int>>graph(v);
    for(auto it:prere){
        graph[it[1]].push_back(it[0]);
    }

    //step 2:Indegree array:
    vector<int>indegree(v,0);
    for(int i=0;i<v;i++){
        for(auto it:graph[i]){
            indegree[it]++;
        }
    }

    //step 3: Intialize the queue:
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

        for(auto it:graph[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    return ans;
}
int main(){
    vector<vector<int>> graph = {{1, 0}, {2, 1}}; // Directed Graph with a cycle
    int V = 3;

    vector<int>ans=sche(V,graph);

    for(auto it:ans){
        cout<<it<<" ";
    }

    //If there will be cycle dependency in the given prerequisites then the vector returned by the topo sort ,it size will be less than V 
    //From that we can understand that the arragement can be made or not. 

}
