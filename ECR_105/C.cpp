#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vii vector<ii>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ii pair<int, int>
#define ff first
#define ss second

#define PRIME 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vi v(n + 1);
    vi custo(n + 1);

    vector<vi> g(n + 1);

    for (int i = 1; i <= n; i++) cin >> v[i];

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        g[x].eb(y);
        g[y].eb(x);
    }

    int ans = 0;

    vii nodes(n + 1);
    for (int i = 1; i <= n; i++) {
        nodes[i].ff = i;

        for (auto folha : g[i]) custo[i] += v[folha];

        nodes[i].ss = v[i] - custo[i];  // alivia se removido
    }

    for (int i = 1; i <= n; i++) {
        sort(nodes.begin(), nodes.end(), [](ii a, ii b) -> bool {
            a.ss < b.ss;
        });

        auto no = nodes.back();
        nodes.pop_back();

        ans += custo[no.ff];

        for (auto folha : g[no.ff]) {
            custo[folha] -= no.ss;
            nodes[folha].ss = v[folha] - custo[folha];
        }
    }

    cout << ans << endl;

    return 0;
}