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

    ll n, m;
    cin >> n >> m;

    priority_queue<pair<ll, int> , vector<pair<ll, int>>, greater<pair<ll, int>> > pq;
    vector<ll> d(100001, 1e18);
    d[n] = 0;

    pq.emplace(d[n], n);
    ll dt;
    ll u;
    while (pq.size()) {
        tie(dt, u) = pq.top();
        pq.pop();

        if (dt > d[u]) continue;

        if (u * 2 <= 100000) {
            if (d[u * 2] > d[u] + 1) {
                d[u * 2] = d[u] + 1;
                pq.emplace(d[u * 2], u * 2);
            }
        }

        if (u-1 >= 1) {
            if (d[u-1] > d[u] + 1) {
                d[u-1] = d[u] + 1;
                pq.emplace(d[u-1], u-1);
            }
        }
    }

    cout << d[m] << endl;
    return 0;
}