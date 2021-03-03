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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < q; i++) {
        int ans = -1;
        int value;
        cin >> value;

        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (a[mid] == value) {
                ans = mid;
                r = mid - 1;
            } else {
                if (a[mid] < value) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}