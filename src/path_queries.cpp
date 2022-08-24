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
vi val(maxn);

struct ST {
    vi st;
    int size;
    int el_neutro;

    ST(int n, int el_neutro = 0) : st(4*n, el_neutro) {
        size = n;
        this->el_neutro = el_neutro;
    }

    int f(int a, int b) {
        return a+b;
    }

    int query(int l, int r) {
        return query(0,0,size-1,l,r);
    }

    void update(int i, int amm) {
        update(0,0,size-1,i,amm);
    }

private:
    int query(int sti, int stl, int str, int l, int r) {
        // fora
        if(stl > r or str < l) {
            return el_neutro;
        }

        // totalmente
        if(stl >= l and str <= r) {
            return st[sti];
        }

        int mid = (stl+str)/2;
        
        return f(query(sti*2+1, stl, mid, l, r), query(sti*2+2, mid+1, str, l, r));
    }

    void update(int sti, int stl, int str, int i, int amm) {
        // fora
        if(stl > i or str < i) {
            return;
        }

        // totalmente
        if(stl == i and str == i) {
            st[sti] += amm;
            return;
        }

        int mid = (stl+str)/2;

        update(sti*2+1,stl,mid,i,amm);
        update(sti*2+2,mid+1,str,i,amm);
        
        st[sti] = f(st[sti*2+1], st[sti*2+2]);
    }
};

vi tin(maxn), tout(maxn);
vi path(maxn);
int t = 0;
void dfs(int u, int p) {
    tin[u] = t++;
    path.pb(u);
    for(auto v : adj[u]) {
        if(v != p) {
            dfs(v, u);
        }
    }

    tout[u] = t-1;
}

int main() {
    sws();
    
    int n, q; cin >> n >> q;

    forn(i,n) cin >> val[i];

    forn(i,n-1) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        adj[a].pb(b);
        adj[b].pb(a);
    }
    
    dfs(0,0);
    ST st(n);

    forn(i,n) {
        st.update(tin[i], path[i]);
        st.update(tout[i]+1, -path[i]);
    }

    while(q--) {
        int typ; cin >> typ;

        if(typ == 1) {
            int s, x;
            cin >> s >> x;
            s--;

            int aux = st.query(tin[s], tout[s]) - x;
            // update s to x
            st.update(tin[s], aux);
        } else {
            int s;
            cin >> s;
            s--;

            // sum from r to s
            // cout << st.query(0, )
            // ? Como filtrar somente caminho
        }
    }
    return 0;
}
