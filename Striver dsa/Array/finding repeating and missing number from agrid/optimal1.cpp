#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
    vector<int> grid = {4,3,6,2,1,1};
    int n=grid.size();
    int sum=0;
    int sum2=0;
    for(auto it: grid){
        sum+=it;
    }
    for(auto it:grid){
        sum2+=it*it;
    }
    int sumation=(n*(n+1))/2;
    int sumation2=(n*(n+1)*(2*n+1))/6;
    int equation1=sum-sumation;  //x-y;
    int equation2=sum2-sumation2;
    equation2=equation2/equation1;  //x+y;

    int x=(equation1+equation2)/2;
    int y=(equation2-equation1)/2;

    cout<<x<<","<<y;


}