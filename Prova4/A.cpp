#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ii pair<int,int>
#define ff first
#define ss second

#define PRIMO 1000000007

ll n;
ll tb[1000001];

ll dp(ll n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 1;
    if (tb[n] != -1) return tb[n];

    return tb[n] = (((dp(n-1) + dp(n-2)) % PRIMO) + dp(n-3)) % PRIMO;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(tb, -1, sizeof(tb));
    tb[0] = 0;
    tb[1] = 1;
    tb[2] = 1;
    
    cin >> n;
 
    ll ans = dp(n);
 
    cout << ans << endl;
    
    return 0;
}