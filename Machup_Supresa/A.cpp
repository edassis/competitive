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
#define vl  vector<ll>
#define vll vector<lll>
#define ll  long long
#define pb  push_back
#define eb  emplace_back
#define mp  make_pair
#define mt  make_tuple
#define ii  pair<int, int>
#define lll pair<ll, ll>
#define ff  first
#define ss  second
#define sws                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define endl    '\n'
#define all(x)  x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define clr(x)  memset(x, 0, sizeof(x))

const ll prime = 1e9 + 7;
const ll oo    = 1e18 + 7;

int pot2(int a) {
    int res = 0;
    while (a / 2) {
        a /= 2;
        res++;
    }

    return res;
}

int main() {
    sws;

    int q;
    cin >> q;

    while (q--) {
        int n;
        cin >> n;

        vi dois(12);

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            if (x > 2048) continue;

            int pot = pot2(x);

            dois[pot]++;
        }

        int num = 0;
        for (int i = 11; i >= 0; i--) {
            num += pow(2, i) * dois[i];
            if (num >= 2048) break;
        }

        if (num >= 2048) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}

// 2048
// 1024 1024
// 512 512 512 512
// 256 256 256 256 256 256 256 256
// 128
// 64
// 32
// 16
// 8
// 4
// 2
// 1