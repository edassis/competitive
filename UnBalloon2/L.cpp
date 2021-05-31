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

    int n; cin >> n;
    vii poli;
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        poli.eb(x, y);
    }

    double area = 0.0;
    for(int i = 1; i < n; i++) {
        double xi = (double)poli[i-1].ff;
        double yi = (double)poli[i-1].ss;
        double xf = (double)poli[i].ff;
        double yf = (double)poli[i].ss;

        double a1 = (xf-xi) * max(yi, yf);
        double a2 = (xf-xi) * abs(yf-yi);
        area += a1 - a2/2;
    }

    cout << fixed << area << endl;

    return 0;
}