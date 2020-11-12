#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int main() {
    string p, t;
    
    cin >> t >> p;
    
    vi idx(t.size());

    for (unsigned i = 0; i < t.size(); i++) {
        cin >> idx[i];
        idx[i]--;
    }

    int l = 0, r = t.size() - 1;
    int res = -1;
    while(l <= r) {
        vi mask(t.size(), 1);
        int mid = (l+r)/2;
        
        for (int i = 0; i < mid; i++) {
            mask[idx[i]] = 0;
        }

        int contador = 0, pos_p = 0;
        for (unsigned i = 0; i < t.size() && pos_p < p.size(); i++){
            if (t[i] == p[pos_p] && mask[i] == 1) {
                pos_p++;
                contador++;
            }
        }
        
        if (contador == p.size()) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << res << endl;
    return 0;
}