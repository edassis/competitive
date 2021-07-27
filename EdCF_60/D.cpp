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

Matrix fexp(const Matrix &mat, ll e, const ll &n) {
    if(e == 0) return Matrix(n, n, true);
    
    Matrix ans = fexp(mat, e/2, n);
    ans = ans*ans;
    if(e%2) ans = ans*mat;

    return ans;
}

ll f(ll n, ll m) {
    if(n == 1 || m > n) return 1;

    Matrix idx(m, m);

    idx.m[0][0] = 1;
    idx.m[0][m-1] = 1;
    for(int i = 1, j = 0; i < m && j < m; i++, j++) {
        idx.m[i][j] = 1;
    }

    vector<vl> b(m, vl(1, 1));
    Matrix base(b);

    idx = fexp(idx, n-1*(m-1), m);
    Matrix ans = idx * base;

    return ans.m[0][0];
}

int main() {
    sws

    ll n, m; cin >> n >> m;

    cout << f(n, m) << endl;

    return 0;
}