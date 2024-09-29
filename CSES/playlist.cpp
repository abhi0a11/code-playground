#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n;cin>>n;
    vector<long> playlist(n);
    for(int i=0; i<n; i++)  cin>>playlist[i];
 
    set<long> st;
    
    long i=0, j=0;
    long maxi = 0;
    while(i<n && j<n){   
        while(j<n && !st.count(playlist[j])){
            st.insert(playlist[j]);
            j++;
        }
        maxi = max(maxi, j-i);
 
        while(i<=j && playlist[i] != playlist[j]){
            st.erase(playlist[i]);
            i++;
        }
        if(playlist[i] == playlist[j]){
            st.erase(playlist[i]);
            i++;
        }  
    }
    cout<<maxi;
    return 0;
}