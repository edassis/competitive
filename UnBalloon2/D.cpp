#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
    #define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << "\n";
#else
    #define W(x)
#endif

using namespace std;

#define vi vector<int>
#define vii vector<ii>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ii pair<int,int>
#define ff first
#define ss second

#define prime 1e9+7

ll a[5001], tb[5001][5001];
int n = 5000;

ll f(int l, int r) {
    if(l == r) return a[l];
    if(tb[l][r]) return tb[l][r];

    ll custo = f(l+1, r);
    custo = min(custo, f(l, r-1));
    
    custo += a[l] + a[r];

    return tb[l][r] = custo;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(a, 0, sizeof(a));

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll custo = f(0, n-1);

    cout << custo << endl;

    return 0;
}