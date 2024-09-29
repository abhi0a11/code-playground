#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    set<pair<int,int>> st;
    vector<pair<int,int>> arr;
    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        arr.push_back({a,b});
        st.insert({a,b});
    }    

    for(auto &&[a,b]:arr){
        auto it = st.upper_bound({a,b});
        
        if(it == st.end()){
            cout<< 0 <<" ";
        }
        else{
            int l = it->first;
            int h = it->second;

            if(a <= l && h <= b){
                cout<<1<<" ";
            }
            else cout<<0<<" ";
        }
    }cout<<endl;
    
    for(auto &&[a,b]:arr){
        auto it = st.lower_bound({a,b});

        // it--;
        if(it == st.begin()){
            cout<<0<<" ";
        }
        else{
            it--;
            // if(it == st.end()){
            //     cout<< 0 <<" ";
            // }
            // else{
                // int l = it->first;
                // int h = it->second;

                // if(l <= a && b <= h){
                //     cout<<1<<" ";
                // }
                // else cout<<0<<" ";
            // }
            cout<<it->first<<" "<<it->second<<endl;
        }
    }
    return 0;
}