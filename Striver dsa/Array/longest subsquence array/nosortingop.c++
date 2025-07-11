#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_set>
using namespace std;
int main()
{
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    unordered_set<int>numss;
    int n=nums.size();
    if (n==0) return 0;
    int longest=1;
    for(int i=0;i<n;i++){
        numss.insert(nums[i]);
    }
    for(auto a:numss){
        if(numss.find(a-1)==numss.end()){
            int counter=1;
            int x=a;
            while(numss.find(x+1)!=numss.end()){
                    x++;
                    counter++;
            }
            longest=max(longest,counter);
        }
    }
    cout<<longest;
}