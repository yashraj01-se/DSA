#include <iostream>
#include <vector>
using namespace std;
int median(int arr1[], int arr2[],int n,int m)
{
    vector<int> arr3;
    int i = 0;
    int j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            arr3.push_back(arr1[i]);
            i++;
        }
        else
        {
            arr3.push_back(arr2[j]);
            j++;
        }
    }
    while(i<n){
        arr3.push_back(arr1[i]);
        i++;
    }
    while(j<m){
        arr3.push_back(arr2[j]);
        j++;
    }

    if(arr3.size()%2==0){
        int i=(arr3.size()-1)/2;
        int j=arr3.size()/2;
        return (arr3[i]+arr3[j])/2;
    }
    else{
        int mid=(arr3.size()-1)/2;
        return arr3[mid];
    }
}
int main()
{
    int arr1[6] = {1, 3, 4, 7, 10, 12};
    int arr2[4] = {2, 3, 6, 15};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    int ans = median(arr1, arr2,n,m);
    cout<<ans;
}