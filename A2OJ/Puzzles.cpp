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

    int n, m;
    cin >> n >> m;

    vi puzzle(m);

    for (int i = 0; i < m; i++) cin >> puzzle[i];

    sort(puzzle.begin(), puzzle.end());

    int i = 0;
    int menor = 1e9;
    while (true) {
        if (i + n > puzzle.size()) break;

        menor = min(menor, puzzle[i+n-1] - puzzle[i]);
        i++;
    }

    cout << menor << endl;

    return 0;
}