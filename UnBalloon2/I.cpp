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

double f(int n, int k) {
    if(n == 1 || n == 2) return 1;

    return (double)k * ( ceil(f(n-1, k)/2.0) + ceil(f(n-2, k)/2.0) );
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int res = f(n, 4) - f(n, 3);
    
    cout << res << endl;

    return 0;
}