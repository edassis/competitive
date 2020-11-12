#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int main() {
    ll x;
    ll lim = pow(10, 10);
    ll resp = -1;
    cin >> x;

    ll l = 1, r = lim;
    while (l <= r) {
        ll mid = (l + r)/2;
        unsigned ll aux = (mid + 1) * mid / 2;
        if (aux > x) {
            resp = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << resp << endl;
    return 0;
}