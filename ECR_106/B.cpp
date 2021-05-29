#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
    #define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << "\n";
#else
    #define W(x)
#endif

using namespace std;

#define vi vector<int>
#define vii vector<ii>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ii pair<int,int>
#define ff first
#define ss second

#define prime 1e9+7

bool t[101][101];
bool calculado[101][101];

bool f(string &s, int &qtd, size_t i, size_t last_rem, size_t last_stay) {
    if (s.size() == i) return true;
    if (s[last_stay] > s[i]) return false;

    if (calculado[i][last_rem]) return t[i][last_rem];

    bool ans = false;
    
    qtd++;
    ans = f(s, qtd, i+1, last_rem, i);
    
    if (!ans && i > last_rem + 1) {
        qtd--;
        ans = f(s, qtd, i+1, i, last_stay);
    }  

    calculado[i][last_rem] = true;

    return t[i][last_rem] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(t, 0, sizeof(t));
    memset(calculado, 0, sizeof(calculado));

    int t; cin >> t;

    while(t--) {
        string s; cin >> s;
        s = '0' + s;

        int qtd = 0;
        f(s, qtd, 1, 0, 0);

        if (qtd >= 2) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }

    return 0;
}