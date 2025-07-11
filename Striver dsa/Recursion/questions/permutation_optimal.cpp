#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void sub(int index,vector<int>&arr,vector<vector<int>>&res,vector<int>&ans){
    int n=arr.size();
    if(index==n){
        res.push_back(arr);
        return;
    }
        for(int i=index;i<n;i++){
            swap(arr[index],arr[i]); // to chose it..
            sub(index+1,arr,res,ans);
            swap(arr[index],arr[i]); // to unchose it...
        }
    
}
int main(){
    vector<int>arr={1,2,3};
    vector<int>ans;
    vector<vector<int>>res;
    sub(0,arr,res,ans);

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