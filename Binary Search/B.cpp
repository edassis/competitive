#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

int main() {
    int n, m;
    vi v;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int aux;
        cin >> aux;
        v.pb(aux);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < m; i++) {
        int req;

        cin >> req;

        int l = 0, r = n - 1;
        int res = -1;
        while (l <= r) {
            int mid = (l + r) / 2;

            if (v[mid] == req) {
                res = mid;
            }

            if (v[mid] >= req) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        if (res != -1)
            cout << res + 1 << ' ';
        else
            cout << res << ' ';
    }
    cout << endl;

    return 0;
}