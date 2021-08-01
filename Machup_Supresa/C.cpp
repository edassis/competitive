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

const int MAX = 104;
int dp[MAX][MAX];   // 2 margin
char matrix[MAX][MAX];

int f(vector<vector<char>> mat, int i, int j, int n) {
    if(j == n+2) return 0;
    if(dp[i][j] > -1) return dp[i][j];

    int atksW = 0, atksB = 0;
    int retW = 0, retB = 0;
    
    mat[i][j] = 'W';
    
    if(mat[i+2][j+1] == 'B') {
        atksW++;
    }
    if(mat[i+2][j-1] == 'B') {
        atksW++;
    }
    if(mat[i+1][j+2] == 'B') {
        atksW++;
    }
    if(mat[i+1][j-2] == 'B') {
        atksW++;
    }

    if(mat[i-2][j+1] == 'B') {
        atksW++;
    }
    if(mat[i-2][j-1] == 'B') {
        atksW++;
    }
    if(mat[i-1][j+2] == 'B') {
        atksW++;
    }
    if(mat[i-1][j-2] == 'B') {
        atksW++;
    }

    int prox_i = i+1, prox_j = j;
    if(prox_i == n+2) {
        prox_j = j+1;
        prox_i = 2;
    }

    retW = f(mat, prox_i, prox_j, n)+atksW;

    mat[i][j] = 'B';
    
    if(mat[i+2][j+1] == 'W') {
        atksB++;
    }
    if(mat[i+2][j-1] == 'W') {
        atksB++;
    }
    if(mat[i+1][j+2] == 'W') {
        atksB++;
    }
    if(mat[i+1][j-2] == 'W') {
        atksB++;
    }

    if(mat[i-2][j+1] == 'W') {
        atksB++;
    }
    if(mat[i-2][j-1] == 'W') {
        atksB++;
    }
    if(mat[i-1][j+2] == 'W') {
        atksB++;
    }
    if(mat[i-1][j-2] == 'W') {
        atksB++;
    }

    retB = f(mat, prox_i, prox_j, n)+atksB;
    
    int ret = 0;
    if (retW >= retB) {
        matrix[i][j] = 'W';
        ret = retW;
    } else {
        matrix[i][j] = 'B';
        ret = retB;
    }

    return dp[i][j] = ret;
}


int main() {
    sws;

    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            dp[i][j] = -1;
        }
    }

    int n; cin >> n;

    vector<vector<char>> mat(n+4, vector<char>(n+4, 0));

    for(int i = 2; i < n+2; i++) {
        for(int j = 2; j < n+2; j++) {
            mat[i][j] = 'B';
        }
    }

    int lutas = f(mat, 2, 2, n);
    W(lutas);

    for(int i = 2; i < n+2; i++) {
        for(int j = 2; j < n+2; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }

    return 0;
}