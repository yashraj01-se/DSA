#include <iostream>
#include <vector>
#include <queue>
using namespace std;
long double gas(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> howmany(n - 1, 0);
    priority_queue<pair<long double,int>>pq;
    for(int i=0;i<n-1;i++){
        pq.push({arr[i+1]-arr[i],i});
    }
    for(int gassstattion=1;gassstattion<=k;gassstattion++){
        auto value=pq.top();
        pq.pop();
        int sectionid=value.second;
        howmany[sectionid]++;
        long double inidiff=arr[sectionid+1]-arr[sectionid];
        long double sectionlenght=inidiff/(howmany[sectionid]+1);
        pq.push({sectionlenght,sectionid});
    }

    return pq.top().first;
    
}

int main()
{
    vector<int> arr = {1, 13, 17, 23};
    int k = 5;
    long double ans=gas(arr, k);
    cout<<ans;
}