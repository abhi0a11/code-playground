#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int sqrtq(int n){
    int s =0, e = n-1;
    int mid = s + (e-s)/2;
    int ans = 0;
    while(s <= e){
        mid = s + (e-s)/2;
    
        if(((long long)mid*mid == n)){
            return mid;
        }
        if((long long)mid*mid > n){
            e = mid-1 ; 
        }
        else{
            ans = mid;
            s = mid+1;
        }
    }
    return -1 ; 
}

double morePrecision(int n, int precision, int tempSol){
    
    double factor = 1;
    double ans = tempSol;

    for (int  i = 0; i < precision; i++)
    {
        factor = factor/10;
        for (double j = ans; j*j < n; j= j+factor)
        {
            ans =j;
        }
    }
    return ans;
}
int main()
{
   int ans = sqrtq(37);
   cout<<ans;
//    cout<<morePrecision(37,3,ans);
    return 0;
}