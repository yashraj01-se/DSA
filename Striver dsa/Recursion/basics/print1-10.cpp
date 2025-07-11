#include <iostream>
using namespace std;
    int counter = 0;
void print()
{
    if (counter == 10)   //1.base condition....
    {
        return;
    }
    cout << counter << endl;
    counter++;        //reinitialize of condition.....
    print();          //function call again...
}
int main()
{
    print();
}