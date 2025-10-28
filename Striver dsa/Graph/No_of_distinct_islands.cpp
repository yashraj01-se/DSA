// #include<queue>
// #include<set>
// void bfs(int row,int col,int** arr, vector<pair<int,int>>&shape,vector<vector<int>>&vis,int n, int m){

//     queue<pair<int,int>>q;
//     q.push({row,col});

//     int baserow=row; int basecol=col;

//     int delrow[4]={-1,0,+1,0};
//     int delcol[4]={0,+1,0,-1};

//     while(!q.empty()){
//         int row=q.front().first;
//         int col=q.front().second;
//         q.pop();
//         shape.push_back({row-baserow,col-basecol});

//         for(int i=0;i<4;i++){
//             int nrow=row+delrow[i];
//             int ncol=col+delcol[i];

//             if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && arr[nrow][ncol]==1){
//                 q.push({nrow,ncol});
//                 vis[nrow][ncol]=1;
//             }
//         }
//     }
// }
// int distinctIslands(int** arr, int n, int m)
// {
//     set<vector<pair<int,int>>>ans;
//     vector<vector<int>>vis(n,vector<int>(m,0));

//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(!vis[i][j] && arr[i][j]==1){
//                 vector<pair<int,int>>shape;
//                 bfs(i,j,arr,shape,vis,n,m);
//                 ans.insert(shape);
//             }
//         }
//     }
//     int a=ans.size();
//     return a;
// }