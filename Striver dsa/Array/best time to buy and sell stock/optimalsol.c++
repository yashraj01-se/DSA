#include <iostream>
using namespace std;
int main()
{
    int profit=0;
    int mini=INT_MAX;
    int arr[6]={7,1,5,3,6,4};
    for(int i=0;i<6;i++){
        mini=min(mini,arr[i]);
        profit=max(profit,arr[i]-mini);
    }
    cout<<profit;
   //for every ith element i will find the min in the 1st to ith number...
   // max in them....
}