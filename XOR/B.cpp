#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    
    ll pos = n;
    ll neg = 0;
    
    vi v;
    while (n > 0) {
        v.pb(n%2);
        n = n / 2;
    }
    for (int i = (int) v.size() - 1; i >= 0; i--) {
        neg = neg * 2 + 1^v[i];
    }
    cout << pos << ' ' << neg << endl;

    return 0;
}