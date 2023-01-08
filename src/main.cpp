#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>    // oset
// #include <ext/pb_ds/tree_policy.hpp>        // oset

// using namespace __gnu_pbds;                 // oset
using namespace std;

#ifndef ONLINE_JUDGE
    #define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << "\n";
#else
    #define W(x)
#endif

// Types
using ll = long long;
using pii = pair<int,int>;
using pl = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pii>;
using vpl = vector<pl>;
template <typename T>
using V = vector<T>;
// template<typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Macros
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define endl '\n'
#define loop(i, n) for(int i=0; i<(int)n; i++)
#define loopi(i, k, n) for(int i=k; i<(int)n; i++)
#define loope(i, k, n) for(int i=k; i<=(int)n; i++)
#define dbg(msg, var) cout << msg << " " << var << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

// Functions
template<typename T>
inline void clr(T& x) { memset(x, 0, sizeof(x)); }
inline void sws() { ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); }
template <typename T>
ostream &operator<<(ostream &out, const V<T> &v) {
   loop(i, v.size()) {
       out << v[i] << ' ';
   }
   return out;
}
template <typename T, typename Y>
ostream &operator<<(ostream &out, const pair<T,Y> &v) {
   out << '(' << v.ff << ";" << v.ss << ")";
   return out;
}
template <typename T>
istream &operator>>(istream &in, V<T> &v) {
   loop(i, sz(v)) in >> v[i];
   return in;
}
template <typename T>
void print(const T &v) {
    cout << v << endl;
}
template <typename T>
void print(const V<T> &v, const int s, const int n) {
    loopi(i,s,n) {
        cout << v[i] << ' ';
    }
    cout << endl;
}

// Constants
const ll MOD = 1e9+7;
const ll oo = LLONG_MAX;
const ll maxn = 3e3+2;

ll n,x;
vl a(maxn);

ll dp[maxn][2];
ll kadane(int i, bool t) {
    if(i == 0) return t ? a[i] : a[i]*x;
    if(dp[i][t] > -oo) return dp[i][t];
    
    ll pega = -oo;
    ll npega = -oo;
    if(t == 0) {
        pega = max(a[i]*x, a[i]*x + kadane(i-1,1));
    }
    npega = a[i] + kadane(i-1,t);
    
    return dp[i][t] = max(pega, npega);
}

int main() {
    fastio;

    cin >> n >> x;
    loop(i,n) cin >> a[i];

    ll ans = -oo;
    loop(i,n) {
        loop(i,maxn) loop(j,2) dp[i][j] = -oo;
        ans = max(ans, kadane(i,0));
    }

    print(ans);

    return 0;
}

// f(n)
//
// f(n, 0) = max(a[i], a[i] + f(n-1))
// f(n, 1) = max(a[i]*x, a[i]*x + f(n-1, 1))
