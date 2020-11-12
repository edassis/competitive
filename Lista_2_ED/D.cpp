#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

int main() {
    int n, r, m;
    vector<ii> ships;
    int dur = 1;

    cin >> n >> r >> m;

    for (int i = 0; i < n; i++) {
        int aux;
        cin >> aux;
        ships.pb(mp(aux, aux));
    }

    while (r > 0) {
        bool extracted = false;
        for (unsigned i = 0; i < ships.size(); i++) {
            if (ships[i].first == ships[i].second) {
                r -= m;
                ships[i].second = 0;
                extracted = true;
                if (r <= 0) {
                    break;
                }
            }
        }
        if (!extracted) {
            for (unsigned i = 0; i < ships.size(); i++) {
                ships[i].second++;
            }

            r++;
            dur++;
        }
    }

    cout << dur << endl;

    return 0;
}