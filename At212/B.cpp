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

ll fromString(string s) {
    ll res = 0;
    for (unsigned i = 0; i < s.size(); i++) {
        res = res * 10 + s[i];
    }

    return res;
}

int main() {
    sws;

    vi     v(4);
    string s;
    cin >> s;
    for (int i = 0; i < 4; i++) {
        v[i] = s[i] - '0';
    }

    string res  = "Weak";
    bool   equal = true, pa = true;
    for (int i = 1; i < 4; i++) {
        if (v[i - 1] != v[i]) {
            equal = false;
        }

        int prox = (v[i-1]+1) % 10;
        if (prox != v[i]) {
            pa = false;
        }
    }

    if(!equal && !pa) {
        cout << "Strong" << endl;
    } else {
        cout << "Weak" << endl;
    }

    return 0;
}