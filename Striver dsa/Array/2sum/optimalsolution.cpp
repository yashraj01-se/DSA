#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    int arr[5]={2,5,6,8,11};
    int target=11;
    int left=0;
    int right=4;
    while(left<right){
        if(arr[left]+arr[right]==target){
            cout << "Indices: " << left << " and " << right << endl;
          return 0;
        }
        if(arr[left]+arr[right]<target){
            left++;
        }
        else{
           right--;
        }
        
    }
    return 0;

}