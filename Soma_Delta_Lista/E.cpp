#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    struct op {
        int l, r, d;
    };
    vector<op> ops;
    for (int i = 0; i < m; i++) {
        op current_op;
        int l, r, d;
        
        cin >> l >> r >> d;
        l--; r--;

        current_op.l = l;
        current_op.r = r;
        current_op.d = d;
        
        ops.push_back(current_op);
    }

    vector<ll> delta_q(m);
    for (int i = 0; i < k; i++) {
        int x, y;
        
        cin >> x >> y;
        x--; y--;

        delta_q[x]++;
        if (y + 1 < m) delta_q[y + 1]--;
    }

    vector<ll> queries(m);
    ll atual = 0;
    for (int i = 0; i < m; i++) {
        atual += delta_q[i];
        queries[i] = atual;
    }

    
    vector<ll> delta_v(n);
    for (int i = 0; i < m; i++) {
        delta_v[ops[i].l] += queries[i] * ops[i].d;
        
        if (ops[i].r + 1 < n)
            delta_v[ops[i].r + 1] -= queries[i] * ops[i].d;
    }

    atual = 0;
    for (int i = 0; i < n; i++) {
        atual += delta_v[i];
        v[i] = atual + v[i];
        cout << v[i] << ' ';
    }
    cout << endl;

    return 0;
}