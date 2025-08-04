#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int>num={2,3,4,7,11};
    int lb=0;
    int k=5;
    int ub=num.size()-1;
    while(lb<=ub){
        int mid=lb+(ub-lb)/2;
        int missing=num[mid]-(mid+1);
        if(missing<k){
            lb=mid+1;
        }
        else{
            ub=mid-1;
        }
    }
    cout<<lb+k;
}