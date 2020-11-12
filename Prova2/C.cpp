#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ii pair<int,int>

#define PRIMO 1000000007

ll hex_to_dec(string s) {
    ll ans = 0;

    for (unsigned i = 0; i < s.size(); i++) {
        ll aux = 0;

        if (s[i] >= 'A') {
            aux = s[i] - 'A' + 10;
        } else {
            aux = s[i] - '0';
        }

        ll base = 1;
        for (unsigned j = i + 1; j < s.size(); j++) base = base * 16 % PRIMO;

        ans = (ans + (aux * base % PRIMO)) % PRIMO;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    ll res = hex_to_dec(s);

    cout << res << endl;

    return 0;
}