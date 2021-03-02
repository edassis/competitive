#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ii pair<int, int>
#define ff first
#define ss second

#define PRIMO 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vi v(k);
    fill(v.begin(), v.end(), 1);

    int counter = 0;
    int pos = k - 1;
    while (true) {
        do {
            for (int i = v[pos - 1]; i <= n; i += v[pos - 1]) {
                v[pos] = i;
                counter = (counter+1) % PRIMO;
            }
            pos++;
        } while (pos < k);

        pos-=2;

        while (pos >= 0) {
            if (v[pos] < n) {
                v[pos]++;
                fill(v.begin() + pos, v.end(), v[pos]);
                pos++;
                break;
            }

            pos--;
        } 

        if (pos < 0) break;
    }

    cout << counter << endl;

    return 0;
}