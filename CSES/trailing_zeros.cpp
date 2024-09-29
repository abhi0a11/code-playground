#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    long n;
    cin>>n;
    long two = 0;
    long five = 0;
    
    for(int i=2; (n/i)>=1; i*=2){
        two += n/i;
    }
    for(int i=5; (n/i)>=1; i*=5){
        five += n/i;
    }

    if(two>five){
        cout<<five<<endl;
    }
    else{
        cout<<two<<endl;
    }
    return 0;
}