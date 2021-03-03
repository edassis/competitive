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

vi merge(vi &a, vi &b, ll &swap) {
    unsigned i = 0, j = 0;
    vi c;

    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) {
            c.eb(a[i]);
            i++;
        } else {
            c.eb(b[j]);
            j++;
            swap += a.size() + j - c.size();
        }
    }

    while (i < a.size()) {
        c.eb(a[i++]);
    }

    while (j < b.size()) {
        c.eb(b[j++]);
    }

    return c;
}

vi mergesort(vi &a, ll &swap) {
    if (a.size() == 1) return a;

    vi l(a.begin(), a.begin() + (a.size() / 2));
    vi r(a.begin() + (a.size() / 2), a.end());

    l = mergesort(l, swap);
    r = mergesort(r, swap);

    a = merge(l, r, swap);

    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        vi a(n);

        for (int j = 0; j < n; j++) scanf("%d", &a[j]);

        ll swap = 0;
        a = mergesort(a, swap);

        printf("%lld\n", swap);
        
        // for (int j = 0; j < n; j++) printf("%d ", a[j]);
        // printf("\n");
    }

    return 0;
}