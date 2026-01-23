#include <iostream>
using namespace std;

int main(){
  string s,k;
  cout<<"enter: ";
  cin>>s;
  int i,t;
  i=0;
  t=s.length();
  k="";
  while (i<t){
    k=k+s[t-1];
    t=t-1;
  }
  if(k==s){
    cout<<"Palindrome";
  }
  else{
    cout<<"Its not";
  }
  return 0;
}
