#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ii pair<int, int>
#define ff first
#define ss second

#define PRIMO 1000000007

const ll oo = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int campo[n][m];
    ll d[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;

            if (c == '.') {
                campo[i][j] = 1;
            } else if (c == 'A') {
                campo[i][j] = 5;
            } else if (c == 'M') {
                campo[i][j] = -1;
            }

            d[i][j] = oo;
        }
    }

    pair<ll, pair<int, int>> p(0, {0, 0});
    priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>> > pq;
    pq.push(p);
    d[0][0] = 0;

    while (pq.size()) {
        p = pq.top();
        pq.pop();

        if (p.ff > d[p.ss.ff][p.ss.ss]) continue;

        if (p.ss.ff + 1 < n) {  // down
            if (campo[p.ss.ff + 1][p.ss.ss] != -1) {
                if (d[p.ss.ff + 1][p.ss.ss] > d[p.ss.ff][p.ss.ss] + campo[p.ss.ff][p.ss.ss]) {
                    d[p.ss.ff + 1][p.ss.ss] = d[p.ss.ff][p.ss.ss] + campo[p.ss.ff][p.ss.ss];
                    pq.emplace(d[p.ss.ff + 1][p.ss.ss], make_pair(p.ss.ff + 1, p.ss.ss));
                }
            }
        }

        if (p.ss.ss + 1 < m) {  // right
            if (campo[p.ss.ff][p.ss.ss + 1] != -1) {
                if (d[p.ss.ff][p.ss.ss + 1] > d[p.ss.ff][p.ss.ss] + campo[p.ss.ff][p.ss.ss]) {
                    d[p.ss.ff][p.ss.ss + 1] = d[p.ss.ff][p.ss.ss] + campo[p.ss.ff][p.ss.ss];
                    pq.emplace(d[p.ss.ff][p.ss.ss + 1], make_pair(p.ss.ff, p.ss.ss + 1));
                }
            }
        }
    }

    cout << d[n-1][m-1] << endl;

    return 0;
}