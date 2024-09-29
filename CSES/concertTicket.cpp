#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    map<int,int> mp;
    for(int i=0; i<n; i++){
        int a; cin>>a;
        mp[a]++;
    }  
    for(int i=0; i<m; i++){
        int price ; cin>>price;
        auto it = mp.upper_bound(price);

        if(it == mp.begin()){
            cout<<-1<<endl;
        }
        else{
            it--;
            cout<<it->first<<endl;
            it->second -= 1;
            if(it->second == 0){
                mp.erase(it);
            }

        }
    }


    return 0;
}


