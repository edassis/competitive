#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ii pair<int, int>
#define ff first
#define ss second

#define PRIMO 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string guest, host, pile;
    cin >> guest >> host >> pile;

    map<char, int> have;
    for (size_t i = 0; i < pile.size(); i++) {
        have[pile[i]]++;
    }

    for (size_t i = 0; i < guest.size(); i++) {
        have[guest[i]]--;
    }

    for (size_t i = 0; i < host.size(); i++) {
        have[host[i]]--;
    }
    
    bool valid = true;
    for (auto &e : have) {
        if (e.ss) {
            valid = false;
            break;
        }
    }
    
    if (valid)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;  // posivitve: extra letters, negative: need more.

    return 0;
}