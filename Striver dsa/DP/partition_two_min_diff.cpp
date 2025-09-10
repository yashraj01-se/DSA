// #include<algorithm>
// class Solution {
// public:
//     int minimumDifference(vector<int>& nums) {
//         int n=nums.size();
//         int total_sum=0;
//         for(int i=0;i<nums.size();i++)total_sum+=nums[i];
//         int k=total_sum;
//         vector<vector<bool>>dp(nums.size(),vector<bool>(k+1,false));

//         //base case:
//         for(int i=0;i<n;i++)dp[i][0]=true;
//         if(nums[0]<=k)dp[0][nums[0]]=true;

//         //filling the Dp_array:

//         bool pick=false;
//         bool not_pick=false;

//         for(int i=1;i<n;i++){
//             for(int j=1;j<=k;j++){
//                 not_pick=dp[i-1][j];
//                 if(nums[i]<=j){
//                     pick=dp[i-1][j-nums[i]];
//                 }
//                 dp[i][j]=pick||not_pick;
//             }
//         }

//         //now interate throgh the min and max differnce that can be there between s1 ans s2
//         int mini=1e9;
//         for(int s1=0;s1<=total_sum/2;s1++){
//             if(dp[n-1][s1]){
//                 mini=min(mini,abs((total_sum-s1)-s1));
//             }
//         }
//         return mini;
//     }
// };