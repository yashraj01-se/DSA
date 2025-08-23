#include <iostream>
#include <vector>
using namespace std;
bool search(int arr[3][4],int num)
{
    int low=0;
    int high=(3*4)-1;
    bool flag=false;
    while(low<=high){
        int mid=low+(high-low)/2;
        int row=mid/4;
        int col=mid%4;

        if(arr[row][col]==num){
            flag=true;
            break;
        }
        else if(arr[row][col]<num)low=mid+1;
        else high=mid-1;
    }
    return flag;
}
int main()
{
    int arr[3][4] = {{3, 4, 7, 9},
                     {12, 13, 16, 18},
                     {20, 21, 23, 29}};
    bool answer = false;
    int num = 23;
    int n = sizeof(arr[0]) / sizeof(arr[0][0]);
    int m=4;
    bool ans=search(arr,num);
    if(ans){
        cout<<"Number Found";
    }
    else{
        cout<<"Number Not Found";
    }
}