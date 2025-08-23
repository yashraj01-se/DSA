#include<iostream>
#include<vector>
using namespace std;
int ONE(int arr[5]){
    int low=0;
    int high=4;
    int first_one=5;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==1){
            first_one=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return 5-first_one;
}
int indexer(int arr[5][5],int& index,int& max_count){
    for(int i=0;i<5;i++){
        int ones_max=ONE(arr[i]);
        if(max_count<ones_max){
            max_count=ones_max;
            index=i;
        }
    }
    return index;
}
int main(){
    int arr[5][5]={{0,0,1,1,1},
                   {0,0,0,0,0},
                   {0,1,1,1,1},
                   {0,0,0,0,0},
                   {0,1,1,1,1}};
    int index=0;
    int max_count=-1;
    int answer=indexer(arr,index,max_count);
    cout<<answer;
}