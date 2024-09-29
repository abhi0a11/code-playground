#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m; cin>>n>>m;
    vector<int> arr(m);
    for(int i=0; i<m; i++){
        cin>>arr[i];
    }  

    set<pair<int,int>> st;
    multiset<int> max_range;
    st.insert({0,n});
    max_range.insert(n);

    for(int i=0; i<m; i++){
        int pos = arr[i];
        auto it = st.upper_bound({pos,0});
        it--;
        int s = it->first, e = it->second;
        st.erase(it);
        st.insert({s,pos});
        st.insert({pos,e});

        max_range.erase(max_range.find(e-s));
        max_range.insert(pos-s);
        max_range.insert(e-pos);

        cout<<*max_range.rbegin()<<" ";
    }
    return 0;
}