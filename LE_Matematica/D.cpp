#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ii pair<int, int>

vi fatora(int n) {
    vi ans;

    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            n = n / i;
            ans.eb(i);
        }
    }
    if (n > 1) ans.eb(n);

    return ans;
}

int main() {
    int m, n;

    scanf("%d %d", &n, &m);

    if (n == 0) {
        printf("1\n");
        return EXIT_SUCCESS;
    }

    int res = 1;
    int dif = n - m;
    int fator2 = 0, fator5 = 0;

    for (int i = dif + 1; i <= n; i++) {
        int aux = i;

        while(aux % 2 == 0) {
            aux = aux / 2;
            fator2++;
        }
        while(aux % 5 == 0) {
            aux = aux / 5;
            fator5++;
        }
        
        res = res * aux % 10;
    }

    while (true) {
        if (fator2 > fator5) {
            res = res * 2 % 10;
            fator2--;
        } else if (fator2 < fator5) {
            res = res * 5 % 10;
            fator5--;
        } else
            break;
    }

    printf("%d", res);

    return EXIT_SUCCESS;
}