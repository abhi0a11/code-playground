#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n;cin>>n;
    set<int> st;
    for(int i=1; i<=n; i++){
        st.insert(i);
    }
    auto top = 1;
    while(!st.empty()){
        auto it = st.upper_bound(top);
 
        if(it == st.end()){
            it = st.begin();
        }
        cout<<*it<<" ";
        it++;
        if(it == st.end()){
            top = *st.begin();
        }
        else top = *(it);
        it--;
        st.erase(it);
    }
    return 0;
}