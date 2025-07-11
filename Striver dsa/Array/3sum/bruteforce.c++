#include <iostream>
#include <set>
#include <vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int>nums={-1,0,1,2,-1,-4};
    vector<vector<int>>ans;
        set<vector<int>>seen;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]+nums[j]+nums[k]==0 ){
                      vector<int>triplet={nums[i],nums[j],nums[k]};
                      seen.insert(triplet);
                    }
                }
            }
        }
        for(auto& it:seen){
            ans.push_back(it);
        }
        for(auto& it:ans){
            cout<<"[";
            for(int i:it){
                cout<<i<<" ";
            }cout<<"]";
        }
    }
