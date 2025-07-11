#include <iostream>
#include <vector>
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
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            ans[2-j][i]=arr[i][j];
        }
    }
    cout<<"anti-clockwise"<<endl;
    for (int i = 0; i <3; i++)
    {
        for (int j = 0; j <3; j++)
        {
            cout << ans[i][j] << " "; // Add space between elements
        }
        cout << endl; // Add new line after each row
    }
     for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            ans[j][(3-1)-i]=arr[i][j];
        }
    }

    cout<<"clock-wise"<<endl;
    for (int i = 0; i <3; i++)
    {
        for (int j = 0; j <3; j++)
        {
            cout << ans[i][j] << " "; // Add space between elements
        }
        cout << endl; // Add new line after each row
    }

}