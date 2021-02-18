#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ii pair<int, int>
#define ff first
#define ss second

#define PRIMO 1000000007

struct UnionFind {
    vi pai;
    vi rank;
    int n;

    UnionFind(int n) : n(n), pai(n), rank(n) {
        fill(rank.begin(), rank.end(), 1);
        iota(pai.begin(), pai.end(), 0);
    }

    int Find(int x) {
        if (x == pai[x]) {
            return x;
        }
        return pai[x] = Find(pai[x]);
    }

    void Union(int a, int b) {
        a = Find(a);
        b = Find(b);
        if (a == b) {
            return;
        }
        if (rank[a] > rank[b]) {
            pai[b] = a;
            rank[a] += rank[b];
        } else {
            pai[a] = b;
            rank[b] += rank[a];
        }
    }

    bool isSameSet(int a, int b) {
        return Find(a) == Find(b);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    UnionFind uni(n + 1);

    for (int i = 0; i < q; i++) {
        int tp, a, b;
        cin >> tp >> a >> b;

        if (tp == 1) {
            uni.Union(a, b);
        } else {
            if (uni.isSameSet(a, b))
                cout << "SIM\n";
            else
                cout << "NAO\n";
        }
    }
    cout << endl;

    return 0;
}