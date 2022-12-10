#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" \
                  << "\n";
#else
#define W(x)
#endif

using namespace std;

// Types
using ll  = long long;
using pii = pair<int, int>;
using pl  = pair<ll, ll>;
using vi  = vector<int>;
using vl  = vector<ll>;
using vpi = vector<pii>;
using vpl = vector<pl>;

// Macros
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
#define fora(e, a)     for (auto e : a)
#define dbg(msg, var)  cout << msg << " " << var << endl
#define all(x)         x.begin(), x.end()
#define rall(x)        x.rbegin(), x.rend()

// Functions
template <typename T>
inline void clr(T &x) { memset(x, 0, sizeof(x)); }
inline void sws() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

// Constants
const ll MOD = 1e9 + 7;
const ll oo  = 1e18 + 7;

const ll maxn = 1e5;
const ll k    = 26;

struct no {
    bool leaf = false;
    vi   next;

    no() : next(k) {}
};

vector<no> trie(1);

int getId(int i, int k) {
    return i * k + k;
}

void insert(string s) {
    int u  = 0;
    int sz = 0;

    while (sz < s.size()) {
        int v = trie[u].next[s[u] - 'a'];
        if (!v) {
            trie.eb();
            v                        = trie.size() - 1;
            trie[u].next[s[u] - 'a'] = v;
        }
        u = v;
        sz++;
    }
    trie[u].leaf = true;
}

bool has(string s) {
    int u  = 0;
    int sz = 0;
    do {
        u = trie[u].next[s[u] - 'a'];
        sz++;
    } while (u && sz);

    return trie[u].leaf;
}

int main() {
    sws();

    clr(trie);

    return 0;
}
