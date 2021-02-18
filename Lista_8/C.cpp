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
 
int n;
ll tb[1000001];

int mymod(ll a, ll b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    if (a == 1) {
        return b;
    }
    if (b == 1) {
        return a;
    }
 
    int aux = mymod(a, b/2);
    
    if ((b & 1) == 0) {
        return (aux+aux) % PRIMO; 
    } else {
        return (aux + (aux+aux) % PRIMO) % PRIMO;
    }
}

int dp(int n) {
    if (n == 0) return 1;
    if (n == 1) return 0;
    if (tb[n] != -1) return tb[n];
 
    for (int i = 2; i <= n; i++) {
        tb[i] = (i-1) * ((tb[i-1] + tb[i-2]) % PRIMO) % PRIMO;
    } 
 
    return tb[n];
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(tb, -1, sizeof(tb));
    tb[0] = 1;
    tb[1] = 0;

    cin >> n;
 
    int ans = dp(n);
 
    cout << ans << endl;
    
    return 0;
}