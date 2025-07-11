#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int arr1[4]={2,4,5,6};
    int arr2[4]={1,3,7,9};
    int size1=sizeof(arr1)/sizeof(arr1[0]);
    int size2=sizeof(arr2)/sizeof(arr2[0]);
    int i=size1-1;
    int j=0;
    while(i>=0 && j<size2){
        if(arr1[i]>arr2[j]){
            swap(arr1[i],arr2[j]);
            i--;
            j++;
        }
        else{
            break;
        }
    }
    sort(arr1,arr1+size1);
    sort(arr2,arr2+size2);

     cout << "arr1: ";
    for (int i = 0; i < 4; i++) {
        cout << arr1[i] << " ";
    }

    cout << "\narr2: ";
    for (int i = 0; i < 4; i++) {
        cout << arr2[i] << " ";
    }
  


}