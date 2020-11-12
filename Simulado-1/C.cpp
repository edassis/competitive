#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int main() {
    int n, q;

    cin >> n >> q;
    
    vi delta(101, 0);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        delta[l]++;
        
        if (r+1 <= 100) {
            delta[r+1]--;
        }
    }

    vi trofeus(101, 0);
    trofeus[0] = delta[0];
    for (int i = 1; i < 101; i++) {
        trofeus[i] = trofeus[i-1] + delta[i];
    }

    vi psum(101, 0);
    psum[0] = trofeus[0];
    for (int i = 1; i < 101; i++) {
        psum[i] = trofeus[i] + psum[i-1];
    }

    int prat_l = psum[q-1];
    int prat_r = psum[q] - 1;

    if (prat_l > prat_r)
        cout << -1 << endl;
    else
        cout << prat_l << ' ' << prat_r << endl;

    return 0;
}