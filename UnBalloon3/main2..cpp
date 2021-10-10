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
#define vpi vector<pii>
#define vpl vector<pl>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pl pair<ll, ll>
#define ff first
#define ss second
#define sws ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'

// FUNCTIONS
#define forn(i, n) for(int i=0; i<(int)n; i++)
#define forne(i, k, n) for(int i=k; i<=(int)n; i++)
#define fora(a) for(auto each:a)
#define dbg(msg, var) cout << msg << " " << var << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define clr(x) memset(x, 0, sizeof(x))

const ll MOD = 1e9+7;
const ll oo = 1e18+7;

const int MAX = 2002;
vi adj[MAX*MAX];
vector<bool> visitado(MAX*MAX, false);

int f(int x, int y, int n) {
    if(visitado[x+y*n]) return 0;

    visitado[x+y*n] = true;
    
    for(auto e : adj[u]) {
        f(x,);
    }
}

int main() {
    sws;

    int n; cin >> n;
    char mat[n+2][n+2];
    
    clr(mat);

    for(int i = 1; i < n+1; i++) {
        for(int j = 1; j < n+1; j++) { 
            cin >> mat[i][j];
        }
    }    
    
    int res[n+2][n+2];
    clr(res);

    for(int i = 1; i < n+1; i++) {
        for(int j = 1; j < n+1; j++) {
            if(mat[i][j] == 'B' && i==n) res[i][j] = 1;
            if(mat[i][j] == 'C' && i==1) res[i][j] = 1;
            if(mat[i][j] == 'D' && j==n) res[i][j] = 1;
            if(mat[i][j] == 'E' && j==1) res[i][j] = 1;
        }
    }

    for(int i = 1; i < n+1; i++) {
        for(int j = 1; j < n+1; j++) { 
            if(mat[i][j] == 'B') {
                adj[i+j*n].pb((i+1)+j);
            }
            if(mat[i][j] == 'C') {
                adj[i+j*n].pb((i-1)+j);
            }
            if(mat[i][j] == 'D') {
                adj[i+j*n].pb(i+(j+1)*n);
            }
            if(mat[i][j] == 'E') {
                adj[i+j*n].pb(i+(j-1)*n);
            }
        }
    }

    for(int i = 1; i < n+1; i++) {
        for(int j = 1; j < n+1; j++) { 
            f(i+j*n);
        }
    }

    for(int i = 1; i < n+1; i++) {
        for(int j = 1; j < n+1; j++) { 
            cout << res[i][j];
        }
    }
    cout << endl;

    return 0;
}