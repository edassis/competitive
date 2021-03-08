#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vii vector<ii>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ii pair<int,int>
#define ff first
#define ss second

#define PRIMO 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    int n, u, r, d, l;

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> u >> r >> d >> l;

        bool found = false;
        for (int j = 0; j < 16; j++) {  // permutation 2^4
            found = false;
            int uc = u, rc = r, dc = d, lc = l;
            
            if (j & 1) {
                // upper & right
                uc--;
                rc--;
            }
            if (j & 2) {
                // right & down
                rc--;
                dc--;
            }
            if (j & 4) {
                // down & left
                dc--;
                lc--;
            }
            if (j & 8) {
                // left & upper
                lc--;
                uc--;
            }

            if (min({uc, rc, dc, lc}) >= 0 && max({uc, rc, dc, lc}) <= n - 2) {
                found = true;
                break;
            } 
        }

        if (found) {
            cout << "yes" << '\n';
        } else {
            cout << "no" << '\n';
        }
    }
    return 0;
}