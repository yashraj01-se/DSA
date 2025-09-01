#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int Ninja_max(int days,int ac,vector<vector<int>> &points){
   if(days==0){
    int maxi=0;
    for(int i=0;i<=2;i++){
        if(i!=ac){
          maxi=max(maxi,points[0][i]);
        }
    }
    return maxi;
   }

   int maxi=0;
   for(int i=0;i<=ac;i++){
    if(i!=ac){
        int point=points[days][i]+Ninja_max(days-1,i,points);
        maxi=max(maxi,point);
    }
   }
    return maxi;
}
int main(){
    vector<vector<int>> points = {{10,40,70},{20,50,80},{30,60,90}};
    int n=points.size();
    int ans=Ninja_max(n-1,3,points);
    cout<<ans;
}