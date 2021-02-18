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

    int n, q;
    vector<string> livros;

    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        livros.emplace_back(s);
    }

    for (int i = 0; i < q; i++) {
        string query;
        cin >> query;

        int a = 0, b = n - 1;
        int res = -1;
        while (a <= b) {
            int mid = (a + b) / 2;
            if (livros[mid] == query) {
                res = mid + 1;
                b = mid - 1;
            } else {
                if (livros[mid] > query) {
                    b = mid - 1;
                } else {
                    a = mid + 1;
                }
            }
        }
        cout << res << '\n';
    }

    return 0;
}