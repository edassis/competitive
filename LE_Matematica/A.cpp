#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

vector<ll> divisors(ll n) {
    vector<ll> ans;

    for (ll a = 1; a*a <= n; a++) {
        if (n%a == 0) {
            ll b = n / a;
            ans.pb(a);
            if (a!=b) ans.pb(b);
        }
    }
    // sort(ans.begin(), ans.end());

    return ans; 
}

vector<int> divisors_until_n(int n) {
    vi div(n,0);

    for (int x = 1; x <= n; x++) {
        for (int m = x; m <= n; m += x) {
            div[m]++;
        }
    }

    return div;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    scanf("%d", &q);

    vi all = divisors_until_n(1000000);
    
    for (int i = 0; i < q; i++) {
        int x;
        scanf("%d", &x);

        printf("%d\n", all[x]);
    }

    return 0;
}