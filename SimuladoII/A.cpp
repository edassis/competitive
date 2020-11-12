#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ii pair<int,int>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    scanf("%d %d", &n, &m);
    int aux = 1;
    for (int i = 1; i <= m; i++) {
        aux = aux * n % 10;
    }
    printf("%d\n", aux);
    return 0;
}