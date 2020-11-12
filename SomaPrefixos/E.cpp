#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

int main() {
    int n;
    cin >> n;

    int floresta[n][n] = {};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char in;
            cin >> in;
            if (in == 'F')
                floresta[i][j] = 1;
        }
    }

    int psum[n + 1][n + 1] = {};
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            psum[i][j] = floresta[i - 1][j - 1];
            psum[i][j] += psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1];
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x, y, z, w;
        cin >> x >> y >> z >> w;

        cout << psum[z][w] - psum[x - 1][w] - psum[z][y - 1] + psum[x - 1][y - 1] << endl;
    }
    return 0;
}