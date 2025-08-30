#include<iostream>
#include<vector>
using namespace std;
int staircase(int n ,vector<int>&dparray){
    if(n==0||n==1)return 1;
    if(dparray[n]!=-1)return dparray[n];
    return dparray[n]=staircase(n-1,dparray)+staircase(n-2,dparray);
}
int main(){
    int n =3;
    vector<int>dparray(n+1,-1);
    int ans=staircase(n,dparray);
    cout<<ans;
}
