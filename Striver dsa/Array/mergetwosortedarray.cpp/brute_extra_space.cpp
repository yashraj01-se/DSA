#include<iostream>
using namespace std;
int main(){
    int arr1[4]={2,4,5,6};
    int arr2[4]={1,3,7,9};
    int arr3[8];
    int i=0;
    int j=0;
    int k=0;
    while(i<4 || j<4){
        if(arr1[i]>arr2[j]){
            arr3[k++]=arr2[j++];
        }
        else{
            arr3[k++]=arr1[i++];
        }
    }
    while(i<4){
        arr3[k++]=arr1[i++];
    }
    while(j<4){
        arr3[k++]=arr2[j++];
    }

   for(int i=0;i<4;i++){
       arr1[i]=arr3[i];
       arr2[i]=arr3[i+4];
   }

   cout << "arr1: ";
    for (int i = 0; i < 4; i++) {
        cout << arr1[i] << " ";
    }

    cout << "\narr2: ";
    for (int i = 0; i < 4; i++) {
        cout << arr2[i] << " ";
    }
  

}