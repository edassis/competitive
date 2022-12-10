#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" \
                  << "\n";
#else
#define W(x)
#endif

using namespace std;

// Types
using ll  = long long;
using pii = pair<int, int>;
using pl  = pair<ll, ll>;
using vi  = vector<int>;
using vl  = vector<ll>;
using vpi = vector<pii>;
using vpl = vector<pl>;
template <typename T>
using V = vector<T>;

// Macros
#define pb             push_back
#define eb             emplace_back
#define mp             make_pair
#define mt             make_tuple
#define ff             first
#define ss             second
#define endl           '\n'
#define forn(i, n)     for (int i = 0; i < (int)n; i++)
#define forni(i, k, n) for (int i = k; i < (int)n; i++)
#define forne(i, k, n) for (int i = k; i <= (int)n; i++)
#define fora(e, a)     for (auto e : a)
#define dbg(msg, var)  cout << msg << " " << var << endl
#define all(x)         x.begin(), x.end()
#define rall(x)        x.rbegin(), x.rend()

// Functions
template <typename T>
inline void clr(T &x) { memset(x, 0, sizeof(x)); }
inline void sws() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
template <typename T>
ostream &operator<<(ostream &out, V<T> v) {
    forn(i, v.size()) {
        cout << v[i] << "\n"[i == v.size() - 1];
    }
    return out;
}
template <typename T>
istream &operator>>(istream &in, V<T> v) {
    int n = v.size();
    forn(i, n) in >> v[i];
    return in;
}

// Constants
const ll MOD  = 1e9 + 7;
const ll oo   = 1e18 + 7;
const ll maxn = 3e5 + 2;

vl  dp[maxn][2];
int n = 0;
int k = 0;

ll f(int i, int qtd, ll joy, vpi &songs) {
    if (i == n) return 0;
    if (qtd == k) return 0;

    ll joyt = min(joy, (ll)songs[i].ss);
    ll ans  = f(i + 1, qtd + 1, joyt, songs) + songs[i].ff * joyt;
    ans     = max(ans, f(i + 1, qtd, joy, songs));
    return ans;
}

int main() {
    sws();

    clr(dp);
    cin >> n >> k;

    vpi songs(n);

    forn(i, n) {
        int l, p;
        cin >> l >> p;
        songs.eb(l, p);
    }

    cout << f(0, 0, MOD, songs);

    return 0;
}
