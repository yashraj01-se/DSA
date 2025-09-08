#include<iostream>
#include<vector>
using namespace std;  
bool solve(int index,int target,vector<int>&arr){
   
    vector<bool>prev(target+1,0),curr(target+1,0);

    prev[0]=curr[0]=true;
   
    bool not_pick=false;
    bool pick=false;

    for(int i=1;i<arr.size();i++){
        for(int j=1;j<=target;j++){
            not_pick=prev[j];
            if(j>=arr[i]){
             pick=prev[j-arr[i]];
            }
            
            curr[j]=not_pick || pick;
        }
        prev=curr;
    }

    return prev[target];
}  
int main(){
    vector<int> arr={1,2,3,4};
    int k=4;
    int n=arr.size();
    bool ans=solve(0,k,arr);
    if(ans){
        cout<<"Found";
    }
    else{
        cout<<"Not Found";
    }
}