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

    int n, k;
    cin >> n >> k;

    vi height(n);
    for(int i = 0; i < n; i++) cin >> height[i];

    vi sum(n);
    sum[0] = height[0];
    for (int i = 1; i < n; i++) {
        sum[i] = height[i] + sum[i-1];
    }

    int idx = 0, menor = 1e9;
    for (int i = k-1; i < n; i++) {
        int inter = sum[i];
        if (i-k >= 0) inter -= sum[i-k];

        if (menor > inter) {
            menor = inter;
            idx = i-k+1;
        }
    }

    cout << idx + 1 << endl;

    return 0;
}