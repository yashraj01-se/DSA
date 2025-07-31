#include<iostream>
using namespace std;
int sqrtnum(int num){
    int ub=num;
    int lb=1;
    int ans=1;
    while(lb<=ub){
        int mid=lb+(ub-lb)/2;
        if(mid*mid<=num){    // question condition...
            ans=mid;
            lb=mid+1;       //eleminating left half...
        }
        else{
            ub=mid-1;   // eleminating right half...
        }
    }
    return ans;
}
int main(){
    int number=35;
    int num=sqrtnum(number);
    cout<<num;
}