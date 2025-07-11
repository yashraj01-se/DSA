#include<iostream>
using namespace std;
void print(int i,int n){
      if(i>n){
        return ;
      }
      print(i+1,n);
      cout<<i<<" ";

}
int main(){
    int n;
    cout<<"enter"<<endl;
    cin>>n;
    int i=1;
    print(i,n);
}