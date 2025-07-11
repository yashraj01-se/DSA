#include <iostream>
using namespace std;
void print(int counter,int n)
{

    if(n<1){
        return;
    }
    cout<<n<<" ";
    print(counter,n-1);

}
int main(){
    int n;
    cout<<"enter"<<endl;
    cin>>n;
    int counter=1;
    print(counter,n);
}