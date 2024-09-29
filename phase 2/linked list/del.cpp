#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int errorScore[n];
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        errorScore[i] = v;
    }
    int compP = 4;
    int compQ = 1;
    priority_queue<pair<int,int>> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push({errorScore[i],0});
    }

    int cnt = 0;
    int ans = 0;
    while (!pq.empty())
    {
        auto preC = pq.top().second;
        auto top = pq.top().first - (cnt-preC)*compQ;
        pq.pop();

        if(top>0){
            ans++;
            cnt++;
        }

        if (top - compP > 0)
        {
            pq.push({top - compP,cnt});
        }
    }
    cout<< ans;
    return 0;
}