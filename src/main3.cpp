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

int f(vi ar, int n, int x) {

    vi psum(n);
    psum[0] = ar[0];
    forni(i, 1, n) {
        psum[i] = psum[i - 1] + ar[i];
    }

    vi ans;

    forn(l, n) {
        for (auto r = n - 1; r >= l; r--) {
            auto sum = psum[r];
            if (l - 1 >= 0) sum -= psum[l - 1];

            W(sum);
            W(l);
            W(r);
            if (sum % x != 0) ans.pb(r - l + 1);
        }
    }
    ans.pb(-1);
    sort(rall(ans));

    return ans[0];
}

int solve(string inp) {
    int a[]{8, 6, 4, 2, 0};

    int sz = inp.size();

    int ans = -1;
    forn(i,sz) {
        if(inp[i] == '0' or inp[i] == '8') {
            ans = inp[i]-'0';
        }
    }

    if(ans==-1 and sz >= 2) {
        pii tmp;
        // for(auto i = sz-1; i; i--) if(tmp.ss == -1) {
        //     forn(j, size(a)) {
        //         int x = inp[i]-'0';
        //         if(x == a[j]) {
        //             tmp.ss = x;
        //             break;
        //         }
        //     }
        // }
        //
        // for(auto i = sz-1; i; i--) if(tmp.ff == -1) {
        //     int x = inp[i]-'0';
        //     int num = x*10+tmp.ss;
        //
        //     if(num % 8 == 0) {
        //         tmp.ff = x;
        //         ans = num;
        //         break;
        //     }
        // }
        forn(i,sz) {
            forni(j,i+1,sz) {
                int num = (inp[i]-'0')*10+(inp[j]-'0');
                W(num);
                if(num%8==0) {
                    ans = num;
                    break;
                }
            }
        }
    }

    return ans;
}

int main() {
    sws();

    string inp;
    cin >> inp;

    // int n = (inp[inp.size() - 2] - '0') * 10 + (inp[inp.size() - 1] - '0');
    
    auto ans = solve(inp);
    W(ans);
    if(ans == -1) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        cout << ans << endl;
    }

    return 0;
}

// 3454
// 0002
// 3458
//
// recursao escolhendo qual tira?
//
// numeros com 1 digito: 0 8
// ou
// qualquer multiplo de 8, preciso somente dos 2 ultimos digitos para saber
// - essa ideia seria para o 4.
