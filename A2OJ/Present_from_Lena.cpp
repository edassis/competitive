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

    int n;
    cin >> n;

    int expand = 0;
    for (int i = 0; i < n*2+1; i++) {
        for (int j = 0; j < (n-expand); j++) {
            cout << "  ";
        }

        for (int j = 0; j < expand*2+1; j++) {
            int value = (expand - j) > 0 ? expand - (expand - j) : expand + (expand - j);
            cout << (char)('0' + value);

            if (j+1 < expand*2+1) cout << ' ';
        }
        cout << '\n';

        if (i < n) {
            expand++;
        } else {
            expand--;
        }
    }

    return 0;
}