#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n=10;
    int r=3;
    int res=1;
    for(int i=0;i<r;i++){
        res=res*(n-i);
        res=res/(i+1);
    }
    cout<<res;
}