#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int main() {
    int n;
    ll k;

    cin >> n >> k;
    vi altura(n);
    
    for (int i = 0; i < n; i++) {
        cin >> altura[i];
    }

    sort(altura.begin(), altura.end(), greater<int>());

    int l = 1, r = altura.front();
    int res = 0;
    while (l <= r) {
        int mid = (l+r)/2;  // altura

        ll qtd = 0;
        for (int i = 0; i < n && qtd < k; i++) {
            int aux = altura[i] / mid;
            qtd += aux;
        }

        if (qtd >= k) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << res << endl;

    return 0;
}