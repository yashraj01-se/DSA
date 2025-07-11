#include<iostream>
#include<sstream>
using namespace std;

int main() {
    int num = 12890;
    stringstream ss;
    ss<<num;
    string s =ss.str();
   int i=0;
   bool ispal=true;
   int j=s.length()-1;
   while(i<j){
    if(s[i]!=s[j]){
         ispal=false;
         break;
    }
    i++;
    j--;
   }
   if(ispal){
    cout<<"palindrome";
   }
   else{
    cout<<"not";
   }
}
