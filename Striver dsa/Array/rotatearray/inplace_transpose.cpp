#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int ans[3][3];
    cout<<"before"<<endl;
     for (int i = 0; i <3; i++)
    {
        for (int j = 0; j <3; j++)
        {
            cout << arr[i][j] << " "; // Add space between elements
        }
        cout << endl; // Add new line after each row
    }

    //step 1: transpose the matrix:
    for(int i=0;i<3;i++){
        for(int j=i+1;j<3;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
    //step 2:reverse each row:
    for(int i=0;i<3;i++){
        reverse(arr[i], arr[i] + 3);
    } 

    cout<<"after"<<endl;
     for (int i = 0; i <3; i++)
    {
        for (int j = 0; j <3; j++)
        {
            cout << arr[i][j] << " "; // Add space between elements
        }
        cout << endl; // Add new line after each row
    }
}