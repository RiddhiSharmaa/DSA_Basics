#include<bits/stdc++.h>
using namespace std;

double  mySqrt(int x) {
        double low = 0.0;
        double high = x;

        while ((high-low) > 1e-6){
            double mid = (high+low)/2;
            if (mid*mid < x){
                low = mid;
            }
            else{
                high = mid;
            }
        }
        return low;
}

int main(){
    cout << fixed << setprecision(3) << mySqrt(68); 
}