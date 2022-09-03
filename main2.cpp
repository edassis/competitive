#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" \
                  << "\n";
#else
#define W(x)
#endif

using namespace std;

#define vi             vector<int>
#define vl             vector<ll>
#define pii            pair<int,int>
// Macros
#define ll             long long
#define pb             push_back
#define eb             emplace_back
#define mp             make_pair
#define mt             make_tuple
#define ff             first
#define ss             second
#define endl           '\n'
#define forn(i, n)     for (int i = 0; i < (int)n; i++)
#define forni(i, k, n) for (int i = k; i < (int)n; i++)
#define forne(i, k, n) for (int i = k; i <= (int)n; i++)
#define fora(a)        for (auto each : a)
#define all(x)         x.begin(), x.end()
#define rall(x)        x.rbegin(), x.rend()
#define clr(x)         memset(x, 0, sizeof(x))

inline void sws() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

// Constants
const ll     MOD = 998244353;
const ll     oo  = 1e18 + 7;
const double PI  = acos(-1.0);
const double EPS{1e-6};


struct DSU {
    int n;
    vi parent, size;

    DSU(int n) {
        this->n = n;
        parent.assign(n+1, 0);
        size.assign(n+1, 1);

        forne(i, 0, n) {
            parent[i] = i;
        }
    }

    void join(int a, int b) {
        a = find(a);
        b = find(b);

        if(size[a] < size[b]) {
            swap(a, b);
        }

        parent[b] = a;
        size[a] += size[b];
    }

    int find(int a) {
        if(a == parent[a]) return a;
        return parent[a] = find(parent[a]);
    }
};

string solve(string s, int k) {
    while(k--) {
        pair<char,int> val;
        val.ff=0;
        val.ss=-1;
        forn(i, i<k && i<s.size()) {
            if(i == 0 || s[i] > val.ff) {
                val.ff = s[i];
                val.ss = i;
            }
        }
        forni(i, 1, s.size()) {
            if(s[i] > s[i-1]) {
                swap(s[i], s[i-1]);
                break;
            }
        }
    }

    return s;
}

int main() {
    sws();
    
    string s;
    int k;
    cin >> s >> k;
    
    string res = solve(s, k);

    cout << res << endl;

    return 0;
}

