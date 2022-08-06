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

string f(string s, int n) {
    vi ch(n);

    while(true) {
        int val = MOD;
        int pos = -1;
        forni(i,1,n) if(!ch[i-1]) {
            if(s[i] < s[i-1] && s[i] < val) {
                val = s[i];
                pos = i;
            }
            // 5 1 2 3
        }
        if(pos == -1) break;

        swap(s[pos-1], s[pos]);
        ch[pos-1] = 1;
    } 

    return s;
}

int main() {
    sws();

    int t; cin >> t;

    while(t--) {
        int n; cin >> n;

        vi els(n);
        forn(i,n) cin >> els[i];

        string s;
        forn(i,n) {
            while(els[i]) {
                s += els[i] % 10 + '0';
                els[i]/=10;
            }
            reverse(s.begin(), s.end());
            W(s);
        }

        s = f(s, n);
        forn(i,n) {
            cout << s[i] << " \n"[i == n-1];
        }
    }

    return 0;
}

// levar o i-th menor valor para as primeiras posicoes
// ate acabar as trocas ou, a troca nao ser vantajosa