#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    int arr[5]={2,6,5,8,11};
    int target=11;
    unordered_map<int,int>number;
    for(int i=0;i<5;i++){
        int rem=target-arr[i];
        if(number.find(rem)!=number.end()){
              cout<<"index are:"<<number[rem]<<","<<i<<endl;
              return 0;
        }
        number[arr[i]]=i;
        
    }
    cout<<"not found";
        return 0;
}