#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define W(x)                                            \
    cerr << "\033[31m" << #x << " = " << x << "\033[0m" \
         << "\n";
#else
#define W(x)
#endif

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

#define prime 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vi ans;

        for (int i = k + 1; i <= n; i++) ans.eb(i);

        for (int i = k / 2 + 1; i <= k - 1; i++) ans.eb(i);

        if (k % 2) {
            // odd
        } else
            ans.eb(k / 2);

        cout << ans.size() << '\n';
        if (ans.size()) {
            for (auto e : ans) cout << e << ' ';
            cout << '\n';
        }
    }

    return 0;
}