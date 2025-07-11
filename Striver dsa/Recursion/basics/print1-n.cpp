#include <iostream>
using namespace std;

void print(int counter,int n)
{

    if(counter==n+1){
        return;
    }
    cout<<counter<<" ";
    print(counter+1,n);

}
int main(){
    int n;
    cout<<"enter"<<endl;
    cin>>n;
    int counter=1;
    print(counter,n);
}