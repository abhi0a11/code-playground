
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class HashMap {

private:
    vector<list<pair<int, int>>> mp;

    const static int Size = 10000;
    const static int mult = 1e9 + 9;

    int hash(int key) {
        return (int)(((ll)key * (ll)mult) % Size);
    }
public:
    HashMap() {
        mp.resize(Size);
    }

    void Insert(int key, int value) {
        int h = hash(key);

        list<pair<int, int>>& l = mp[h];
        for (pair<int, int>& i : l) {
            if (i.first == key) {
                i.second = value;
                return;
            }
        }

        l.push_back(make_pair(key, value));
    }

    int get(int key) {

        int h = hash(key);
        if (mp[h].empty()) return -1;

        auto l = mp[h];

        for (auto& i : l) {
            if (i.first == key)
                return i.second;
        }
        return -1;
    }

    void Delete(int key) {

        int h = hash(key);
        list<pair<int, int>>& l = mp[h];

        list<pair<int, int>>::iterator i;
        for (i = l.begin(); i != l.end(); i++) {
            if (i->first == key) {
                l.erase(i);
                return;
            }
        }
    }
};

int main() {

    int n;
    cin >> n;
    HashMap m;
    for (int q = 0; q < n; q++) {

        int type;
        cin >> type;
        if (type == 1) {
            int key, value;
            cin >> key >> value;
            m.Insert(key, value);
        }
        else if (type == 2) {
            int key;
            cin >> key;
            cout << m.get(key) << endl;
        }
        else if (type == 3) {
            int key;
            cin >> key;
            m.Delete(key);
        }
    }
}