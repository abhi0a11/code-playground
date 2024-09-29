#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n; 
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    multiset<int> st;
    long ans = 1;
    st.insert(arr[0]);
    for(auto i=1; i<n; i++){
        int cube = arr[i];
        auto it = st.upper_bound(cube);
        if(it == st.end()){
            st.insert(cube);
            ans++;
        }
        else{
            st.erase(it);
            st.insert(cube);
        }
    }
    cout<<ans;
    return 0;
}