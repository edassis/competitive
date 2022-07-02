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
#define fora(a)        for (auto each : a)
#define all(x)         x.begin(), x.end()
#define rall(x)        x.rbegin(), x.rend()
#define clr(x)         memset(x, 0, sizeof(x))

// Functions
// template<typename T>
// inline void clr(T& x) { memset(x, 0, sizeof(x)); }
inline void sws() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

// Constants
const ll MOD = 1e9 + 7;
const ll oo  = 1e18 + 7;
const double PI  = acos(-1.0);
const double EPS{1e-6}; 

using inter = pair<int,int>;

int solve() {
    return 0;
}

ll f(ll n) {
    return n * (n-1) * (n-2) / 6;
}

int main() {
    sws();
    
    while(true) {
        int n; cin >> n;
        if(!n) break;    

        int idx = 0;
        double bigger = 0;

        forn(i, n) {
            double w, h; cin >> w >> h;
            
            // 2x2
            auto lmin = w/2;
            lmin = min(lmin, h/2);
            // W(lmin);
            if(lmin - EPS > bigger) {
                bigger = lmin;
                idx = i+1;
            }

            // sequencia na linha/coluna
            auto aux = max(w, h)/min(w, h);
            // W(aux);
            if(aux + EPS < 4) {
            } else {
                if(min(w, h) - EPS > bigger) {
                    bigger = min(w,h);
                    idx = i+1;
                }
            }
        }

        cout << idx << endl;
    }

    return 0;
}
