#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
int main(){
    int fac=1;
    int n=3;
    int k=3;
    vector<int>numbers;
    for(int i=1;i<n;i++){
        fac=fac*i;
    }
    for(int i=1;i<=n;i++){
        numbers.push_back(i);
    }
    string s="";
    k=k-1;
    while(!numbers.empty()){
        s=s+to_string(numbers[k/fac]);
        numbers.erase(numbers.begin()+k/fac);
        if(numbers.empty()){
            break;
        }
    k=k%fac;
    fac=fac/numbers.size();

    }
    cout<<s;
}