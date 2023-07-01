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
#define loop(i, n)     for (int i = 0; i < (int)n; i++)
#define loopi(i, k, n) for (int i = k; i < (int)n; i++)
#define loope(i, k, n) for (int i = k; i <= (int)n; i++)
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

const ll maxn = 1e5+2;
const ll K    = 26;

// int n;

struct no {
    bool leaf = false;
    vi   next;

    no() : next(K) {}
};

vector<no> trie(1);

int getId(int i, int k) {
    return i * k + k;
}

void insert(string s) {
    int u  = 0;
    int sz = 0;

    while (sz < s.size()) {
        int v = trie[u].next[s[sz] - 'a'];
        if (!v) {
            trie.eb();
            v = trie.size() - 1;
            trie[u].next[s[sz] - 'a'] = v;
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
        u = trie[u].next[s[sz++] - 'a'];
    } while (u and sz < s.size());

    return trie[u].leaf;
}

vi dp(maxn, -1);
string s;

int count(int i) {
    if(i == s.size()) return 1;
    W(s.substr(i));
    if(dp[i] > -1) return dp[i];

    int u = 0;

    int j = i;
    int ans = 0;
    do {
        u = trie[u].next[s[j]-'a'];
        j++;
        if(trie[u].leaf) {
            ans += count(j);
            ans %= MOD;
        }
    } while(u and j < s.size());

    return dp[i] = ans;
}


int main() {
    sws();

    int n;
    cin >> n;

    loop(i,n) {
        cin >> s;
        insert(s);
    }

    cin >> s;

    cout << count(0) << endl;

    return 0;
}
