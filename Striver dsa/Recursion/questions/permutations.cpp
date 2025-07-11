#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void sub(int index,vector<int>&arr,vector<vector<int>>&res,vector<bool>&map,vector<int>ans){
    int n=arr.size();
    if(index==n){
        res.push_back(ans);
        return;
    }
        for(int i=0;i<n;i++){
            if(!map[i]){
               ans.push_back(arr[i]);
               map[i]=true;
               sub(index+1,arr,res,map,ans);
               map[i]=false;
               ans.pop_back();
            }
        }
    
}
int main(){
    vector<bool>map(3);
    vector<int>arr={1,2,3};
    vector<int>ans;
    vector<vector<int>>res;
    sub(0,arr,res,map,ans);

     for (auto it : res)
    {
        cout << "[";
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << "]\n";
    }
    return 0;
}