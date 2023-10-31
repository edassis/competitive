#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>    // oset
// #include <ext/pb_ds/tree_policy.hpp>        // oset

// using namespace __gnu_pbds;                 // oset
using namespace std;

#ifndef ONLINE_JUDGE
    #define W(x) std::cerr << "\033[31m" << #x << " = " << x << "\033[0m" << "\n"
    #define dbg(msg, var) cout << msg << " " << var << endl
#else
    #define W(x)
    #define dbg(msg, var)
#endif
// Types
using ll = long long;
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pi>;
using vpl = vector<pl>;
template <typename T> using V = vector<T>;
// template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// Macros
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define FF first
#define SS second
#define endl '\n'
#define FOR(i, k, n) for(int i=k; (k<n)?(i<=(int)n):(i>=(int)n); (k<n)?i++:i--)
#define loop(i, n) for(int i=0; i<(int)n; i++)
#define loopi(i, k, n) for(int i=k; i<(int)n; i++)
#define loope(i, k, n) for(int i=k; i<=(int)n; i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
// Functions
template<typename T> inline void clr(T& x) { memset(x, 0, sizeof(x)); }
template <typename T> ostream &operator<<(ostream &out, const V<T> &v) { loop(i, v.size()) { out << v[i] << ' '; }; return out; }
template <typename T, typename Y> ostream &operator<<(ostream &out, const pair<T,Y> &v) { out << v.FF << ' ' << v.SS; return out; }
template <typename T> void print(const T &v) { cout << v << endl; }
template <typename T> void print(const V<T> &v, const int s, const int n) { loopi(i,s,n) { cout << v[i] << ' '; }; cout << endl; }
// Constants
const ll MOD = 1e7+2;
const ll oo = 1e9+7;
const ll maxn = 2e5+4;

int main() {
    fastio;

    // D: Road to Nutella
    // Se menor percurso (dijkstra) for dist impar, procurar par (vice-versa)
    // Ideia:
    // Achar todos os possíveis caminhos de A para B.
    //  DFS -> euler tour
    //  O que acontece se após o nó visitado tiver outro caminho válido?
    //  Como processar a qtd de nós que já foram visitados para ranquear os caminhos?

    return 0;
}
