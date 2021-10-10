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
#define fora(a) for(auto each:a)
#define dbg(msg, var) cout << msg << " " << var << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define clr(x) memset(x, 0, sizeof(x))

const ll MOD = 1e9+7;
const ll oo = 1e18+7;

const int MAX = 100001;

ll q(vl vt, ll m) {
    int res = 0;
    forn(i, vt.size()) {
        res += abs(vt[i]-m);
    }
    
    return res;
}

int main() {
    sws;

    int n; cin >> n;
    vl vt(n);
    forn(i,n) cin >> vt[i];

    sort(vt.begin(), vt.end());

    vl psoma(n);
    psoma[0] = vt[0];
    for(int i = 1; i < n; i++) {
        psoma[i] = psoma[i-1] + vt[i];
    }

    ll res = 0;
    for(int i = 0; i < n-2; i++) {
        res += psoma[n-2] - psoma[i];
    }
    res += psoma[n-1] - psoma[n-2];

    cout << res << endl;

    return 0;
}