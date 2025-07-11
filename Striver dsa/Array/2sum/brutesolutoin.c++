#include<iostream>
using namespace std;
int main(){
    int arr[5]={2,6,5,8,11};
    int target=11;
    int j=1;
    for(int i=0;i<5;i++){
       for(int j=i+1;j<5;j++){
        if(arr[i]+arr[j]==target){
            cout<<"found!";
            return 0;
        }
       }
   }
    cout<<"Not Found";
    return 0;
}