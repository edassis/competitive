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

// Constants
const ll MOD = 1e9 + 7;
const ll oo  = 1e18 + 7;

int f(vi ar, int n, int x) {

    vi psum(n);
    psum[0] = ar[0];
    forni(i,1,n) {
        psum[i] = psum[i-1] + ar[i];
    }

    vi ans;

    forn(l,n) {
        for(auto r = n-1; r >= l; r--) {
            auto sum = psum[r];
            if(l-1>=0) sum-=psum[l-1];
            
            W(sum);
            W(l); W(r);
            if(sum%x != 0) ans.pb(r-l+1);
        }
    }
    ans.pb(-1);
    sort(rall(ans));

    return ans[0];
}

int main() {
    sws();
    
    int t; cin >> t;

    while(t--) {
        int n,x; cin >> n >> x;

        vi ar(n);

        forn(i,n) cin >> ar[i];

        cout << f(ar,n,x) << endl;

    }

    return 0;
}
