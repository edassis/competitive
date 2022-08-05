#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
#define all(x) x.begin(),x.end()

class DSU {
    vi p;
    vi size;
public:
    DSU(int n) : p(n+1), size(n+1, 1) {
        iota(all(p), 0);
    }

    void insert(int a, int b) {
        // vai para o pai
        a = query(a);
        b = query(b);

        // Mesmo pai
        if(a == b) return;

        // balancamento
        if(size[a] > size[b]) {
            swap(a, b);
        }

        // b maior
        size[b] += size[a];
        p[a] = b;
    }

    int query(int e) {
        // Compressão
        return (e == p[e]) ? (e) : ( p[e] = query(p[e]) );
    }

    bool same_set(int a, int b) {
        return query(a) == query(b);
    }
};