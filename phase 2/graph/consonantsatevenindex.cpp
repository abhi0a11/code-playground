#include<bits/stdc++.h>
using namespace std;
int solve(int &x, int& y){
    x = x+1;
    y = y+2;
    return x+y;
}
int main(){
    int a = 3;
    cout<<solve(a,a);
    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     string s;cin>>s;
//     int n = s.size();
//     vector<int> pref(n,0);
//     pref[0] = s[0] == 'b';
//     for(int i=1; i<n; i++){
//         pref[i] = pref[i-1] + (s[i] == 'b');
//     }   

//     int ans = pref[n-1];
//     for(int i=0; i<n; i++){
//         if(s[i] == 'a'){
//             ans = min( ans, pref[i] + (n-i-1 - (pref[n-1] - pref[i])));
//         }
//     }
//     cout<<ans<<endl;
//     return 0;
// }