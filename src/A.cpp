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

int f(int n) {
    int pot = 10000;
    for(int k = 4; k >= 0; k--) {
        for(int i = 9; i >= 1; i--) {
            int x = i * pot;
            if(x <= n) return x;
        }
        pot /=10;
    }

    return 1;
}

int main() {
    sws();

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vi ans;
        while(n) {
            int addend = f(n);
            n-=addend;
            ans.pb(addend);
        }

        cout << ans.size() << endl;
        forn(i,ans.size()) {
            cout << ans[i] << " \n"[i==ans.size()-1];
        }
    }

    return 0;
}