#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxFreq(vector<int> arr){
    unordered_map<int,int> mp;
    unordered_map<int,int> freq;

    int maxi = INT_MIN;
    int mod=-1, idx = -1;
    for(int i=0; i<arr.size(); i++){
        if(mp.find(arr[i]) == mp.end()){
            mp[arr[i]] = i;
        }
        freq[arr[i]]++;
        maxi = max(maxi, freq[arr[i]]);
    }

    for(auto &[k,v]:freq){
        if(v == maxi){
            if(idx == -1){
                mod = k;
                idx = mp[k];
            }
            else if(idx > mp[k]){
                mod = k;
                idx = mp[k];
            }
        }
    }
    return mod;
}
int main(){
    vector<int> arr{10,4,5,2,4};
    cout<<maxFreq(arr);
    return 0;
}