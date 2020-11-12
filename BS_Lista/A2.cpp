#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

int main() {
    int n, m;
    cin >> n >> m;
    vi livro(n);

    for (int i = 0; i < n; i++) {
        cin >> livro[i];
    }

    sort(livro.begin(), livro.end());

    int x = -1, y = -1;
    for (int i = 0; i < n-1 && livro[i] <= m/2; i++) {
        int l = i + 1, r = n - 1;
        int res = -1;
        while (l <= r) {
            int mid = (l+r)/2;
            if (livro[mid] == m - livro[i]) {
                res = mid;
                break;
            } else if (livro[mid] < m - livro[i]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        if (res != -1) {
            x = livro[i];
            y = livro[res];
        }
    }

    cout << x << " " << y << endl;

    return 0;
}