#include <iostream>
#include <vector>
using namespace std;
bool ls(vector<int> &nums, int n)
{
    for(int i=0;i<nums.size();i++){
        if(nums[i]==n){
            return true;
        }
    }
    return false;
}
int main()
{
    vector<int>arr={100, 4, 200, 1, 3, 2};
    int longest=1;
  int n = arr.size();
    for(int i=0;i<n;i++){
        int curr=arr[i];
        int counter=1;
        while(ls(arr,curr+1)){
             curr++;
             counter++;
        }
        longest=max(longest,counter);
    }
    cout<<longest;
}