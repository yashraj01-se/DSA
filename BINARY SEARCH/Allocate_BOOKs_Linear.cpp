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

int CanAllocate(vector<int> &books, int pages)
{
    int studentcount = 1;
    int pagescount = 0;
    for (int i = 0; i < books.size(); i++)
    {
        if (pagescount + books[i] <= pages)
        {
            pagescount += books[i];
        }
        else
        {
            studentcount++;
            pagescount = books[i];
        }
    }
    return studentcount;
}

int allocate(vector<int> &Books, int studentnum)
{
    if (studentnum > Books.size())
    {
        return -1;
    }
    int lb = maxi(Books);
    int ub = suma(Books);
    for (int pages = lb; pages <= ub; pages++)
    {
        int num = CanAllocate(Books, pages);
        if (num == studentnum)
        {
            return pages;
        }
    }
    return -1;
}

int main()
{
    vector<int> Books = {25, 46, 28, 49, 24};
    int m = 4;
    int ans = allocate(Books, m);
    cout<<ans;
}