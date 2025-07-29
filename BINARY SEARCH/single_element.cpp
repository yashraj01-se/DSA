#include<iostream>
#include<vector>
using namespace std;
int singleNonDuplicate(vector<int>& arr)
{
	 int n=arr.size();
        if(arr.size()==1)return arr[0];
        if(arr[0]!=arr[1])return arr[0];
        if(arr[n-1]!=arr[n-2])return arr[n-1];

        int lb=1;
        int ub=n-2;
        while(lb<=ub){
            int mid=lb+(ub-lb)/2;
            if(arr[mid]!=arr[mid+1] && arr[mid]!=arr[mid-1]){
                return arr[mid];
            }
            if((mid%2==1 && arr[mid]==arr[mid-1])  
            || (mid%2==0 && arr[mid]==arr[mid+1])){
                 lb=mid+1;
            }
            else{
                ub=mid-1;
            }
        }
        return -1; 
}
int main(){
    vector<int>arr={1,1,2,2,3,3,4,5,5};
    int ele=singleNonDuplicate(arr);
    cout<<ele;
}