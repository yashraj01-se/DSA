#include <vector>
#include <iostream>
using namespace std;
vector<int>ans={0,1};
int fibo(int n, int a, int b)
{

    if (n == 0)
    {
        return b;
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
    int f=fibo(n-2, a, b);
    cout<<f;
    
}