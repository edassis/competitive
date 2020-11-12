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

bool ordena(ii a, ii b) {
    return a.first > b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<ii> caixas(n);
    for (int i = 0; i < n; i++) {
        cin >> caixas[i].first;
        cin >> caixas[i].second;
    }

    // sort(caixas.begin(), caixas.end(), ordena);

    vector<ii> ans_pos;
    int last_value = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((caixas[i].first + caixas[j].first) % m == 0) {
                if (last_value) {
                    if (last_value < caixas[i].first + caixas[j].first) {
                        ans_pos.clear();

                        last_value = caixas[i].first + caixas[j].first;
                        ans_pos.pb({i, j});

                    } else if (last_value == caixas[i].first + caixas[j].first) {
                        last_value = caixas[i].first + caixas[j].first;
                        ans_pos.pb({i, j});
                    }
                } else {
                    last_value = caixas[i].first + caixas[j].first;
                    ans_pos.pb({i, j});
                }
            }
        }
    }

    if (ans_pos.empty()) {
        cout << -1 << endl;
        return 0;
    }

    ii menor = ans_pos.front();
    for (unsigned i = 1; i < ans_pos.size(); i++) {
        if (caixas[ans_pos[i].first].second + caixas[ans_pos[i].second].second < caixas[menor.first].second + caixas[menor.second].second) {
            menor = ans_pos[i];
        }
    }

    cout << menor.first + 1 << ' ' << menor.second + 1 << endl;

    return 0;
}