#include<iostream>
using namespace std;
// int main(){
//     int i,j,k,s;
//     int n=5;
//     for (i=1; i<=n; i++){
//         for (j=1; j<=i; j++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }
//     for (i=1; i<=n; i++){    
//         for (k=n-i; k>=1; k--){
//             cout<<"*";
//         }
//         cout<<endl;
//     }    
// return 0;
// }


// int main(){
//     int i,j,l;
//     int n=5;
//     for (i=1; i<=n; i++){
//         if (i%2!=0){
//             l=1;}
//         else{
//             l=0;}
//         for (j=1; j<=i; j++){
//             cout<<l;
//             l=1-l;
//         }
//         cout<<endl;
//     }
// }


// int main(){
//     int i,j,k;
//     int n=4;
//     for (i=1; i<=n; i++){
//         for (j=1; j<=i; j++){
//             cout<<j;
//         }
//         for (k=n-i; k>=1; k--){
//             cout<<" ";
//         }
//         for (k=n-i; k>=1; k--){
//             cout<<" ";
//         }
//         for (j=i; j>=1; j--){
//             cout<<j;
//         }
//         cout<<endl;
//     }
// return 0;
// }


// int main(){
//     int i,j;
//     int n=5;
//     int x=1;
//     for (i=1; i<=n; i++){
//         for (j=1; j<=i; j++){
//             cout<<x<<" ";
//             x=x+1;
//         }
//         cout<<endl;
//     }
// return 0;
// }


// int main(){
//     int i;
//     char j;
//     int n=5;
//     for (i=1; i<=n; i++){
//         for (j='A'; j<='A'+i-1; j++){
//             cout<<j;
//         }
//         cout<<endl;
//     }
// return 0;
// }


// int main(){
//     int i;
//     char j;
//     for (i=5; i>=1; i--){
//         for (j='A'; j<='A'+i-1 ; j++){
//             cout<<j;
//         }
//         cout<<endl; 
//     }
// return 0; 
// }


// A
// BB
// CCC
// DDDD
// EEEEE

// int main(){
//     int i;
//     char j;
//     int n=5;
//     char k='A';
//     for (i=1; i<=n; i++){
//         for (j='A'; j<='A'+i-1; j++){
//             cout<<k;
//         }
//         cout<<endl;
//         k=k+1;
//     }
// return 0;
// }


// int main(){
//     int i,l;
//     char j;
//     int n=5;
//     for (i=1; i<=n; i++){
//         for (l=1; l<=n-i; l++){
//             cout<<" ";
//         }
//         for (j='A'; j<='A'+i-1; j++){
//             cout<<j;
//         }
//         for (j='A'+i-2; j>='A'; j--){
//             cout<<j;
//         }
//         cout<<endl;
//     }
// return 0;    
// }


// E
// DE
// CDE
// BCDE
// ABCDE

// int main(){
//     int i;
//     char j;
//     int n=5;
//     for (i=1; i<=n; i++){
//         for (j='E'-i+1; j<='E'; j++ ){
//             cout<<j;
//         }
//         cout<<endl;
//     }
// return 0; 
// }


// **********
// ****  ****
// ***    ***
// **      **
// *        *
// *        *
// **      **
// ***    ***
// ****  ****
// **********

// int main(){
//     int i,j,k,l,f;
//     int n=5;
//     for (i=1; i<=n; i++){
//         for (j=n-i+1; j>=1; j--){
//             cout<<"*";
//         }
//         for (j=1; j<=2*(i-1); j++){
//             cout<<" ";
//         }
//         for (j=n-i+1; j>=1; j--){
//             cout<<"*";
//         }
//         cout<<endl;
//     }
//     for (k=1; k<=n; k++){
//         for (l=1; l<=k; l++){
//             cout<<"*";
//         }
//         for (f=10-2*k; f>=1; f--){
//             cout<<" ";
//         }
//         for (j=1; j<=k; j++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }
// return 0;    
// }


// ****
// *  *
// *  *
// ****

// int main(){
//     int i,j,k;
//     int n=4;
//     for (i=1; i<=n; i++){
//         for (j=1; j<=n; j++){
//             if (i==1 || i==n || j==1  || j==n){
//                 cout<<"*";
//             }
//             else{
//                 cout<<" ";
//             }
//         }
//         cout<<endl;
//     }
// return 0;    
// }


// brute force
// int main(){
//     int i,j,l;
//     int n=7;
//     int k=4;
//     for (i=1; i<=n; i++){
//         for (j=1; j<=n; j++){
//             if (i==1 || i==n || j==1  || j==n){
//                 cout<<k;
//             }
//             else if(i==2 || i==n-1 || j==2  || j==n-1){
//                 cout<<k-1;
//             }
//             else if(i==3 || i==n-2 || j==3  || j==n-2){
//                 cout<<k-2;
//             }
//             else if(i==4 || i==n-3 || j==4  || j==n-3){
//                 cout<<k-3;
//             }
//         }
//         cout<<endl;
//     }
// return 0;    
// }


// int main(){
//     int i,j;
//     int n=4;
//     int k=2*n-1;
//     for (i=1; i<=k; i++){
//         for (j=1; j<=k; j++){
//             int top=i;
//             int bottom=k-i+1;
//             int left=j;
//             int right=k-j+1;
//             cout<<(n-min(min(top,bottom), min(left,right)))+1;
//         }
//         cout<<endl;
//     }
// return 0;
// }


// *        *
// **      **
// ***    ***
// ****  ****
// **********
// ****  ****
// ***    ***
// **      **
// *        *

// int main(){
//     int i,j;
//     int n=5;
//     for (i=1; i<=n; i++){
//         for (j=1; j<=i; j++){
//             cout<<"*";
//         }
//         for (j=2*n-2*i; j>=1; j--){
//             cout<<" ";
//         }
//         for (j=1; j<=i; j++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }
//     for (i=1; i<=n; i++){
//         for (j=n-i; j>=1; j--){
//             cout<<"*";
//         }
//         for (j=1; j<=2*i; j++){
//             cout<<" ";
//         }
//         for (j=n-i; j>=1; j--){
//             cout<<"*";
//         }
//         cout<<endl;
//     }
// return 0;
// }










