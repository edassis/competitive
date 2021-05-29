#include <bits/stdc++.h>

using namespace std;

#define vi  vector<int>
#define vii vector<ii>
#define vll vector<ll>
#define ll  long long
#define pb  push_back
#define eb  emplace_back
#define mp  make_pair
#define ii  pair<int, int>
#define ff  first
#define ss  second

#define PRIME 1000000007

string compare = "hello";

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    size_t pos = 0;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == compare[pos]) pos++;

        if (pos == compare.size()) {
            cout << "YES" << endl;
            break;
        }
    }

    if (pos < compare.size()) cout << "NO" << endl;

    return 0;
}