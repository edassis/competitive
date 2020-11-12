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
    vi chocolate(n);
    
    for (int i = 0; i < n; i++) {
        cin >> chocolate[i];
    }

    sort(chocolate.begin(), chocolate.end(), greater<int>());

    int l = 1, r = chocolate.front();
    int res = -1;
    while (l <= r) {
        int mid = (l + r) / 2;  // qtd de chocolates para cada mae

        int maes = 0;
        for (int i = 0; i < n && maes < m; i++) {            
            int aux = chocolate[i] / mid; 
            maes += aux;
        }

        if (maes >= m) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    if (res != -1) cout << res << endl;
    else cout << 0 << endl;

    return 0;
}