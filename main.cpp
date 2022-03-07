#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" \
                  << "\n";
#else
#define W(x)
#endif

using namespace std;

// Types
using ll  = long long;
using pii = pair<int, int>;
using pl  = pair<ll, ll>;
using vi  = vector<int>;
using vl  = vector<ll>;
using vpi = vector<pii>;
using vpl = vector<pl>;

// Macros
#define pb             push_back
#define eb             emplace_back
#define mp             make_pair
#define mt             make_tuple
#define ff             first
#define ss             second
#define endl           '\n'
#define forn(i, n)     for (int i = 0; i < (int)n; i++)
#define forni(i, k, n) for (int i = k; i < (int)n; i++)
#define forne(i, k, n) for (int i = k; i <= (int)n; i++)
#define fora(a)        for (auto each : a)
#define all(x)         x.begin(), x.end()
#define rall(x)        x.rbegin(), x.rend()
#define clr(x)         memset(x, 0, sizeof(x))

// Functions
// template<typename T>
// inline void clr(T& x) { memset(x, 0, sizeof(x)); }
inline void sws() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

// Constants
const ll     MOD = 998244353;
const ll     oo  = 1e18 + 7;
const double PI  = acos(-1.0);
const double EPS{1e-6};

template <typename T>
struct Point;

template <typename T>
bool equals(const T &a, const T &b) {
    if (is_floating_point_v<T>) {
        return fabs(a - b) < EPS;
    } else {
        return a == b;
    }
}

template <typename T>
double dist(const Point<T> &a, const Point<T> &b) {
    return hypot(static_cast<double>(a.x - b.x), static_cast<double>(a.y - b.y));
}

template <typename T>
struct Point {
    T x, y;

    bool operator<(const Point<T> &p) const {
        return equals(x, p.x) ? y < p.y : x < p.x;
    }
};

template <typename T>
struct Line {
    T a, b, c;

    Line(const Point<T> &P, const Point<T> &Q) {
        a = P.y - Q.y;
        b = Q.x - P.x;
        c = P.x * Q.y - Q.x * P.y;

        // T div = equals(a, 0.0) ? b : a;
        // a /= div;
        // b /= div;
        // c /= div;
    }

    // bool operator==(const Line<T> &l) const {
    //     return equals(a, l.a) && equals(b, l.b) && equals(c, l.c);
    // }

    double distance(const Point<T> &p) const {
        return fabs(a * p.x + b * p.y + c) / hypot(a, b);
    }

    bool contains(const Point<T> &p) const {
        return equals(a * p.x + b * p.y + c, 0);
    }

    Point<T> closest(const Point<T> &p) const {
        auto den = (a * a + b * b);

        auto x = (b * (b * p.x - a * p.y) - a * c) / den;
        auto y = (a * (-b * p.x + a * p.y) - b * c) / den;

        return Point<T>{x, y};
    }
};

template <typename T>
struct Segment {
    Point<T> A, B;

    bool contains2(const Point<T> &P) const {
        double dAB = dist(A, B), dAP = dist(A, P), dPB = dist(P, B);

        return equals(dAP + dPB, dAB);
    }

    Point<T> closest(const Point<T> &P) {
        Line<T> r(A, B);
        auto    Q = r.closest(P);

        if (this->contains2(Q))
            return Q;

        auto distA = dist(P, A);
        auto distB = dist(P, B);

        if (distA <= distB)
            return A;
        else
            return B;
    }
};

int main() {
    sws();

    int n, vb, vs;
    int xu, yu;
    cin >> n >> vb >> vs;

    vi parada(n);
    forn(i, n) {
        cin >> parada[i];
    }

    cin >> xu >> yu;

    Point<int> A{0, 0};
    double     t   = 0;
    int        idx = 0;
    forni(i, 1, n) {
        Point<int> U{xu, yu};
        Point<int> B{parada[i], 0};

        auto t1 = dist(A, U) / vs;

        auto t2b = dist(A, B) / vb;
        auto t2s = dist(B, U) / vs;

        W(t1);
        W(t2b);
        W(t2s);

        if (t + t1 < t + t2b + t2s) {
            // ir a pe
            // idx = i - 1;
            t += t1;
            break;
        } else if (t + t1 == t + t2b + t2s) {
            auto d1 = dist(A, U);
            auto d2 = dist(B, U);
            if (d1 < d2) {
                // desce se parada leva o mesmo tempo e a pé é for mais perto
                // idx = i - 1;
                t += t1;
                break;
            }
        }

        // caso contrario, continuar no onibus
        idx = i;
        t += t2b;
        A = B;
    }

    cout << idx + 1 << endl;

    return 0;
}
