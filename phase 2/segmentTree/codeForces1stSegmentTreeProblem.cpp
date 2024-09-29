
// problem
// xenia and bit operation code forces 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class segmentTree{
    vector<int> seg;
public:
    segmentTree(int n){
        seg.resize(4*n+1);
    }

    void build(int ind,int low, int high,int arr[], int orr){
        if(low == high){
            seg[ind] = arr[low];
            return;
        }

        int mid = (low+high)/2;
        build(2*ind+1, low, mid, arr, !orr);
        build(2*ind+2, mid+1, high, arr, !orr);

        if(orr) seg[ind] = seg[2*ind+1] | seg[2*ind+2];
        else seg[ind] = seg[2*ind+1] ^ seg[2*ind+2];
    }

    int query(int ind, int low, int high, int l, int r){
        // no overlap
        // l r low high or low high l r
        if(r < low || high < l) return INT_MAX;

        // complete ovrlap
        // [l low high r]

        if(low >= l && high <= r)   return seg[ind];

        int mid = (low+high) >> 1;
        int left = query(2*ind+1, low, mid, l, r);
        int right = query(2*ind+2, mid+1, high, l, r);
        return min(left,right);
    }

    void update(int ind, int low, int high, int i, int val, int orr){
        if(low == high){
            seg[ind] = val;
            return;
        }

        int mid = (low + high) >> 1;
        if(i<=mid) update(2*ind+1, low, mid, i, val,!orr);
        else    update(2*ind+2, mid+1, high,i,val,!orr);

        if(orr) seg[ind] = seg[2*ind+1] | seg[2*ind+2];
        else seg[ind] = seg[2*ind+1] ^ seg[2*ind+2];
    }

    int getSeg(int ind){
        return seg[ind];
    }
};
int main(){
    int n , q;
    cin>>n>>q;
    int el = pow(2,n);

    int arr[el];
    for(int i=0; i<el ; i++)    cin>>arr[i];

    segmentTree st(el);

    if(n%2 == 0)   st.build(0,0,el-1,arr,0);   
    else   st.build(0,0,el-1,arr,1);   

    while(q--){
        int i, val;
        cin>>i>>val;
        q--;

        if(n%2 == 0)    st.update(0,0,el-1,i,val,0);
        else    st.update(0,0,el-1,i,val,1);

        cout<<st.getSeg(0);
    }
    return 0;
}