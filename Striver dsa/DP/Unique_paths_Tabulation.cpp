#include<iostream>
#include<vector>
using namespace std;
int solve(int i,int j,int m ,int n , vector<vector<int>>&dp_array){
    for(int i=0;i<m;i++)dp_array[i][0]=1; //one way to move from 0th row
    for(int j=0;j<n;j++)dp_array[0][j]=1; // one way to move from 0th column

    int left=0;
    int up=0;

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            left=dp_array[i][j-1];
            up=dp_array[i-1][j]; 
            dp_array[i][j]=left+up; // Filling dp_array
        }
    }
   

    return dp_array[m-1][n-1]; // returning accumulated value
}
int main(){
    int m=3;
    int n=2;
    vector<vector<int>>dp_array(m,vector<int>(n,0));
    int ans=solve(m,n,m,n,dp_array);                    
    cout<<ans;
}