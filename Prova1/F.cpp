#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>


int main() {
    int n;

    cin >> n;
    vector<ll> vessels(n);
    ll last_empty_vessel = n - 1;
    // vector<bool> mask(n, false);
    vector<ll> cap(n);

    for (int i = 0; i < n; i++) {
        cin >> cap[i];
    }

    int m;
    cin >> m;

    vector<pair<ll, ll>> alt;
    for (int i = 0; i < m; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int p, x;
            cin >> p >> x;
            p--;

            alt.push_back({p, x});
        } else if (op == 2) {
            int k;
            cin >> k;
            k--;

            if (!alt.empty()) {
                sort(alt.begin(), alt.end(), [](const pair<ll,ll> &a, const pair<ll,ll> &b) -> bool {
                    return a.first < b.first;
                });
                
                int counter = 0;
                for (auto it = alt.begin(); it != alt.end(); it++) {
                    if (it->first > k) break;
                    
                    vessels[it->first] += it->second;
                    
                    counter++;
                }

                pair<ll,ll> water = alt.front();

                water.second = vessels[water.first] - cap[water.first];  // overflow
                while (water.second > 0 && water.first <= last_empty_vessel) {
                    vessels[water.first] = cap[water.first];
                    
                    if (water.first == last_empty_vessel) {
                        last_empty_vessel--;
                    }
                    if (water.first + 1 < n) {
                        vessels[water.first + 1] += water.second;
                        water.second = vessels[water.first + 1] - cap[water.first + 1];     // overflow
                    } 
                    water.first++;
                }
                alt.erase(alt.begin(), alt.begin()+counter);
            }

            cout << vessels[k] << endl;
        }
    }

    return 0;
}