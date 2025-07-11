#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    vector<vector<int>>arr={{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>>ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++){
        int first=arr[i][0];
        int second=arr[i][1];
        if(!ans.empty() && second<=ans.back()[1]){
            continue;
        }
        for(int j=i+1;j<arr.size();j++){
            if(arr[j][0]<=second){
                second=max(second,arr[j][1]);
            }
            else{
                break;
            }
        }
        ans.push_back({first,second});
    }
    for(auto it:ans){
        cout<<"["<<it[0]<<","<<it[1]<<"]";
    }
}