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

class DSU {
    vi p;
    vi size;
public:
    DSU(int n) : p(n+1), size(n+1, 1) {
        iota(all(p), 0);
    }

    void insert(int a, int b) {
        // // vai para o pai
        a = query(a);
        b = query(b);

        // // Mesmo pai
        if(a == b) return;

        // // balancamento
        // if(size[a] > size[b]) {
        //     swap(a, b);
        // }

        // b maior
        size[b] += size[a];
        p[a] = b;
    }

    int query(int e) {
        // Compressão
        // return (e == p[e]) ? (e) : ( p[e] = query(p[e]) );
        return (e == p[e]) ? (e) : ( query(p[e]) );
    }

    bool same_set(int a, int b) {
        return query(a) == query(b);
    }
};

int main() {
    sws();

    int r, c, q;
    while(cin >> r >> c >> q, r != 0) {
        DSU dsu(r);

        forn(i, c) {
            int a, b; cin >> a >> b;
            dsu.insert(a, b);
        }
        // For each room in test case
        // print either it make a good challenge or not (Y/N)
    }

    return 0;
}