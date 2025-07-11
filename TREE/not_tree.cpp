#include<iostream>
#include<vector>
using namespace std;
int main(){
    string s="YashrajSharm";
    vector<string>ans;
    for(int i=0;i<s.length();i+=3){
          string st=s.substr(i,3);
          ans.push_back(st);
    }
    for(auto it: ans){
        cout<<it<<" ";
    }
    
}