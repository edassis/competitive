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

vi crivo(int n) {
    vector<bool> ehprimo(n + 1, true);
    vi ans;

    ans.eb(2);
    ehprimo[0] = false;
    ehprimo[1] = false;

    for (int x = 3; x <= n; x += 2) {
        ehprimo[x + 1] = false;
        if (ehprimo[x]) {
            ans.eb(x);

            for (int i = x + x; i <= n; i += x) {
                ehprimo[i] = false;
            }
        }
    }

    return ans;
}

int main() {
    int q;
    scanf("%d", &q);

    vi primos = crivo(1000000);
    
    for (int i = 0; i < q; i++) {
        int n, m;
        scanf("%d %d", &n, &m);

        map<int, vi> pairs;
        for (unsigned j = 0; j < primos.size() - 1; j++) {
            if (primos[j] >= n && primos[j+1] <= m) {
                pairs[abs(primos[j+1] - primos[j])].eb(j);
            } else if (primos[j] > m) {
                break;
            }
        }

        if (!pairs.empty()) {
            printf("%d %d\n", primos[pairs.begin()->second.front()], primos[pairs.begin()->second.front() + 1]);
        } else {
            printf("-1\n");
        }
    }
    return 0;
}