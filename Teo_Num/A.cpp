#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

int main() {
    int x;

    cin >> x;

    vi divisores;

    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            int q = x / i;
            divisores.pb(i);
            if (q != i) divisores.pb(q);
        }
    }

    cout << divisores.size() << endl;

    return 0;
}