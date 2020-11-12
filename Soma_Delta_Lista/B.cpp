#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<ll, ll>> setor(n, {0, 0});
    for (int i = 0; i < n; i++) {
        cin >> setor[i].first;
    }

    vector<pair<ll, ll>> delta(n, {0, 0});
    delta[0].first = setor[0].first;
    for (int i = 1; i < n; i++) {
        delta[i].first = setor[i].first - setor[i - 1].first;
    }

    for (int i = 0; i < m; i++) {
        int l, r, a;
        cin >> l >> r >> a;
        l--; r--;
        delta[l].first -= a;
        delta[l].second++;

        if (r + 1 < n) {
            delta[r + 1].first += a;
            delta[r + 1].second--;
        }
    }

    // pair<ll, ll> atual = {0, 0};
    setor[0].first = delta[0].first;
    setor[0].second = delta[0].second;
    for (int i = 1; i < n; i++) {
        // atual.first += delta[i].first;
        // atual.second += delta[i].second;

        setor[i].first = delta[i].first + setor[i - 1].first;
        setor[i].second = delta[i].second + setor[i - 1].second;
    }

    ll op = 0;
    for (int i = 0; i < n; i++) {
        if (setor[i].first > 0) op += setor[i].second;
    }

    cout << op << endl;

    return 0;
}