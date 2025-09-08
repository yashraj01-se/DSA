#include<iostream>
#include<vector>
using namespace std;  
bool solve(int index,int target,vector<int>&arr){
    if(target==0)return true;
    if(index==0) return true?arr[0]==target:false;

    bool not_pick=solve(index-1,target,arr);
    bool pick=false;
    if(target>=arr[index]){
        pick=solve(index-1,target-arr[index],arr);
    }

    return not_pick || pick;
}  
int main(){
    vector<int> arr={1,2,3,4};
    int k=4;
    int n=arr.size();

    bool ans=solve(n-1,k,arr);
    if(ans){
        cout<<"Found";
    }
    else{
        cout<<"Not Found";
    }
}