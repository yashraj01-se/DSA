#include<iostream>
using namespace std;

int main() {
    int num = 121;
    int sum = 0;
    int rem;


    while(num > 0) {
       rem=num%10;
       sum+=rem;
       num=num/10;
    }

    cout << "The sum of the digits is: " << sum << endl;
    return 0;
}
