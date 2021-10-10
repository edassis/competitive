#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
    #define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << "\n";
#else
    #define W(x)
#endif

using namespace std;

// TYPES
#define vi vector<int>
#define vl vector<ll>
#define vpi vector<pi>
#define vpl vector<pl>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define pi pair<int,int>
#define pl pair<ll, ll>
#define F first
#define S second
#define sws ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'

// FUNCTIONS
#define fo(i, n) for(auto i=0; i<n; i++)
#define foe(i, n) for(auto i=0; i<=n; i++)
#define Fo(i, k, n) for(auto i=k; k<n?i<n:i>n; k<n?i+=1:i-=1)
#define Foe(i, k, n) for(auto i=k; k<n?i<=n:i>=n; k<n?i+=1:i-=1)
#define fora(a) for(auto each:a)
#define dbg(msg, var) cout << msg << " " << var << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define clr(x) memset(x, 0, sizeof(x))

const ll MOD = 1e9+7;
const ll oo = 1e18+7;

const int MAX = 1001;
int mat[MAX][MAX];
// vi g[MAX*MAX];
bool visitado[MAX][MAX];

void f(int x, int y) {
    if(x < 0 || x >= MAX) return;
    if(y < 0 || y >= MAX) return;

    if(visitado[x][y]) return;

    visitado[x][y] = true;

    if(!mat[x][y+1]) f(x, y+1);
    if(!mat[x-1][y+1]) f(x-1, y+1);

    if(!mat[x-1][y]) f(x-1, y);
    if(!mat[x-1][y-1]) f(x-1, y-1);

    if(!mat[x][y-1]) f(x, y-1);
    if(!mat[x+1][y-1]) f(x+1, y-1);

    if(!mat[x+1][y]) f(x+1, y);
    if(!mat[x+1][y+1]) f(x+1, y+1);
}

int main() {
    sws;

    clr(mat);
    clr(visitado);

    int n; cin >> n;
    pi a,b,c;
    cin >> a.F >> a.S;
    cin >> b.F >> b.S;
    cin >> c.F >> c.S;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == b.F) mat[i][j] = 1;
            if(j == b.S) mat[i][j] = 1;

            int d = abs(i - b.F);
            if(abs(i) == abs(b.F)+d && abs(j) == abs(b.S)+d) mat[i][j] = 1;
        }
    }

    f(a.F, a.S);

    if(visitado[c.F][c.S]) cout << "yes" << endl;
    else cout << "no" << endl;

    return 0;
}