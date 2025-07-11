#include <vector>
#include <iostream>
using namespace std;
vector<int> ans = {0, 1};
vector<int> fibo(int n, int a, int b)
{

    if (n == 0)
    {
        return ans;
    }
    int c;
    c = a + b;
    ans.push_back(c);
    return fibo(n - 1, b, c);
}
int main()
{
    int a = 0;
    int b = 1;
    int n;
    cout << "enter" << endl;
    cin >> n;
    fibo(n-2, a, b);
    for (auto it : ans)
    {
        cout << it << " ";
    }
}