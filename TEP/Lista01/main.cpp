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
#define forne(i, k, n) for(int i=k; i<(int)n; i++)
#define fora(a) for(auto each:a)
#define dbg(msg, var) cout << msg << " " << var << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define clr(x) memset(x, 0, sizeof(x))

const ll MOD = 1e9+7;
const ll oo = 1e18+7;

int main() {
    sws;

    int n = 3;
    vector<string> res_pool { "first", "second", "illegal", "the first player won", "the second player won", "draw" };
    string res = res_pool[0];
    char grid[n+4][n+4];
    int qtdX = 0, qtdO = 0;

    clr(grid);

    forne(i, 2, n+2) {
        forne(j, 2, n+2) {
            cin >> grid[i][j];
        }
    }  

    int wins = 0;

    forne(i, 2, n+2) {
        forne(j, 2, n+2) {
            if((grid[i][j] == grid[i][j+1] && grid[i][j+1] == grid[i][j+2])
                    || (grid[i][j] == grid[i+1][j] && grid[i+1][j] == grid[i+2][j])
                    || (grid[i][j] == grid[i+1][j+1] && grid[i+1][j+1] == grid[i+2][j+2])) {

                if(grid[i][j] == 'X') {
                    res = res_pool[3];
                } else if(grid[i][j] == '0') {
                    res = res_pool[4];
                }
                wins++;
            }

            if(grid[i][j] == 'X') {
                qtdX++;
            }
            if(grid[i][j] == '0') {
                qtdO++;  
            }
        }
    }

    if(wins > 1 || (qtdX > qtdO + 1) || (qtdX < qtdO)) res = res_pool[2];  // illegal
    if(res == res_pool[3] && qtdX != qtdO + 1) res = res_pool[2];
    if(res == res_pool[4] && qtdX != qtdO) res = res_pool[2];

    if(res == res_pool[0]) { // default
        if(qtdX+qtdO > 8) res = res_pool[5];
        else if(qtdX == qtdO) res = res_pool[0];
        else if(qtdX == qtdO + 1) res = res_pool[1];    //second
    }

    cout << res << endl;

    return 0;
}