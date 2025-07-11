#include<iostream>
using namespace std;
int main(){
    int arr[10]={0,1,2,0,2,1,2,0,0,1};
    int cout0=0;
    int cout1=0;
    int cout2=0;
    for(int i=0;i<10;i++){
        if(arr[i]==0){
            cout0++;
        }
        else if(arr[i]==1){
            cout1++;
        }
        else{
            cout2++;
        }
    }
    int index=0;
    for(int i=0;i<cout0;i++){
        arr[index++]=0;
    }
    for(int i=0;i<cout1;i++){
        arr[index++]=1;
    }
    for(int i=0;i<cout2;i++){
        arr[index++]=2;
    }

    for(int i=0;i<10;i++){
        cout<<arr[i];
    }cout<<endl;

}