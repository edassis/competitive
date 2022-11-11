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


struct Seg {
    vi           st;
    vi           lazy;
    vector<bool> has;
    int          n;
    int          el_neutro;

    Seg(int n, int el_neutro = 0) : st(4 * n, el_neutro), lazy(4 * n, el_neutro), has(4 * n, false) {
        this->el_neutro = el_neutro;
        this->n         = n;
    }

    int query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }

    void update(int i, int amm) {
        update(0, 0, n - 1, i, amm);
    }

    void update(int l, int r, int amm) {
        update(0, 0, n - 1, l, r, amm);
    }

  private:
    int query(int sti, int stl, int str, int l, int r) {
        propagate(sti, stl, str);
        // fora do range
        if (stl > r || str < l) {
            return el_neutro;
        }

        // totalmente
        if (stl >= l && str <= r) {
            return st[sti];
        }

        int mid = (stl + str) / 2;

        // parcialmente
        return f(query(sti * 2 + 1, stl, mid, l, r), query(sti * 2 + 2, mid + 1, str, l, r));
    }

    void update(int sti, int stl, int str, int i, int amm) {
        propagate(sti, stl, str);
        // fora do range
        if (stl > i or str < i) {
            return;
        }

        // totalmente
        if (stl == i and str == i) {
            st[sti] += amm;
            // W(st[sti]);
            return;
        }

        // parcialmente
        int mid = (stl + str) / 2;
        update(sti * 2 + 1, stl, mid, i, amm);
        update(sti * 2 + 2, mid + 1, str, i, amm);
        st[sti] = f(st[sti * 2 + 1], st[sti * 2 + 2]);
    }

    void update(int sti, int stl, int str, int l, int r, int amm) {
        if (stl > r or str < l) {
            return;
        }

        if (stl >= l and str <= r) {
            lazy[sti] = amm;
            has[sti]  = true;
            propagate(sti, stl, str);
            return;
        }

        int mid = (stl + str) / 2;
        update(sti * 2 + 1, stl, mid, l, r, amm);
        update(sti * 2 + 2, mid + 1, str, l, r, amm);
        st[sti] = f(st[sti * 2 + 1], st[sti * 2 + 2]);
    }

    void propagate(int sti, int stl, int str) {
        if (has[sti]) {
            st[sti] += lazy[sti] * (str - stl + 1);
            // W(stl); W(str); W(st[sti]);
            if (stl != str) {
                lazy[sti * 2 + 1] = lazy[sti];
                lazy[sti * 2 + 2] = lazy[sti];
                has[sti * 2 + 1]  = true;
                has[sti * 2 + 2]  = true;
            }
            has[sti] = false;
        }
    }

    int f(int a, int b) {
        return a + b;
    }
};

const int maxn = 2e5+2;
vi vals(maxn);
vi adj[maxn];
vi in(maxn), out(maxn);
int t = 0;
vi path(maxn);

void dfs(int u, int p, int val=0) {
    in[u] = t++; 
    
    val+=vals[u];
    path[u]=val;

    for(auto v : adj[u]) {
        if(v!=p) {
            dfs(v,u,val);
        }
    }
    
    out[u] = t-1; 
}


int main() {
    sws();
    
    int n,q;
    cin >> n >> q;
    
    // vi vals(n+1);
    forni(i,1,n+1) {
        cin >> vals[i];
    }

    forn(i,n-1) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }

    // construir seg
    dfs(1,1);
    Seg seg(n);
    forni(i,1,n+1) {
        // seg.update(in[i], path[i]);
        seg.update(in[i], path[i]);
        seg.update(out[i]+1, -path[i]);
        // seg.update(out[i]+1, -vals[i]);
        // seg.update(in[i], out[i], vals[i]);
        // seg.update(out[i]+1, -vals[i]);
        // W(i); W(in[i]);W(out[i]);W(vals[i]);
        // W(i);
        // W(seg.query(in[i],out[i]));
    }

    while(q--) {
        forni(i,1,n+1) {
            W(seg.query(in[i],in[i]));
        }

        int typ; cin >> typ;

        if(typ == 2) {
            //consulta
            int no;
            cin >> no;
            cout << seg.query(in[no],in[no]) << endl;
        } else {
            //altera
            int no, val;
            cin >> no >> val;
            val -= vals[no];
            W(val);
            // seg.update(in[no],out[no],val);
            seg.update(in[no],val);
            seg.update(out[no]+1, -val);
            // seg.update(in[no], val);
            // seg.update(out[no]+1,-val);
            // n sei quando a subarvore termina
            // usar euler tour
            // n estou aproveitando a estrutura da seg
        }
    }

    return 0;
}
