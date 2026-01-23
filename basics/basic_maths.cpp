#include<iostream>
#include <cmath>
#include <string>
using namespace std;

//number of digits
// int main(){
//     int s,c,l;
//     cout<<"enter number: ";
//     cin>>s;
//     c=0;
//     while (s>0){
//         l=s%10;
//         s=s/10;
//         c=c+1;
//     }
//     cout<<c;
// return 0;
// }


//reverse a number
// int main(){
//     int s=45695376;
//     int c=0,l;
//     while (s>0){
//         l=s%10;
//         s=s/10;
//         c=c*10;
//         c=c+l;
//     }
//     cout<<"reversed number: "<<c;
// return 0;    
// }


//palindrome
// int main(){
//     int s, original;
//     cin>>s;
//     original=s;
//     int c=0,l;
//     while (s>0){
//         l=s%10;
//         s=s/10;
//         c=c*10;
//         c=c+l;
//     }
//     if (original==c){
//         cout<<"PALINDROME";
//     }
//     else{
//         cout<<"NOT PALINDROME";
//     }
// return 0;    
// }


//armstrong number
// int main(){
//     int num=1634;
//     string k=to_string(num);
//     int last,count=0;
//     float sum=0;
//     int t=k.length();
//     float original=num;
//     while (num>0){
//         last=num%10;
//         num=num/10;
//         sum= sum+ (pow(last, t));
//     }
//     if (sum==original){
//         cout<<"Armstrong";
//     }
//     else{
//         cout<<"NOT ARMSTRONG";
//     }
// return 0;    
// }


//divisors
// int main(){
//     int i=36,j;
//     for (j=1; j<=i; j++){
//         if (i%j==0){
//             if (j!=i){
//                 cout<< j<< ", ";
//             }
//             else{
//                 cout<<j;
//             }
//         }
//     }
// return 0;    
// }


//check for prime
// int main(){
//     int i=19,j;
//     bool prime=true;
//     for (j=2; j<=sqrt(i); j++){
//         if (i%j==0){
//             prime=false;
//             break;
//         }
//     }
//     if (prime==true){
//         cout<<i<<" is a prime number";
//     }
//     else{
//         cout<<i<<" is not a prime number";
//     }
// return 0;    
// }


//gcd or hcf
// int main(){
//     int n1=12,n2=8,i;
//     int gcd=1;
//     for (i=1; i<=min(n1,n2); i++){
//         if (n1%i==0 && n2%i==0){
//             gcd=i;
//         }
//     }
//     cout<<"gcd: "<<gcd;
// return 0;    
// }
















