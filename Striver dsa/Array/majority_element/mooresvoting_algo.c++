#include<iostream>
using namespace std;
int findMajorityElement(int arr[], int n) {
    //moore voting  algo....
    int candidate=arr[0];
    int count=1;
    int i=1;
    while(i<n){
        if(arr[i]==candidate){
            count++;
        }
      else{
        count--;
        if(count==0){
          candidate=arr[i];
          count=1;
        }
      }
       i++;
    }
    //verifying the candidate....
    int c=0;
	for(int i=0;i<n;i++){
		if(arr[i]==candidate){
			c++;
		}
	}
	if(c>n/2){
		return candidate;
	}
	else{
		return -1;
	}
}
int main() {
    int arr[] = {2, 2, 1, 1, 2, 2, 2,3,3,3,3,3,3,3,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Majority Element: " << findMajorityElement(arr, n) << endl;
}