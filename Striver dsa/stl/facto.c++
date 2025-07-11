#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of which you want to find out the factorail:"<<endl;
    cin>>n;
    int mul=1;
    for(int i=n; i>=1;i--){
        mul=mul*i;
    }
    cout<<mul;
}