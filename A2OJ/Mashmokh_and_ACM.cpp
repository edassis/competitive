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

#define PRIME 1000000007

// value, pos
int a[2005];
int t[2005][2005];

int f(int last, int n, int k) {
    if (n <= 0) return 0;
    if (last + 1 > k) return 1;

    if (t[a[last]][last]) return t[a[last]][last];

    int ans = 0;
    int pre = a[last + 1];

    for (int x = a[last]; x <= n; x += a[last]) {
        a[last + 1] = x;
        ans = (ans + f(last + 1, n, k)) % PRIME;
    }
    a[last + 1] = pre;

    return t[a[last]][last] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    for(int i = 0; i < 2005; i++) a[i] = 1;
    memset(t, 0, sizeof(t));

    int ans = f(0, n, k);

    cout << ans << endl;

    return 0;
}