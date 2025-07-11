#include <vector>
#include <iostream>
using namespace std;
int fibo(int n)
{
   if(n<=1){
    return n;
   }
   return fibo(n-1)+fibo(n-2);
}
int main()
{
    int a = 0;
    int b = 1;
    int n;
    cout << "enter" << endl;
    cin >> n;
    int f=fibo(n);
    cout<<f;
    
}