#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<vector<int>> arr = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int row = arr.size();
    int col = arr[0].size();
    int col0 = 1;
    // vector<int>srow(row,0);
    // vector<int>scol(col,0);

    // step1:Mark the arr[i][0] and arr[0][j] and variable col1 as 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == 0)
            {
                arr[i][0] = 0;

                if (j != 0)
                {
                    arr[0][j] = 0;
                }
                else
                {
                    col0 = 0;
                }
            }
        }
    }

    // step 2:we will iterate throgh the array but not in firt col and row...
    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            if (arr[i][j] != 0)
            {
                if (arr[i][0] == 0 || arr[0][j] == 0)
                {
                    arr[i][j] = 0;
                }
            }
        }
    }

    // step 3:we will now look on the first row and col...
    if (arr[0][0] == 0)
    {
        for (int j = 0; j < col; j++)
        {
            arr[0][j] = 0;
        }
    }
    if (col0 == 0)
    {
        for (int i = 0; i < row; i++)
        {
            arr[i][0] = 0;
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " "; // Add space between elements
        }
        cout << endl; // Add new line after each row
    }
}