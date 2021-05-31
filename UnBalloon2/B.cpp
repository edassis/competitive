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

    int n, m; cin >> n >> m;
    vector<vi> r(n, vi(3)), p(m, vi(3));
    
    for(int i = 0; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;

        r[i][0] = a;
        r[i][1] = b;
        r[i][2] = c;
    }

    for(int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;

        p[i][0] = a;
        p[i][1] = b;
        p[i][2] = c;
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int a, b, c;
            a = p[j][0]/r[i][0];
            b = p[j][1]/r[i][1];
            c = p[j][2]/r[i][2];

            int qtd = 0;
            if (a && b && c) {
                qtd = min({a, b, c});
            }
            res = max(res, qtd);
        }
    }

    cout << res << endl;
    
    return 0;
}