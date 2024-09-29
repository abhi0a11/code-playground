#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;cin >> n;
    vector<vector<int>> arr;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arr.push_back({ a,b,i });
    }

    sort(arr.begin(), arr.end());
    vector<int> ans(n);
    set<pair<int, int>> occupiedRoom; //departure time , room;
    int room = 0;
    for (int i = 0; i < n; i++) {
        int arrTime = arr[i][0];
        int depTime = arr[i][1];
        int idx = arr[i][2];

        if (occupiedRoom.empty() || occupiedRoom.begin()->first >= arrTime) {
            room++;
            occupiedRoom.insert({ depTime,room });
            ans[idx] = room;
        }
        else {
            auto p = occupiedRoom.begin()->second;
            occupiedRoom.erase(occupiedRoom.begin());
            occupiedRoom.insert({ depTime,p });
            ans[idx] = p;
        }
    }
    cout << room << endl;
    for (auto i : ans) cout << i << " ";
    return 0;
}