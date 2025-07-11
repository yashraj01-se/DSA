#include<unordered_map>
#include<vector>
#include<iostream>
using namespace std;
int main(){
    vector<int>a={4,2,2,6,4};
    int sum=6;
    unordered_map<int,int>mpp;
    int xo;
    int count=0;
    mpp[xo]++;    //(0,1) at first place in map...
    for (int i = 0; i <a.size(); i++)
    {
        xo=xo^a[i];            // phele pure ka xor find karo...
        int x=xo^sum;          // uske bad jo formalu hai yaad karo...
        if(mpp.find(x)!=mpp.end()){       // ab dekho ki vo x map me hai ki nahi...
            count+=mpp[x];
        }
        mpp[xo]++;   // xor to dalna hi hai...
    }
    cout<<count;

}