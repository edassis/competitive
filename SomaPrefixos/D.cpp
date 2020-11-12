#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int main() {
    int n, q;
    cin >> n;

    vi vet(n);  // prices
    for (int i = 0; i < n; i++) {
        cin >> vet[i];
    }

    sort(vet.begin(), vet.end());

    cin >> q;
    for (int i = 0; i < q; i++) {
        int coins;
        cin >> coins;

        int l = 0, r = n - 1;
        int res = -1;
        while (l <= r) {
            int mid = (l+r)/2;
            if (vet[mid] <= coins) {
                res = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        cout << res+1 << endl;
    }

    return 0;
}