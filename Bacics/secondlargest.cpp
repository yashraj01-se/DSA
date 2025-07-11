#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int arr[5]={12,3,4,1,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int lar=arr[0];
    int secondlar=-1;
    for(int i=1;i<n;i++){
        if(lar<arr[i]){
            secondlar=lar;
            lar=arr[i];
        }
        else if(arr[i]<lar & arr[i]>secondlar){
            secondlar=arr[i];
        }
    }
   cout<<secondlar;

}