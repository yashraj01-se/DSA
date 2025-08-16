#include <iostream>
#include <vector>
#include <queue>
using namespace std;
long double maxi(vector<int>arr){
    long double ans=INT_MIN;
    for(int i=0;i<arr.size()-1;i++){
        if(arr[i+1]-arr[i]>ans){
            ans=arr[i+1]-arr[i];
        }
    }
    return ans;
}
int noofgas(vector<int>arr,long double dist){
    int count=0;
    for(int i=0;i<arr.size()-1;i++){
        long double noinBetween=(arr[i+1]-arr[i])/dist;
        if((arr[i]-arr[i-1])/dist==noinBetween*dist){
            noinBetween--;
        }
        count+=noinBetween;
    }
    return count;
}
long double gas(vector<int>arr,int k){
    long double low=0;
    long double high=maxi(arr);
    long double ans=0;
    while(high-low>1e-6){
        long double mid=low+(high-low)/2;
        long double count=noofgas(arr,mid);
        if(count>k){
            low=mid;
        }
        else{
            high=mid;
        }
    }
    return high;

}
int main()
{
    vector<int> arr = {1, 13, 17, 23};
    int k = 5;
    long double ans=gas(arr, k);
    cout<<ans;
}