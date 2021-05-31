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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; cin >> n >> q;
    string s;
    for(int i = 0; i < n; i++) {
        char c; cin >> c;
        s.pb(c);
        // freq[c]++;
    }

    while(q--) {
        map<char, int> freq;
        int l, r; cin >> l >> r;
        for (int i = l-1; i < r; i++) {
            freq[s[i]]++;
        }

        int counter = 0;
        for (auto e : freq) {
            if (e.ss % 2) {
                counter++;
            }
        }

        if ((r-l+1) % 2 == 0) {
            if (counter) {
                cout << "Nao" << '\n';
            } else {
                cout << "Sim" << '\n';
            }
        } else {
            if (counter == 1) {
                cout << "Sim" << '\n';
            } else {
                cout << "Nao" << '\n';
            }
        }
    }

    return 0;
}