#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
void solve(vector<string>&res,int index,vector<string>&numbers){
        int n=numbers.size();
        if(index==n){
            string temp="";
            for(const string& s:numbers){
                temp+=s;
            }
            res.push_back(temp);
            return;
        }
        for(int i=index;i<n;i++){
            swap(numbers[index],numbers[i]);
            solve(res,index+1,numbers);
            swap(numbers[index],numbers[i]);
        }
}
int main(){
    int n=3;
    int k=3;
     vector<string> numbers;
        for (int i = 1; i <= n; ++i){
              numbers.push_back(to_string(i));
        }
        vector<string>res;
        solve(res,0,numbers);
        sort(res.begin(), res.end());
        cout << "The " << k << "-th permutation is: " << res[k - 1] << endl;

    return 0;
}
