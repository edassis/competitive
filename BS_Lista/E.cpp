#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int main() {
    int n;
    ll p;

    cin >> n >> p;
    vi num(n);

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    int l = 1, r = n;
    int res = 0;
    while(l <= r) {
        int mid = (l+r)/2;  // intervalo

        ll soma = 0;
        int i = 0;
        
        for (int j = i; j < mid; j++) {
            soma += num[j];
        }

        while (soma > p && i < n - mid) {
            soma -= num[i];
            i++;
            soma += num[i + mid - 1];
        }

        if (soma <= p) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << res << endl;

    return 0;
}