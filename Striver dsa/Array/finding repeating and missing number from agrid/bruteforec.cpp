#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
    vector<vector<int>> grid = {{1, 3}, {2, 2}};
    int repeated = -1;
    int missing = -1;
    for (int i = 1; i <= grid.size()*grid.size(); i++)
    {
        int count = 0;
        for (int r = 0; r < grid.size(); r++)
        {
            for (int c = 0; c < grid.size(); c++)
            {
                if (grid[r][c] == i)
                {
                    count++;
                }
            }
        }
        if (count == 2)
        {
            repeated = i;
        }
        else if (count == 0)
        {
            missing = i;
        }
    }
    cout << repeated << "," << missing;
}