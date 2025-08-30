#include <iostream>
#include <vector>
using namespace std;
int frog_jumps(int n, vector<int> &h, vector<int> &dp_array, int k)
{
    dp_array[0]=0;
    int min_energy = INT_MAX;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(i-j>=0){
              dp_array[i]=min(dp_array[i],dp_array[i-j]+abs(h[i]-h[i-j]));
            }
        }
    }
    return dp_array[n];
}
int main()
{
    vector<int> h = {30, 10, 60, 10, 60, 50};
    int n = h.size() - 1;
    vector<int> dp_array(n + 1, INT_MAX);
    int k = 5;
    int ans = frog_jumps(n, h, dp_array, k);
    cout << ans;
}