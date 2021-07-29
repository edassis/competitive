// Static Range Minimum Queries
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

const int MAX = 200005;
int mylog[MAX+1];
void make_log() {
    mylog[1] = 0;
    for(int i = 2; i <= MAX; i++) {
        mylog[i] = mylog[i/2] + 1;
    }
}

const int logn = 22;
struct Sparse {
    vector<vi> st;

    Sparse(vi v) {
        int n = v.size();
        st.assign(n, vi(logn, 0));
        
        for (int i = 0; i < n; i++) {
            st[i][0] = v[i];
        }

        for (int k = 1; k < logn; k++) {
            for (int i = 0; i < n; i++) {
                // tamanho intervalo
                if (i + (1 << k) - 1 >= n)
                    continue;

                // proximo intervalo
                int prox = i + (1 << (k-1));
                st[i][k] = f(st[i][k-1], st[prox][k-1]);
            }
        }
    };

    int query(int l, int r) {
        int len = r - l + 1;
        int k = mylog[len];

        return f(st[l][k], st[r - ((1 << k)-1)][k]);  
    }
    
    int f(int a, int b) {
        return min(a, b);
    }
};

int main() {
    sws;
    
    make_log();

    int n, q; cin >> n >> q;

    vi v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    Sparse st(v);

    while(q--) {
        int l, r; cin >> l >> r;
        l--; r--;

        cout << st.query(l, r) << endl;
    }
    
    return 0;
}