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
        cin >> m >> n;

        int Matrix[101][101];
        for (int j = 0; j < 101; j++) {
            for (int k = 0; k < 101; k++) {
                Matrix[j][k] = 0;
            }
        }

        for (int j = 1; j <= n; j++) {
            int aux;
            cin >> aux;
            Matrix[aux][0] = 1;
        }
        for (int j = 1; j <= m; j++) {
            int aux;
            cin >> aux;
            Matrix[0][aux] = 1;
        }

        int count = 0;
        for (int k = 1; k < 101; k++) {
            if (Matrix[k][0]) { // bottom
                if (Matrix[0][k]) { // left
                    Matrix[k][k] = 1;
                    count++;
                }
            }
        }

        cout << count << 0;
    }
    return 0;
}