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

const int maxn = 2e5+2;

vi adj[maxn];
vi visitado(maxn);
deque<int> path, ans;
int l = 0;
int r = 0;
int greater = 0;

void dfs(int u) {
    if(visitado[u]) return;

    visitado[u] = 1;
    path.pb(u);
    


    for(auto v : adj[u]) {
        if(!visitado[v]) {
            dfs(v);
        }
    }

    path.pop_back();
}

int main() {
    sws();
    
    int n,m,k; cin >> n >> m >> k;

    vi w(n);

    forn(i,n) cin >> w[i];

    forn(i,m) {
        int a,b;
        cin >> a >> b;
        a--; b--;

        adj[a].pb(b);
    }

    return 0;
}
