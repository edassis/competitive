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
const ll maxn = 2e5+2;

vector<vi> adj(maxn);
int visitado[maxn];
bool cor[maxn];
vector<vi> grupo(2);

void bfsPinta(int u) {
    queue<int> q;

    clr(visitado);
    clr(cor);
    grupo[0].clear();
    grupo[1].clear();
    
    grupo[cor[u]].pb(u);    
    q.push(u);
    visitado[u] = 1;

    while(q.size()) {
        u = q.front(); q.pop();
        for (auto v : adj[u]) {
            if(!visitado[v]) {
                cor[v] = !cor[u];
                W(u);W(cor[v]); W(v);
                grupo[cor[v]].pb(v);
                q.push(v);
                visitado[v]=1;
            }
        }
    }
}

int main() {
    sws();

    int t; cin >> t;

    while(t--) {
        int n,m; cin >> n >> m;
        int s;  
        forn(i,m) {
            int a,b; cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
            if(!i) s = a;
        }

        bfsPinta(s);
        int sel = 0;
        if(grupo[1] < grupo[0]) sel = 1;

        cout << grupo[sel].size() << endl;
        forn(i,grupo[sel].size()) {
            cout << grupo[sel][i] << " \n"[i==grupo[sel].size()-1];
        }

        forn(i,maxn) adj[i].clear();
    }

    return 0;
}
