#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long getVal(long row, long col){
    long n = max(row,col)*2+1;
    long m = max(row,col)-1;
    
    long start = (m*(2*3 + (m-1)*2))/2 + 2;
    long end = start + n - 1;
    m++;
    long ans=0;
    if(m%2 == 0){ // increasing
        if(row>col){//row me h
            while(col){
                start++;
                col--;
            }
            ans = start;
        }
        else{// col me h
            while(row){
                end--;
                row--;
            }
            ans = end;
        }
    }
    else{ // decreasing
        if(row>col){//row me h
            while(col){
                end--;
                col--;
            }
            ans = end;
        }
        else{// col me h
            while(row){
                start++;
                row--;
            }
            ans = start;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    while(n--){
        long x,y;
        cin>>x>>y;
        if(x==1 && y==1)    cout<<1<<endl;
        else
            cout<<getVal(x-1,y-1)<<endl;       
    }            
    return 0;
}