#include<iostream>
using namespace std;
void print(int i,int n){
      if(i<1){
        return ;
      }
      print(i-1,n);
      cout<<i<<" ";

}
int main(){
    int n;
    cout<<"enter"<<endl;
    cin>>n;
    print(n,n);
}