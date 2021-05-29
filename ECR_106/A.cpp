#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" \
                  << "\n";
#else
#define W(x)
#endif

using namespace std;

#define vi  vector<int>
#define vii vector<ii>
#define vll vector<ll>
#define ll  long long
#define pb  push_back
#define eb  emplace_back
#define mp  make_pair
#define ii  pair<int, int>
#define ff  first
#define ss  second

#define prime 1e9 + 7

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k1, k2;
        cin >> n >> k1 >> k2;
        int w, b;
        cin >> w >> b;

        int kb1 = n - k1;
        int kb2 = n - k2;

        int answ = 0, ansb = 0;

        answ = k1 / 2;
        k2 += k1 % 2;
        answ += k2 / 2;

        ansb = kb1 / 2;
        kb2 += kb1 % 2;
        ansb += kb2 / 2;

        if (answ + ansb >= w + b) cout << "yes" << '\n';
        else
            cout << "no" << '\n';
    }

    return 0;
}