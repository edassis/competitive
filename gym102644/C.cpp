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
#define sws ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'

const ll prime = 1e9+7;
const ll oo = 1e18+7;

vector<vl> id = {{1LL, 1LL}, {1LL, 0LL}};
vector<vl> b = {{1LL}, {0LL}};

struct Matrix {
    vector<vl> m;
    ll r, c;

    Matrix(vector<vl> &o) {
        m = vector<vl>(o);
        r = o.size();
        c = o[0].size();
    }

    Matrix(ll r, ll c, bool identity = false) {
        this->r = r;
        this->c = c;
        m = vector<vl>(r, vl(c, 0));
        
        if(identity) {
            for(ll i = 0; i < min(r, c); i++) {
                m[i][i] = 1;
            }
        }
    }

    Matrix operator*(const Matrix &o) const {
        assert(c == o.r);   // ensures matrix multiplication
        
        vector<vl> ans(r, vl(o.c, 0));
        
        for(ll i = 0; i < r; i++) {
            for(ll j = 0; j < o.c; j++) {
                for(ll k = 0; k < c; k++) {
                    ans[i][j] = (ans[i][j] + (m[i][k] * o.m[k][j] % prime)) % prime;
                }
            }
        }

        return Matrix(ans);
    }

    void print() {
        for(ll i = 0; i < r; i++) {
            for(ll j = 0; j < c; j++) {
                cout << m[i][j] << ' ';
            }
            cout << endl;
        }
    }
};

ll fexp(ll num, ll e) {
    if(e == 0) return 1;

    if(e % 2) return num*fexp(num, e>>1)*fexp(num, e>>1)%prime;
    return fexp(num, e>>1)*fexp(num, e>>1)%prime;
}

vector<Matrix> dp(64, Matrix(2, 2, true));
char calculado[64];

Matrix fexpmdp(Matrix mat, ll e, ll n, ll st) {
    if(e == 0) return Matrix(n, n, true);
    if(calculado[st]) return dp[st];
    
    Matrix ans(2, 2, true);
    if(e % 2){
        ans = mat * fexpmdp(mat, e>>1, n, st+1) * fexpmdp(mat, e>>1, n, st+1);
    } else {
        ans = fexpmdp(mat, e>>1, n, st+1) * fexpmdp(mat, e>>1, n, st+1);
    }

    calculado[st] = 1;
    return dp[st] = ans;
}

Matrix fexpm(Matrix mat, ll e, ll n) {
    if(e == 0) return Matrix(n, n, true);
    
    Matrix ans = fexpm(mat, e>>1, n);
    ans = ans*ans;
    if(e % 2) ans = mat * ans;

    return ans;
}

ll ffib(ll n) {
    if(n == 0) return 0;

    Matrix idx(id), base(b);
    
    // memset(calculado, 0, sizeof(calculado));
    
    // idx = fexpmdp(idx, n-1, 2, 0);
    idx = fexpm(idx, n-1, 2);
    Matrix ans = idx * base;

    return ans.m[0][0];
}

int main() {
    sws

    ll n; cin >> n;

    cout << ffib(n) << endl;

    return 0;
}