#include<iostream>
using namespace std;

int main() {
    int num=6;
    int a=0;
    int b=1;
    int c;
    for(int i=0;i<num-1;i++){
        c=a+b;
        a=b;
        b=c;
    }
    cout<<a;
}