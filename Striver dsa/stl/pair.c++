#include<iostream>
using namespace std;
int main(){
   pair<char,int>p1={'y',1};   // storing  2 value in same variable...
   pair<char,int>p2={'a',2};
   p1.swap(p2);
   //Scout<<p1.first<<" "<<p2.first ;    //swapping pair value...
   pair<int,pair<int,int>>o={1,{3,4}};
   pair<pair<int,int>,pair<int,int>>l={{1,2},{3,4}};
   pair<int,pair<pair<int,int>,pair<int,int>>>r={1,{{2,3},{4,5}}};
   //cout<<r.second.first.second;
   pair<char,int>arr[4]={{'y',1},{'a',2},{'s',3},{'h',4}};
   for (int i = 0; i <4; i++)
   {
    cout<< arr[i].first <<" "<<arr[i].second<<endl;
   }
   
}