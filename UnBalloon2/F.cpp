#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" \
                  << "\n";
#else
#define W(x)
#endif

using namespace std;

#define vi  vector<int>
#define vii vector<ii>
#define vll vector<ll>
#define ll  long long
#define pb  push_back
#define eb  emplace_back
#define mp  make_pair
#define ii  pair<int, int>
#define ff  first
#define ss  second

#define prime 1e9 + 7

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;
    int tab[n + 2][n + 2];
    memset(tab, 0, sizeof(tab));

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        tab[x][y] = 1; // nave;
    }
    
    int res = 0;
    for (int i = 0; i < q; i++) {
        int x, y; cin >> x >> y;
        
        if(tab[x][y]) {
            tab[x][y] = 0;
            res++;
        }
        if(tab[x+1][y]) {
            tab[x+1][y] = 0;
            res++;
        }
        if(tab[x-1][y]) {
            tab[x-1][y] = 0;
            res++;
        }
        if(tab[x][y+1]) {
            tab[x][y+1] = 0;
            res++;
        }
        if(tab[x][y-1]) {
            tab[x][y-1] = 0;
            res++;
        }
    }
    
    cout << res << endl;

    return 0;
}