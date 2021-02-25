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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // real drink = k(bottle) * l(millimiters)
    // total slices = c(limes) * d(qtd slice)
    // real salt = p;
    int n, k, l, c, d, p, nl, np;

    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    int toasts = 1e9;
    toasts = min(toasts, k * l / nl);
    toasts = min(toasts, c * d);
    toasts = min(toasts, p / np);

    toasts /= n;
    
    cout << toasts << endl;

    return 0;
}