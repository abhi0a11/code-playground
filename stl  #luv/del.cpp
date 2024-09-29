#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void addNum(int val, vector<int>& one, vector<int>& zero){
    int i=0;
    while(val){
       if(val%2 == 1){
            one[i++]++;
        }
        else{
            zero[i++]++;
        }
        val/=2;
    }
}
void deleteNum(int val, vector<int>& one, vector<int>& zero){
    int i=0;
    while(val){
        if(val%2 == 1){
            one[i++]--;
        }
        else{
            zero[i++]--;
        }
        val/=2;
    }
}
int getNum(vector<int>& one, vector<int>& zero){
    int ans = 0;
    for(int i=0; i<32; i++){
        if(zero[i]==0 && one[i]>0){
            ans += pow(2,i);
        }
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    vector<int> one(32);
    vector<int> zero(32);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int t;
    cin>>t;

    int i=0,j=0;
    int mini = INT_MAX;
    while(j<n){
        addNum(arr[j],one,zero);
        while(i<=j && abs(getNum(one,zero) - t) >= mini){
            mini = min(mini, abs(getNum(one,zero)-t));
            deleteNum(arr[i],one,zero);
            i++;
        }
        mini = min(mini, abs(getNum(one,zero)-t));
        j++;
    }
    while(i<n){
        mini = min(mini, abs(getNum(one,zero)-t));
        deleteNum(arr[i],one,zero);
        i++;
    }
    cout<<mini;
}













// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;
// int solve(vector<int>& arr, int m, int house){
//     vector<int> vis(100);
//     for(int i=0; i<m; i++){
//         int mid = arr[i];
//         int s = mid-house;
//         int e = mid+house;
//         if(s < 0)   s = 0;
//         if(e>100)   e = 100;
//         for(int j = s; j<=e; j++){
//             vis[j] = 1;
//         }
//     }

//     int ans = 0;
//     for(auto i:vis){
//         if(i==1)    ans++;
//     }
//     return ans;
// }
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--){
//         int m,x,y;
//         cin>>m>>x>>y;
//         vector<int> arr(m);

//         for(int i=0; i<m; i++)  cin>>arr[i];
//         cout<<solve(arr,m,x*y);
//     }
//     return 0;
// }

/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int solve(vector<vector<char>>& v,vector<vector<int>>& med,int i, int j,int energy,int n,int m){
    if(i>= n || j>= m || (energy == 0 && med[i][j] == 0) || v[i][j] == '#') return 0;
    if(v[i][j] == 'T')  return 1;

    int right = solve(v,med,i,j+1,energy + med[i][j] - 1,n,m); 
    int down = solve(v,med, i+1, j,energy+med[i][j]-1,n,m);
    
    return right|down;
}
int main()
{
    int n,m;cin>>n>>m;
    vector<vector<char>> v(n,vector<char>(m));
    
    int sr,sc;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>v[i][j];
            if(v[i][j] == 'S'){
                sr = i;
                sc = j;
            }

        }
    }
    vector<vector<int>> med(n,vector<int> (m,0));
    int k, cin>>k;
    for(int i=0; i<k; i++){
        int r,c,cal;
        cin>>r>>c>>cal;
        med[r-1][c-1] = cal;
    }
    if(med[sr][sc] == 0)    cout<<0;
    else
        cout<<solve(v,med,sr,sc,0,n,m);
    return 0;
}

*/