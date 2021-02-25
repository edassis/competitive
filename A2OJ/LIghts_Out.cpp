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

    int grid[3][3];
    memset(grid, 0, sizeof(grid));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int x;
            cin >> x;

            grid[i][j] += x;
            // adj
            if (j + 1 < 3) {  // coluna
                grid[i][j + 1] += x;
            }
            if (j - 1 >= 0) {
                grid[i][j - 1] += x;
            }

            if (i + 1 < 3) {
                grid[i + 1][j] += x;
            }
            if (i - 1 >= 0) {
                grid[i - 1][j] += x;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid[i][j]++;   // starts on
            if (grid[i][j] % 2) {
                // on
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
            cout << grid[i][j];
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}