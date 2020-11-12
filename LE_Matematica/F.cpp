#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

vi all_divisors(int n, int x) {
    vi ans;

    for (int i = 1; i * i <= x && i <= n; i++) {
        if (x % i == 0) {
            int b = x / i;
            ans.emplace_back(i);
            if (i != b && b <= n) {
                ans.emplace_back(b);
            }
        }
    }
    sort(ans.begin(), ans.end());

    return ans;
}

vector<vi> all_divisors_until_n(int n) {
    vector<vi> ans(n + 1);

    for (int i = 1; i <= n; i++) {
        // ans.emplace_back(all_divisors(i));
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    scanf("%d %d", &m, &n);

    vi amigos(n + 1, 0);

    for (int q = 1; q <= m; q++) {
        int x, y;
        scanf("%d %d", &x, &y);

        int ovos = 0;
        vi divs = all_divisors(n, x);
        
        for (auto &e : divs) {
            if (y <= q - 1 - amigos[e]) {
                amigos[e] = q;
                ovos++;
            }
        }

        printf("%d\n", ovos);
    }

    return 0;
}