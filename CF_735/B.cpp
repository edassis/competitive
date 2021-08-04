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

int main() {
    sws;

    int t; cin >> t;

    while(t--) {
        int n;
        ll k; 
        cin >> n >> k;

        vl v(n+1);
        for(int i = 1; i <= n; i++) cin >> v[i];
        
        ll res = -oo;
        for(int i = 1; i <= n-1; i++) {
            for(int j = i+1; j <= n; j++) {
                res = max(res, i*j - k * (v[i] | v[j]));
            }
        }

        cout << res << endl;
    }
    return 0;
}