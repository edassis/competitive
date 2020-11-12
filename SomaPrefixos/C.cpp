// C - Karen and Coffee
#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

#define MAX_TEMP 200005
int main() {
    int n, k, q;
    cin >> n >> k >> q;
    
    vi delta(MAX_TEMP, 0);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        delta[l] += 1;
        if (r+1 < MAX_TEMP)
            delta[r+1] -= 1;
    }

    vi rec(MAX_TEMP, 0);
    int atual = 0;
    for (int i = 0; i < MAX_TEMP; i++) {
        atual += delta[i];
        rec[i] = atual;
    }

    vi psum(MAX_TEMP, 0);
    if (rec[0] >= k)
        psum[0] = 1;
    
    for (int i = 1; i < MAX_TEMP; i++) {
        if (rec[i] >= k) {
            psum[i] = psum[i-1] + 1;
        }
        else {
            psum[i] = psum[i-1];
        }
    }
    
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        cout << psum[r] - psum[l-1] << endl; 
    }

    return 0;
}
