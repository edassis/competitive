#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
    #define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << "\n";
#else
    #define W(x)
#endif

using namespace std;

#define vi vector<int>
#define vii vector<ii>
#define vl vector<ll>
#define vll vector<lll>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define ii pair<int,int>
#define lll pair<ll, ll>
#define ff first
#define ss second
#define sws ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define clr(x) memset(x, 0, sizeof(x))

const ll prime = 1e9+7;
const ll oo = 1e18+7;

ll intsqrt(ll x) {
    // W("x: " + to_string(x));
    ll res = 0;
    for (ll i = 1; i*i <= x; i++) {
        res = i;
    }
    if(res*res < x) res++;
    // W("res: " + to_string(res));
    
    return res;
}

int main() {
    sws;

    int n, d;
    
    cin >> n >> d;

    int count = 0;
    for(int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;

        double dst = sqrt(x*x + y*y);
        // W("dst: " + to_string(dst));
        if(dst <= d) count++;
    }

    cout << count << endl;

    return 0;
}