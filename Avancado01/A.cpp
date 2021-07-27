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

int main() {
    sws;

    vi  a(3), b(3);
    int n;

    cin >> a[0] >> a[1] >> a[2];
    cin >> b[0] >> b[1] >> b[2];
    cin >> n;

    int pos  = 1;
    int posx = 0;

    for (int i = 0; i < 3; i++) {
        posx += a[i];

        while (posx > 5) {
            pos++;
            posx -= n;
        }
    }
    if(posx) {
        posx = 0;
        pos++;
    }

    for (int i = 0; i < 3; i++) {
        posx += b[i];

        while (posx > 10) {
            pos++;
            posx -= n;
        }
    }

    if (pos <= n) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    return 0;
}