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
        int uc = u;
        int rc = r;
        int dc = d;
        int lc = l;

        int qtd = n - 2;
        bool found = false;
        for (int j = 0; j < 15; j++) {  // permutation 2^4
            found = false;
            u = uc; r = rc; d = dc; l = lc;

            if ((j & (1<<0)) && u && r) {
                // upper & right
                u--;
                r--;
            }
            if ((j & (1<<2)) && d && l) {
                // down & left
                d--;
                l--;
            }
            if ((j & (1<<3)) && l && u) {
                // left & upper
                l--;
                u--;
            }
            if ((j & (1<<1)) && r && d) {
                // right & down
                r--;
                d--;
            }

            if (qtd >= u && qtd >= r && qtd >= d && qtd >= l) {
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