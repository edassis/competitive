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

    int r, c;
    cin >> r >> c;
    char cake[r][c];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            char cell;
            cin >> cell;

            cake[i][j] = cell;
        }
    }

    int count = 0;

    for (int i = 0; i < r; i++) {
        bool evil = false;

        for (int j = 0; j < c; j++) {
            if (cake[i][j] == 'S') {
                evil = true;
                break;
            }
        }

        if (!evil) {
            for (int j = 0; j < c; j++) {
                if (cake[i][j] == '.') {
                    cake[i][j] = ' ';
                    count++;
                }
            }
        }
    }

    for (int i = 0; i < c; i++) {
        bool evil = false;

        for (int j = 0; j < r; j++) {
            if (cake[j][i] == 'S') {
                evil = true;
                break;
            }
        }
        
        if (!evil) {
            for (int j = 0; j < r; j++) {
                if (cake[j][i] == '.') {
                    cake[j][i] = ' ';
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}