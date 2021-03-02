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

    string s;
    cin >> s;

    int counter = 0;
    int team = -1;
    bool danger = false;

    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] != team) {
            counter = 1;
            team = s[i];
        } else {
            counter ++;
        }

        if (counter >= 7) {
            danger = true;
            break;
        }
    }

    if (danger) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}