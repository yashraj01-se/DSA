#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int Ninja_max(int days,int last,vector<vector<int>>&points,vector<vector<int>>&dp_array){
    if(days==0){
        int maxi=0;
        for(int i=0;i<=2;i++){
            if(i!=last){
            maxi=max(maxi,points[0][i]);
            }
        }
        return maxi;
    }
    
    if(dp_array[days][last]!=-1)return dp_array[days][last];
    int maxi=0;
    for(int i=0;i<=2;i++){
        int point=points[days][i]+Ninja_max(days-1,i,points,dp_array);
        maxi=max(maxi,point);
    }
    return dp_array[days][last]=maxi;
}
int main(){
    vector<vector<int>> points = {{10,40,70},{20,50,80},{30,60,90}};
    int n=points.size();
    vector<vector<int>>dp_array(n,vector<int>(n+1,-1));
    int ans=Ninja_max(n-1,3,points,dp_array);
    cout<<ans;
}