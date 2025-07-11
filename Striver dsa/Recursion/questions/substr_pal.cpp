#include<vector>
#include<iostream>
using namespace std;
bool ispal(string&s,int start, int end){
    while (start<end)
    {
        if(s[start++]!=s[end--])return false;

    }
    return true;
    
}
void solve(int index,string &s,vector<vector<string>>&res,vector<string>ans){
    int n=s.length();
    if(n==index){
        res.push_back(ans);
        return;
    }
    for(int i=index;i<s.length();i++){
        if(ispal(s,index,i)){
            ans.push_back(s.substr(index,i-index+1));
            solve(i+1,s,res,ans);
            ans.pop_back();
        }
    }
}
int main(){
    string s="aabb";
    vector<vector<string>>res;
    vector<string>ans;
    solve(0,s,res,ans);
    for(auto it:res){
        for(auto i:it){
            cout<<i<<" ";
        }cout<<endl;
    }
}