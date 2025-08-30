#include<iostream>
#include<vector>
using namespace std;
int fibo(int n, vector<int>&dp_array){
   if(n<=1){
    return n;  //Base case
   }
   if(dp_array[n]!=-1)return dp_array[n];            //Memoization
   return dp_array[n]=fibo(n-1,dp_array)+fibo(n-2,dp_array);   //Recursion
}
int main(){
    int n;
    cin>>n;
    vector<int>dp_array(n+1,-1);
    int ans=fibo(n,dp_array);
    cout<<ans;
}