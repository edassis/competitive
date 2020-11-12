#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ii pair<int,int>

#define PRIMO 1000000007

vll crivo(int n) {
    vector<bool> ehprimo(n + 1, true);
    vll ans;

    ans.eb(2);
    ehprimo[0] = false;
    ehprimo[1] = false;

    for (ll x = 3; x <= n; x += 2) {
        ehprimo[x + 1] = false;
        if (ehprimo[x]) {
            ans.eb(x);

            for (ll i = x + x; i <= n; i += x) {
                ehprimo[i] = false;
            }
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin >> m;

    vll primos = crivo(m);
    
    vll nums;

    for (unsigned i = 0; i < primos.size(); i++) {
        for (unsigned j = i+1; j < primos.size(); j++) {
            ll n = primos[i] * primos[j];
            
            if (n <= m) nums.eb(n);
            else break;
        }
    }

    cout << nums.size() << endl;

    return 0;
}