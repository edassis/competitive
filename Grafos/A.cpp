#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ii pair<int, int>

#define PRIMO 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<int> validos;
    validos.emplace(1);
    
    int c, v;
    cin >> c >> v;
    vector<ii> pos;

    for (int i = 0; i < v; i++) {
        int c1, c2, temp;
        cin >> c1 >> c2 >> temp;

        if (temp >= 0) {
            if (validos.count(c1)) {
                validos.emplace(c2);
            } else if (validos.count(c2)) {
                validos.emplace(c1);
            } else {
                pos.emplace_back(make_pair(c1, c2));
            }
        }
    }

    while (pos.size()) {
        if (validos.count(pos.back().first)) {
            validos.emplace(pos.back().second);
        } else if (validos.count(pos.back().second)) {
            validos.emplace(pos.back().first);
        }
        
        pos.pop_back();
    }

    cout << c - validos.size() << endl;

    return 0;
}