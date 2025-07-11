#include <iostream>
using namespace std;
void suma(int counter, int n, int sum)
{

    if (counter > n)
    {
        cout << sum;
        return;
    }
    suma(counter + 1, n, sum = sum + counter);
}
int main()
{
    int n;
    cout << "enter" << endl;
    cin >> n;
    int counter = 1;
    int sum = 0;
    suma(counter, n, sum);
}
