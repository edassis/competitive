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

const int logn = 22;
const int MAX = 200005;

int mylog[MAX];
void make_log() {
    mylog[1] = 0;
    for(int i = 2; i <= MAX; i++) {
        mylog[i] = mylog[i/2] + 1;
    }
}

typedef int (*f_int_t) (int, int);

int f_max(int a, int b) {
    return max(a, b);
}
int f_min(int a, int b) {
    return min(a, b);
}

struct Sparse {
    vector<vl> st;

    Sparse(vl vt, f_int_t cb) {
        ll n = vt.size();
        st.assign(n, vl(logn, 0));

        for(ll i = 0; i < n; i++) {
            st[i][0] = vt[i];
        }

        for(ll k = 1; k < logn; k++) {
            for(ll i = 0; i < n; i++) {
                // tamanho intervalo 
                if(i + (1 << k) - 1 >= n)
                    continue;

                // prox intervalo
                ll prox = i + (1<<(k-1));
                st[i][k] = cb(st[i][k-1], st[prox][k-1]);
            }
        }
    }

    ll query(ll l, ll r, f_int_t cb) {
        ll len = r - l + 1;
        ll k = mylog[len];
        ll pot2 = (1<<k);

        ll res = cb(st[l][k], st[r-(pot2-1)][k]);
        return res;
    }
};

int main() {
    sws;

    int n; cin >> n;
    vl a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    f_int_t f_max_p = &f_max;
    f_int_t f_min_p = &f_min;

    Sparse st_max(a, f_max_p), st_min(b, f_min_p);

    ll count = 0;
    for(int i = 0; i < n; i++) {
        // middle of the remaining space
        
        ll l = i;
        ll r = n-1;
        while(l <= r) {
            ll mid = (l+r)/2;
            // W(l); W(r); W(mid);
            ll max = st_max.query(l, mid, f_max_p);
            ll min = st_min.query(l, mid, f_min_p);
            // W(diff);
            if(max == min) {
                count++;
                break;
            } else if (max > min) {
                r = mid - 1;
            } else { 
                l = mid + 1;
            }
        } 
    }

    cout << count << endl;

    return 0;
}