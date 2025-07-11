#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int>nums={1,2,3};
    vector<vector<int>>permutation;
    vector<int>original=nums;
    sort(nums.begin(),nums.end());
    do{
        permutation.push_back(nums);
    }while(next_permutation(nums.begin(),nums.end()));

    for(int i=0;i<permutation.size();i++){
        if(permutation[i]==original){
            if(i+1<permutation.size()){
                nums=permutation[i+1];
            }
            else{
                nums=permutation[0];
            }
        }
    }
    for (int i = 0; i <nums.size(); i++)
    {
        cout<<nums[i];
    }
    

}