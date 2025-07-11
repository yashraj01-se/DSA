#include<iostream>
#include<vector>
using namespace std;
int main(){
    int arr[9]={1,2,3,1,1,1,4,2,3};
    int k=3;
    int maxlength=0;
    for (int i=0;i<9;i++){
        long long sum=0;
        for (int j=i;j<9;j++){
                sum+=arr[j];
                if(sum==k){
                 maxlength=max(maxlength,j-i+1);
                } 
              }
        }
    cout<<maxlength;


}