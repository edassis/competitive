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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a,b,c,d; cin >> a >> b >> c >> d;

    double res = 0.0;
    for (int i = 1; i <= a; i++) {
        int chance = max(0, i + b - d - 1);
        res += min(1.0, (double)chance/(double)c);
    }

    cout << res/(double)a << endl;

    return 0;
}