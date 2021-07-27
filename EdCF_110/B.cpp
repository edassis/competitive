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

vi fatores(int x) {
    int q = 2;
    vi ans;
    while(x >= q) {
        while(x / q) {
            x /= q;
        }
        ans.pb(q);
        q++;
    }

    return ans;
}

vector<ll> crivo(ll n) {
    // vector<ll> lp(n + 1, -1);
    vector<bool> ehprimo(n+1, true);
    vector<ll> primos;

    ehprimo[1] = false;
    primos.eb(2);
    primos.eb(3);
    for (ll i = 3; i <= n; i+=2) {
        // if (lp[i] == -1) {
        //     for (ll j = i; j <= n; j += i) {
        //         lp[j] = i;  // biggest prime divisor
        //     }
            // primos.pb(i);
        // }
        ehprimo[i+1] = false;
        if (ehprimo[i]) {
            primos.eb(i);

            for (int x = i+i; x <= n; x+=i) { 
                ehprimo[x] = false;
            }
        }
    }

    return primos;
}

int lsdiv(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return i;
        }
    }

    return n;
}

int main() {
    sws;

    int t; cin >> t;

    while(t--) {
        int n; cin >> n;
        vi a(n);
        map<int, int> fr;

        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            x = lsdiv(x);
            fr[x]++;
            a[i] = x;
        }
        
        sort(all(a), [](int e1, int e2) {
            return gcd(e1, 2) > 1;
        });

        int ans = 0;
        int qtd2 = fr[2];
        for(int i = 0; i < n-1; i++) {
            // if (gcd(a[i], 2) > 1) {
            //     ans += n-i-1;
            //     fr[a[i]]--;
            // }
            if (a[i] > 1 && fr[a[i]] >= 2) {
                if (a[i] == 2) {
                    ans += n - qtd2 - fr[i] - 1;
                    fr[a[i]]--;
                }
                else {
                    ans += fr[a[i]]--;
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}