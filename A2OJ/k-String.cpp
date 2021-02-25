#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ii pair<int,int>
#define ff first
#define ss second

#define PRIMO 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    string s;

    cin >> k >> s;

    map<char, int> glo;
    for(size_t i = 0; i < s.size(); i++) {
        glo[s[i]]++;
    }

    string out;
    bool valid = true;
    for (auto &e : glo) {
        if (e.ss % k) {
            valid = false;
            break;
        }

        for (int i = 0; i < e.ss/k; i++) {
            out += e.ff;
        }
    }

    if (valid) {
        for (int i = 0; i < k; i++) {
            cout << out;
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}