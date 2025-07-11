#include<iostream>
#include<unordered_map>
using namespace std;
int findMajorityElement(int arr[], int n) {
	unordered_map<int,int>map;
	for(int i=0;i<n;i++){
        map[arr[i]]++;
	    
	}
	for(auto it:map){
		if(it.second>n/2){
			return it.first;
		}
	}
	return -1;
}
int main() {
    int arr[] = {2, 2, 1, 1, 2, 2, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Majority Element: " << findMajorityElement(arr, n) << endl;
}