// // using hashing of array;
// class Solution {
// public:
//     vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
//         vector<int>ans;
//         int n=grid.size();
//         int size=n*n;
//         vector<int>freq(size+1,0);
//         for(auto& it:grid){
//             for(auto i:it){
//                 freq[i]++;
//             }
//         }
//            int repeated = -1, missing = -1;


//         for(int i=1;i<=size;i++){
//             if(freq[i]==2){
//                 repeated=i;
//             }
//             if(freq[i]==0){
//                 missing=i;
//             }
//         }
//        return {repeated,missing};
//         }
//     };