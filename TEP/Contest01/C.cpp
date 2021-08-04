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

set<ll> primos;

void crivo(ll n) {
    vector<bool> candidato(n+1, true);

    for(ll i = 3; i <= n; i+=2) {
        if(candidato[i]) {
            primos.emplace(i);
            for(ll j = i+i; j <= n; j+=i) {
                candidato[j] = false;
            }
        }
    }
}

int main() {
    sws;

    crivo(1000005);
    
    ll n, m; cin >> n;

    m = 1;
    while(primos.count(n*m+1)) {
        m++;
    }
    
    cout << m << endl;

    return 0;
}