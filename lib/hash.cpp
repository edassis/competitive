#include <bits/stdc++.h>

using namespace std;

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
// Macros
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
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
const ll MOD = 1e7+2;
const ll oo = 1e9+7;
const ll maxn = 2e5+4;

ll add(ll a, ll b, ll mod) {
  return (a+b)%mod;
}
 
ll sub(ll a, ll b, ll mod) {
  return ((a-b)%mod + mod)%mod;
}
 
ll mul(ll a, ll b, ll mod) {
  return (a*b)%mod;
}

ll fexp(ll b, ll e, ll mod) {
  if(e == 0) return 1;
  ll x = fexp(b, e/2, mod);
  x = mul(x, x, mod);
  if(e%2) x = mul(x, b, mod);

  return x;
}

const vector<ll> mods = {
        1000015187, 1000027957//, 1000041323
    // (ll)1e9+7, (ll)1e9+9
};
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count()); // random number
const ll base = uniform_int_distribution<int>(356, mods[0]-1)(rng); // alphabet < base < mod1
// const ll base = 31;
 
struct hash_string{
    string s;
    ll n;
    vector<vector<int>> hashes, power, inv;

    hash_string(): n(0){}
    hash_string(string _s)
        : n(_s.size()), s(_s), 
        hashes(mods.size(),vector<int>(n)), 
        power(mods.size(),vector<int>(n)),
        inv(mods.size(),vector<int>(n))
        {
        for(int i=0; i<mods.size(); i++){
            power[i][0] = 1, inv[i][0] = 1;
            for(int j=1; j<n; j++){
                power[i][j] = mul(power[i][j-1], base, mods[i]);
            }
            inv[i][n-1] = fexp(power[i][n-1], mods[i]-2, mods[i]);
            for(int j=n-2; j>=0; j--){
                // inv[i][j] = fexp(power[i][j], mods[i]-2, mods[i]);
                inv[i][j] = mul(inv[i][j+1], base, mods[i]);
            }
            hashes[i][0] = (int)(s[0]-'A'+1);
            for(int j=1; j<n; j++){
                hashes[i][j] = add(hashes[i][j-1], mul(power[i][j], (int)(s[j]-'A'+1), mods[i]), mods[i]);
            }
        }
    }
    // return vector of hashes [l, r]
    vector<int> query(int l, int r){
        vector<int> get_hashes;
        for(int i=0; i<mods.size(); i++){
            // hashes[r] - hashes[l-1]
            int res = hashes[i][r];
            if(l > 0) res = sub(res, hashes[i][l-1], mods[i]);
            res = mul(res, inv[i][l], mods[i]);
            get_hashes.pb(res);
        }
        return get_hashes;
    }

    vector<int> update(int idx, int c){
        vector<int> get_hashes;
        for(int i=0; i<mods.size(); i++){
            int h = hashes[i][n-1];
            int m = mul((int)s[idx], power[i][idx], mods[i]);
            h = sub(h, m, mods[i]);
            m = mul(c, power[i][idx], mods[i]);
            h = add(h, m, mods[i]);
            get_hashes.pb(h);
        }
        return get_hashes;
    }
};

int32_t main(){ 
    fastio;

    string a; cin >> a;
    int n = sz(a);
    
    hash_string hs(a);

    return 0;
}

