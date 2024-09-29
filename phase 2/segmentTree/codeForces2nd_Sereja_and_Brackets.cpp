
// problem
// xenia and bit operation code forces 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct info{
    int open, close, full;
    info(){
        open = 0;
        close = 0;
        full = 0;
    }
    info(int _open, int _close, int _full){
        open = _open;
        close = _close;
        full = _full;
    }
};
class segmentTree{
    vector<info*> seg;
public:
    segmentTree(int n){
        seg.resize(4*n+1,0);
    }

    info* merge(info* left, info* right){
        info* ans = new info(0,0,0);
        ans->full = left->full + right->full + min(left->open, right->close);
        ans->open = left->open + right->open - min(left->open, right->close);
        ans->close = left->close + right->close - min(left->open, right->close);
        return ans;
    }

    void build(int ind, int low, int high, string s){
        
        if(low == high){
            seg[ind] = new info(s[low] == '(' , s[low] == ')', 0);

            // seg[ind]->open = s[low] == '(';
            // seg[ind]->close = s[low] == ')';
            // seg[ind]->full =  0;
            return;
        }

        int mid = (low+high)>>1;
        build(2*ind+1, low, mid, s);
        build(2*ind+2, mid+1, high, s);
        seg[ind] = merge(seg[2*ind+1], seg[2*ind+2]);
    }
    info* query(int ind, int low, int high, int l, int r){
        if( r < low || high < l)    return new info();
        if(low >= l && high <= r){
            return seg[ind];
        }

        int mid = (low+high)>>1;

        info* left = query(2*ind+1, low, mid, l, r);
        info* right = query(2*ind+2, mid+1, high, l, r);

        return merge(left, right);
    }
};
int main(){
    string s;
    cin>>s;
    int q;
    cin>>q;
    int n = s.size();
    segmentTree st(n);
    st.build(0,0,n-1,s);

    while(q--){
        int l, r;
        cin>>l>>r;
        l--;r--;
        info* ans = st.query(0,0,n-1,l,r);
        cout<<ans->full<<endl;
    }
    return 0;
}