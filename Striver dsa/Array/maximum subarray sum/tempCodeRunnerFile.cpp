#include <iostream>
using namespace std;
int main()
{
    int arr[8] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int maxi = INT_MIN;
    int sum = 0;
    int i=0;
    while(i<8){
        sum+=arr[i];
        if(maxi<sum){
            maxi=sum;
        }
        if(sum<0){
            sum=0;
         }
     i++;
    }
    cout<<maxi;
}