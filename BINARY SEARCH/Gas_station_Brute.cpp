#include <iostream>
#include <vector>
using namespace std;
long double gas(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> howmany(n - 1, 0);
    for (int gasstation = 1; gasstation <= k; gasstation++)
    {
        long double maxvalue = -1;
        int maxindex = -1;
        for (int i = 0; i < n - 1; i++)
        {
            long double diff = arr[i + 1] - arr[i];
            long double sectionlenght = diff / (howmany[i] + 1);

            if (maxvalue < sectionlenght)
            {
                maxvalue = sectionlenght;
                maxindex = i;
            }
        }
        howmany[maxindex]++;
    }

    long double ans = -1;
    for (int i = 0; i < n - 1; i++)
    {
        long double diff = arr[i + 1] - arr[i];
        long double sectionlenght = diff / (howmany[i] + 1);
        ans = max(ans, sectionlenght);
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 13, 17, 23};
    int k = 5;
    long double ans=gas(arr, k);
    cout<<ans;
}