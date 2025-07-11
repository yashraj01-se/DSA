#include <iostream>
#include<vector>
using namespace std;
int main()
{
    int profit=0;
    int sum=0;
    int arr[6]={7,1,5,3,6,4};
    vector<int>ans;
    for(int i=0;i<6;i++){
        for(int j=i;j<6;j++){
            sum=arr[j]-arr[i];
            profit=max(profit,sum);

        }
    }
    cout<<"Max profit:"<<profit<<endl;
    for(auto it: ans){
        cout<<it<<" ";
    }


}