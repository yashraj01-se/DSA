#include <iostream>
using namespace std;
bool checker(string s, int i)
{
    int n = s.length();
    if(i>=n/2)return true;
    if (s[i] != s[n - i - 1])return false;
    return checker(s, i + 1);
}
int main()
{
    string s;
    cout << "enter the string" << endl;
    cin >> s;
    int i = 0;
    bool check = checker(s, i);
    if (check)
    {
        cout << "It is a palindrome" << endl;
    }
    else
    {
        cout << "It is not a palindrome" << endl;
    }
}