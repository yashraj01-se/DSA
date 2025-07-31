#include<iostream>
using namespace std;
int main(){
    int number=28;
    int ans=1;
    for(int i=1;i<number;i++){
        if(i*i<=number){
            ans=i;
        }
        else{
            break;
        }
    }
    cout<<ans;
    return 0;
}