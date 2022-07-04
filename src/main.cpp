#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
    #define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << "\n";
#else
    #define W(x)
#endif

using namespace std;

// Types
using ll = long long;
using pii = pair<int,int>;
using pl = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pii>;
using vpl = vector<pl>;

// Macros
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define endl '\n'
#define forn(i, n) for(int i=0; i<(int)n; i++)
#define forni(i, k, n) for(int i=k; i<(int)n; i++)
#define forne(i, k, n) for(int i=k; i<=(int)n; i++)
#define fora(e, a) for(auto e:a)
#define dbg(msg, var) cout << msg << " " << var << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// Functions
template<typename T>
inline void clr(T& x) { memset(x, 0, sizeof(x)); }
inline void sws() { ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); }

// Constants
const ll MOD = 1e9+7;
const ll oo = 1e18+7;

const int N = 3e5+1;
vl w(N);
vpi adj[N];
int n=0;
ll ans=0;

ll f(int e, int p=0) {

    ll best = w[e];

    vl results;

    for(auto [c, v] : adj[e]) {
        if(v != p) {
            auto child = f(v, e)-c;
            results.pb(child);
            best = max(best, child+w[e]);
        }
    }

    sort(rall(results));

    ans = max(ans, best);
    if(results.size() >= 2) {
        ans = max(ans, results[0]+results[1]+w[e]);
    }

    return best;
}

int main() {
    sws();

    cin >> n;

    forn(i,n) {
        cin >> w[i];
    }

    forn(i, n-1) {
        int u, v, c; cin >> u >> v >> c;
        u--; v--;
        adj[u].eb(c, v);
        adj[v].eb(c, u);
    }
    
    f(0);

    cout << ans << endl;

    return 0;
}