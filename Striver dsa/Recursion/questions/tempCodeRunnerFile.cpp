#include <iostream>
using namespace std;
int counter=1;
void print(int n)
{

    if(counter==n+1){
        return;
    }
    cout<<counter<<endl;
    counter++;
    print(n);

}
int main(){
    int n;
    cout<<"enter"<<endl;
    cin>>n;
    print(n);
}