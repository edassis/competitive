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

const int MAXN = int(1e5+4);
// 0 - red, 1 - black
vector<pii> adj[MAXN];
bool visited[MAXN];
int n, k;

// bfs, procurar caminho com black ate de profundidade k
int bfs(int s, int p, int lv) {
    // visited[s] = true;

    for(auto [v, c] : adj[s]) {
        if(v != p) {

        }
    }

}

int main() {
    sws();

    // int n,k;
    cin >> n >> k;

    forn(i, n-1) {
        int u,v,x;
        cin >> u >> v >> x;
        u--; v--;

        adj[u].eb(v, x);
        adj[v].eb(u, x);
    }

    int ans = 0;
    forn(i, n) {
        clr(visited);
        ans += bfs(i, i, 1);
    }

    cout << ans << endl;

    return 0;
}