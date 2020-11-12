#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int main() {
    ll n, y;

    cin >> n >> y;

    ll l = 1, r = n;
    ll res = 0;
    while(l <= r) {
        ll mid = (l+r)/2;
        
        string mid_s = to_string(mid);
        ll soma = 0;
        for (unsigned i = 0; i < mid_s.size(); i++) {
            soma += mid_s[i] - '0';
        }
        ll aux = mid - soma;

        if (aux >= y) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    if (res != 0) res = n - res + 1;
    
    cout << res << endl;

    return 0;
}