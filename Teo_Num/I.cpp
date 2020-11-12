#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>


ll fast_exp(ll b, ll e) {
    if (e == 0) return 1;

    if (e % 2) return b * fast_exp(b*b, e/2);
    return fast_exp(b*b, e/2);
}

ll convert_num(string s, int base) {
    ll num = 0;
    for (size_t i = 0; i < s.size(); i++) {
        num = num * base + (s[i] - '0');
    }
    return num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;
        ll num = convert_num(s, 10);
        ll exp = s.size();
        ll res = ( ( (1+fast_exp(10, exp)) % 7) * (num % 7) % 7);

        if (res) cout << "Nao" << endl;
        else cout << "Sim" << endl;
    }
    return 0;
}