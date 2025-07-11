#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int arr[5]={1,2,3,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    // int sum=(n*(n+1))/2;
    // int s=0;
    // for(int i=0;i<n;i++){
    //    s+=arr[i];
    // }
    // int ele=sum-s;
    // cout<<ele;

      vector<int>ans;
    for(int i=1;i<=n;i++){
      ans.push_back(i);
    }
       int ele=0;
    for(int i=1;i<ans.size();i++){
        if(arr[i]!=ans[i]){
        ele=ans[i];
        }
    }

    cout<<ele;

}