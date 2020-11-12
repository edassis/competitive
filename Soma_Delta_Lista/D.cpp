#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int main() {
    int n, q;

    cin >> n >> q;
    vi v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vi delta(n);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;

        delta[l]++;
        if (r+1 < n) delta[r+1]--;
    }

    vector<pair<ll, ll>> prior(n);
    ll atual = 0;
    for (int i = 0; i < n; i++) {
        atual += delta[i];
        prior[i].first = atual;
        prior[i].second = i;
    }

    sort(v.begin(), v.end(), greater<int>());
    sort(prior.begin(), prior.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b) -> bool {
        return a.first > b.first;
    });

    vi v_final(n);
    for (int i = 0; i < n; i++) {
        v_final[prior[i].second] = v[i];
    }

    vector<ll> soma(n);
    for (int i = 0; i < n; i++) {
        soma[prior[i].second] = v_final[prior[i].second] * prior[i].first;
    }

    for (int i = 1; i < n; i++) {
        soma[i] += soma[i-1];
    }

    cout << soma[n - 1] << endl;

    return 0;
}