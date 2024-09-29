
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(int s, int e, int land, vector<pair<int,int>>& vis, long& left, long& right){
    sort(vis.begin(), vis.end());
    long l ,h;
    long temp = s-1;
    for(int i=0; i<vis.size(); i++){
        l = vis[i].first;
        h = vis[i].second;

        if(temp >= l && temp <= h){
            left= l-1;
            right = h+1;
            int j = i;
            while(i-1>=0 && vis[i-1].second >= left){
                i--;
                left = vis[i-1].first-1;
            }
            while(j+1 < vis.size() && vis[j+1].first >= right){
                j++;
                right = vis[j+1].second+1;
            }
            break;
        }
    }
    cout<<left<<" "<<right<<endl;
}
int main()
{       

    int l,n;
    cin>>l>>n;
    
    // vector<int> vis(l,0);
    vector<pair<int,int>> vis;
    for(int i=0; i<n; i++){
        int s,e;
        cin>>s>>e;
        long ans = 0;        

        if(s!=0)
            ans+=((e*(e+1))/2 - (s*(s-1))/2);
        else
            ans+=(e*(e+1))/2;
        vis.push_back({s,e});
        long left = -1, right = -1;
        solve(s,e,l,vis,left,right);
        if(left != -1){
            ans += left;
            vis.push_back({left,left});
        }
        if(right != -1){
            ans += right;
            vis.push_back({right,right});
        }
        cout<<ans<<endl;
    }
    return 0;
}