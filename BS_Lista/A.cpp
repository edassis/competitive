#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int main() {
    int n, m;
    cin >> n >> m;
    vi livro(n);

    for (int i = 0; i < n; i++) {
        cin >> livro[i];
    }

    sort(livro.begin(), livro.end());

    int l = 0, r = n - 1;
    int x = -1,  y = - 1;
    while (l <= r) {
        int mid = (l+r)/2;

        int aux = -1;
        for (int i = 0; i < n; i++) {
            if (livro[i] + livro[mid] == m && i != mid) {
                aux = i;
                break;
            }
        }

        if (aux != -1) {
            if (x == -1 || abs(x - y) > abs(livro[mid] - livro[aux])) {
                x = livro[mid];
                y = livro[aux];
            }
        }

        if (livro[mid] <= m / 2) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    if (x <= y) {
        cout << x << " " << y << endl;
    } else {
        cout << y << " " << x << endl;
    }

    return 0;
}