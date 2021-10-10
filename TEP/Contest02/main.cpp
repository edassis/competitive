#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
    #define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << "\n";
#else
    #define W(x)
#endif

using namespace std;

// TYPES
#define vi vector<int>
#define vl vector<ll>
#define vpi vector<pii>
#define vpl vector<pl>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pl pair<ll, ll>
#define ff first
#define ss second
#define sws ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'

// FUNCTIONS
#define forn(i, n) for(int i=0; i<(int)n; i++)
#define forne(i, k, n) for(int i=k; i<=(int)n; i++)
#define Fo(i, k, n) for(auto i=k; k<n?i<n:i>n; k<n?i+=1:i-=1)
#define fora(a) for(auto each:a)
#define dbg(msg, var) cout << msg << " " << var << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define clr(x) memset(x, 0, sizeof(x))

const ll MOD = 1e9+7;
const ll oo = 1e18+7;

int main() {
    sws;

    int t; cin >> t;
    while(t--) {
        ll n, k; cin >> n >> k;
        vpl vt;
        forn(i, n) {
            int x; cin >> x;
            vt.eb(x, i+1);
        }

        sort(vt.begin(), vt.end(), [](pl a, pl b) {
            return a.ff < b.ff;
        });

        ll res = -oo;
        forn(i, n-1) {
            W((vt[i].ff|vt[i+1].ff));
            W(k*(vt[i].ff|vt[i+1].ff));
            W((vt[i].ss*vt[i+1].ss));
            res = max( res, vt[i].ss*vt[i+1].ss - k*(vt[i].ff|vt[i+1].ff) );
            W(res);
        }

        cout << res << endl;
    }
    return 0;
}