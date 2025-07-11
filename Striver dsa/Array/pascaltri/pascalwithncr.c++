// class Solution {
// public:
//     long long NCR(long long r, long long n) {
//     long long res = 1LL;
//     for (long long i = 0; i < r; i++) {
//         res = res * (n - i);
//         res = res / (i + 1);
//     }
//     return res;
// }
//     vector<vector<int>> generate(int numRows) {
        
//         vector<vector<int>>ans;
//         for(int row=1;row<=numRows;row++){
//             vector<int>temp;
//             for(int col=1;col<=row;col++){
//                 temp.push_back(NCR(col-1,row-1));
//             }
//             ans.push_back(temp);
//         }
//         return ans;
//     }
// };