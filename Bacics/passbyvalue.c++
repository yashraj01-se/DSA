#include<iostream>
using namespace std;
void sum(int num){
     num +=10;
     cout<<num<<"\n";

}
void sum2(int & num){
    num +=10;
    cout<<num<<"\n";
}
int main(){
   int num=10;
   sum(num);      // pass by value copy of variable is given not the variable itself....
   cout<<num<<"\n";
   sum2(num);
    cout<<num;     // pass by reference... varibale is itself shared....
       
}