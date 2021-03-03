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

#define PRIMO 1000000007

ll insertion_sort(vi &a, int len) {
    ll ans = 0;

    for (int i = 1; i < len; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
            ans++;
        }
        a[j + 1] = key;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    vi a(1e5);
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        scanf("%d", &n);

        for (int j = 0; j < n; j++) scanf("%d", &a[j]);

        ll swap = insertion_sort(a, n);

        printf("%lld\n", swap);
    }

    return 0;
}