#include<iostream>
#include<vector>
using namespace std;
int main(){
    int arr[5][5]={{0,0,1,1,1},
                   {0,0,0,0,0},
                   {0,1,1,1,1},
                   {0,0,0,0,0},
                   {0,1,1,1,1}};
    int index=0;
    int max_count=-1;
    for(int i=0;i<5;i++){
        int ones=0;
        for(int j=0;j<5;j++){
            if(arr[i][j]==1){
                ones++;
            }
        }
        if(ones>max_count){
            max_count=ones;
            index=i;
        }
    }
    cout<<index;
}