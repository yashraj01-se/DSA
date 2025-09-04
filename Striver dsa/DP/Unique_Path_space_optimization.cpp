#include<iostream>
#include<vector>
using namespace std;
int solve(int i,int j,int m ,int n , vector<int>&dp_array){
    for(int i=0;i<m;i++){
        vector<int>temp(n,0);
        for(int j=0;j<n;j++){
            if(i==0 && j==0)temp[j]=1;
            else{
                temp[j]=dp_array[j]+(j > 0 ? temp[j-1] : 0);
            }
        }
        dp_array=temp;
    }
    return dp_array[n-1];
}
int main(){
    int m=3;
    int n=2;
    vector<int>dp_array(n,0);
    int ans=solve(m,n,m,n,dp_array);                    
    cout<<ans;
}