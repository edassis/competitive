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
#define fora(a)        for (auto &each : a)
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
const double pi  = acos(-1.0);
const ll     MOD = 1e9 + 7;
const ll     oo  = 1e18 + 7;

const double EPS{1e-6};

template <typename T>
struct Point;

template <typename T>
struct Line;

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
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

template <typename T>
T manhattan(const Point<T> &a, const Point<T> &b) {
    if (is_floating_point_v<T>) {
        return fabs(a.x - b.x) + fabs(a.y - b.y);
    } else {
        return abs(a.x - b.x) + abs(a.y - b.y);
    }
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
    // equacação geral
    T a, b, c;

    Line(const Point<T> &P, const Point<T> &Q) {
        a = P.y - Q.y;
        b = Q.x - P.x;
        c = P.x * Q.y - Q.x * P.y;

        T div = equals(a, 0.0) ? b : a;
        a /= div;
        b /= div;
        c /= div;
    }

    bool operator==(const Line<T> &l) const {
        return equals(a, l.a) && equals(b, l.b) && equals(c, l.c);
    }
};

template <typename T>
struct Triangle {
    Point<T> A, B, C;

    double area() const {
        // Fórmula de Heron
        auto a = dist(A, B);
        auto b = dist(B, C);
        auto c = dist(C, A);

        // semiperímetro
        auto s = (a + b + c) / 2;

        return sqrt(s) * sqrt(s - a) * sqrt(s - b) * sqrt(s - c);
    }
};

int main() {
    sws();

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<Point<int>> points;
        vi                 has(n);

        forn(i, n) {
            Point<int> p;
            cin >> p.x >> p.y;
            points.pb(p);
        }

        forn(i, n) {
            forni(j, i + 1, n) {
                auto man = manhattan(points[i], points[j]);
                if (man <= k) {
                    has[i]++;
                }
            }
        }

        bool valido = false;
        forn(i, n) {
            if (has[i] == n - 1) {
                valido = true;
                break;
            }
        }

        cout << (valido ? "1" : "-1") << endl;
    }

    return 0;
}

