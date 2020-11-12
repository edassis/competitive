#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int main() {
    int n, q;
    vi v; 
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        int aux;
        cin >> aux;
        v.pb(aux);
    }
    
    sort(v.begin(), v.end());

    for (int i = 0; i < q; i++) {
        int req;
        cin >> req;
        int l = 0, r = n - 1;
        int res = -1;
        while (l <= r) {
            int mid = (l + r)/2;
            
            if (v[mid] >= req) {
                res = v[mid];
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        cout << res << endl;
    }
    
    return 0;
}