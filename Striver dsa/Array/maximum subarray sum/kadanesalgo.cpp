#include <iostream>
using namespace std;
int main()
{
    int arr[8] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int maxi = INT_MIN;
    int sum = 0;
    int i=0;
    int start=-1;
    int ansstart=-1;
    int ansend=-1;
    while(i<8){
        if(sum==0) start=i;
        sum+=arr[i];
        if(maxi<sum){
            maxi=sum;
            ansstart=start;
            ansend=i;
        }
        if(sum<0){
            sum=0;
        }
        
        i++;
    }
    for(int i=ansstart;i<=ansend;i++){
        cout<<arr[i];
        if(i < ansend) cout << ",";
    }cout<<endl;
    cout<<maxi;
}