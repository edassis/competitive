template<typedef T>
struct DSU {
    vector<T> p, size;

    DSU(int n) : p(n+1), size(n+1, 1) {
        iota(p.begin(), p.end(), 0);
    }

    void insert(T a, T b) {
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

    T query(int e) {
        // Compressão
        return (e == p[e]) ? (e) : ( p[e] = query(p[e]) );
    }

    bool same_set(T a, T b) {
        return query(a) == query(b);
    }
};