#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ii pair<int, int>

#define PRIMO 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int m, n;
        cin >> n >> m;

        vi bottom(101, 0);
        vi left(101, 0);
        for (int j = 1; j <= n; j++) {
            int aux;
            cin >> aux;
            bottom[aux] = 1;
        }
        for (int j = 1; j <= m; j++) {
            int aux;
            cin >> aux;
            left[aux] = 1;
        }

        int count = 0;
        for (int k = 1; k < 101; k++) {
            if (bottom[k] == 1 && left[k] == 1) count++;
        }

        cout << count << endl;
    }
    return 0;
}