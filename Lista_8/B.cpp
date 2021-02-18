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

int n, x;
vi moeda(15);
int tb[10000];

int dp(int p) {
    if (p == 0) {
        return 1;
    }

    if (tb[p] != -1) return tb[p];

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (p >= moeda[i]) {
            ans = (ans + dp(p - moeda[i])) % PRIMO;
        }
    }

    return tb[p] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(tb, -1, sizeof(tb));

    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        cin >> moeda[i];
    }    

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans + dp(x - moeda[i])) % PRIMO;
    }

    cout << ans << endl;

    return 0;
}