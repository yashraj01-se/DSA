#include <iostream>
#include <vector>
using namespace std;
   void markrow(int i,vector<vector<int>>& arr,int col){
           for(int j=0;j<col;j++){
            if(arr[i][j]!=0){
                arr[i][j]=-1;
            }
           }
   }
   void markcol(int j,vector<vector<int>>& arr,int row){
           for(int i=0;i<row;i++){
            if(arr[i][j]!=0){
                arr[i][j]=-1;
            }
           }
   }

int main() {
    // Correct way to initialize a 2D vector
    vector<vector<int>> arr = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int row=arr.size();
    int col=arr[0].size();
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]==0){
                markrow(i,arr,col);
                markcol(j,arr,row);
            }
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]==-1){
                arr[i][j]=0;
            }
        }
    }
      for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";  // Add space between elements
        }
        cout << endl;  // Add new line after each row
    }
    

}