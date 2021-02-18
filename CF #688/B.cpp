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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vi vec(n);
        for (int j = 0; j < n; j++) {
            cin >> vec[j];
        }

        vi delta(n);
        delta[0] = vec[0];
        for (int j = 1; j < n; j++) {
            delta[j] = vec[j] - vec[j - 1];
        }

        int maior = 0;
        int maior_idx = 0;
        for (int j = 1; j < n - 1; j++) {
            int aux = abs(delta[j] - delta[j + 1]);
            if (aux > maior) {
                maior = aux;
                maior_idx = j;
            }
        }

        if (abs(delta[maior_idx] - delta[maior_idx - 1]) 
                > abs(delta[maior_idx + 1] - delta[maior_idx - 1])) {
            delta[maior_idx] = 0;
            delta[maior_idx+1] += - (delta[maior_idx] - delta[maior_idx - 1]);
        } else {
            delta[maior_idx] = 0;
            delta[maior_idx+1] += -(delta[maior_idx+1] - delta[maior_idx]);
        }

        ll count = 0;
        for (int j = 1; j < n; j++) {
            count += abs(delta[j]);
        }

        cout << count << endl;

        return 0;
    }
}