template <typename T>
struct Seg {
    vector<T>    st;
    vector<T>    lazy;
    vector<bool> has;
    T            n;
    T            el_neutro;

    Seg(int n, T el_neutro = 0) : st(4 * n, el_neutro), lazy(4 * n, el_neutro), has(4 * n) {
        this->el_neutro = el_neutro;
        this->n         = n;
    }

    T query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }

    void update(int i, T amm) {
        update(0, 0, n - 1, i, amm);
    }

    void update(int l, int r, T amm) {
        update(0, 0, n - 1, l, r, amm);
    }

  private:
    T query(int sti, int stl, int str, int l, int r) {
        propagate(sti, stl, str);
        // fora do range
        if (stl > r or str < l) {
            return el_neutro;
        }

        // totalmente
        if (stl >= l and str <= r) {
            return st[sti];
        }

        int mid = (stl + str) / 2;

        // parcialmente
        return f(query(sti * 2 + 1, stl, mid, l, r), query(sti * 2 + 2, mid + 1, str, l, r));
    }

    void update(int sti, int stl, int str, int i, T amm) {
        propagate(sti, stl, str);
        // fora do range
        if (stl > i or str < i) {
            return;
        }

        // totalmente
        if (stl == i and str == i) {
            st[sti] = amm;
            return;
        }

        // parcialmente
        int mid = (stl + str) / 2;

        update(sti * 2 + 1, stl, mid, i, amm);
        update(sti * 2 + 2, mid + 1, str, i, amm);
        st[sti] = f(st[sti * 2 + 1], st[sti * 2 + 2]);
    }

    void update(int sti, int stl, int str, int l, int r, T amm) {
        if (stl > r or str < l) {
            return;
        }

        if (stl >= l and str <= r) {
            lazy[sti] = amm;
            has[sti]  = true;
            propagate(sti, stl, str);
            return;
        }

        int mid = (stl + str) / 2;
        update(sti * 2 + 1, stl, mid, l, r, amm);
        update(sti * 2 + 2, mid + 1, str, l, r, amm);
        st[sti] = f(st[sti * 2 + 1], st[sti * 2 + 2]);
    }

    void propagate(int sti, int stl, int str) {
        if (has[sti]) {
            st[sti] = lazy[sti] * (str - stl + 1);
            if (stl != str) {
                lazy[sti * 2 + 1] = lazy[sti];
                lazy[sti * 2 + 2] = lazy[sti];
                has[sti * 2 + 1]  = true;
                has[sti * 2 + 2]  = true;
            }
        }
        has[sti] = false;
    }

    T f(T a, T b) {
        return a + b;
    }
};
