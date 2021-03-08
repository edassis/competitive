#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" \
                  << "\n";
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
#define ii pair<int, int>
#define ff first
#define ss second

#define prime 1000000007

vi go{0, 1, 5, -1, -1, 2, -1, -1, 8, -1};

ll toInt(string s) {
    ll ans = 0;

    for (size_t i = 0; i < s.size(); i++) {
        ans = ans * 10 + (s[i] - '0');
    }

    return ans;
}

string toString(ll x) {
    string s;

    do {
        s.pb((x % 10) + '0');
    } while (x /= 10);

    reverse(s.begin(), s.end());

    return s;
}

int check(int x) {
    string s, ans;
    s = toString(x);
    if (x < 10) s = '0' + s;

    for (int i = 1; i >= 0; i--) {
        if (go[s[i] - '0'] == -1) return prime;
        else {
            ans.pb((go[s[i] - '0']) + '0');
        }
    }

    return toInt(ans);
}

string format(int x) {
    string ans;

    if (x < 10) {
        ans = '0' + toString(x);
    } else {
        ans = toString(x);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int h, m, ih, im;
        cin >> h >> m;
        string s;
        cin >> s;

        ih = (s[0] - '0') * 10 + (s[1] - '0');
        im = (s[3] - '0') * 10 + (s[4] - '0');

        while (1) {
            if (im == m) {
                im = 0;
                ih++;
            }

            if (ih == h) {
                ih = 0;
            }
            
            W(im);
            W(ih);
            W(check(im));
            W(check(ih));
            if (check(im) < h && check(ih) < m) {
                cout << format(ih) << ':' << format(im) << '\n';
                break;
            }
            im++;
        }
    }

    return 0;
}