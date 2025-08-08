#include <iostream>
#include <vector>
using namespace std;
int maxi(vector<int> &Books)
{
    int i = 0;
    int n = Books.size();
    int Maxi = INT_MIN;
    while (i < n)
    {
        if (Books[i] > Maxi)
        {
            Maxi = Books[i];
        }
        i++;
    }
    return Maxi;
}

int suma(vector<int> &Books)
{
    int sum = 0;
    for (int i = 0; i < Books.size(); i++)
    {
        sum += Books[i];
    }
    return sum;
}
int Canpaint(vector<int> &hours, int mid)
{
    int counter = 1;
    int hourspainting = 0;
    for (int i = 0; i < hours.size(); i++)
    {
        if (hourspainting + hours[i] <= mid)
        {
            hourspainting += hours[i];
        }
        else
        {
            counter++;
            hourspainting = hours[i];
        }
    }
    return counter;
}
int painting(vector<int> &hours, int painters)
{
    int lb = maxi(hours);
    int ub = suma(hours);
    int ans = 0;
    while (lb <= ub)
    {
        int mid = lb + (ub - lb) / 2;
        int num = Canpaint(hours, mid);
        if (num <= painters)
        {
            ans = mid;
            ub = mid - 1;
        }
        else
        {
            lb = mid + 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> hours = {10, 20, 30, 40};
    int painters = 2;
    int ans = painting(hours, painters);
    cout << ans;
}
