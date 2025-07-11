#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
int main(){
    vector<int>v={1,2,3,4,4,5};
    v.push_back(35);
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    v.erase(v.begin()+2,v.begin()+5);
    for(auto it: v){
        cout<<it<<" ";
    }
    cout<<endl;
    set<int>st;
    st.insert(1);
    st.insert(2);
    for( auto it: st){
        cout<<it<<" ";
    }
    cout<<endl;
    auto a=st.lower_bound(1);
    cout<<*a;
    cout<<endl;
   map<int,pair<int,int>>ma;
   ma.insert({1,{2,3}});
   ma.insert({2,{3,4}});

   for(auto it: ma){
    cout<<it.first <<","<<it.second.first<<" "<<it.second.second<<" "<<endl;;
   }
    cout<<endl;
    cout<<ma[1].first<<" "<<ma[1].second;
 
    cout<<endl;
    int arr[3]={55,2,1};
    sort(arr,arr+3);
    for(int i=0;i<3;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int num=7;
    int con=__builtin_popcount(num);
    cout<<con;
    cout<<endl;
    string s="123";
    do
    {
        cout<<s<<" ";
    } while (next_permutation(s.begin(),s.end()));
    

}