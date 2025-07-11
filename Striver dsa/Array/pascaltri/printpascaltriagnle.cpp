#include <iostream>
using namespace std;
#include<vector>
int main(){
    int n=5;
   
    vector<vector<int>>ans;
    for(int row=1;row<=n;row++){
        vector<int>temp;
         int a=1;
        for(int col=1;col<=row;col++){
            temp.push_back(a);
              a=a*(row-col);
              a=a/(col);
              
        }
        ans.push_back(temp);
    }

    //for printning the vector of vectors:
    for(auto it:ans){
        for(auto num:it){
            cout<<num<<" ";
        }
          cout << endl;
    }

}