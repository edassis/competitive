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
#define forne(i, k, n) for (int i = k; i  (int)n; i++)
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
    if (is_floating_point<T>::value) {
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
double manhattan(const Point<T> &a, const Point<T> &b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

template <typename T>
struct Point {
    T x, y;
    
    // Point(const T& x, const T& y) : x(x), y(y) {}
    
    // Point<double>(const int& x, const int& y) : x(double(x)), y(double(y)) {}

    bool operator<(const Point<T> &p) const {
        return equals(x, p.x) ? y < p.y : x < p.x;
    }

    bool operator==(const Point<T>& p) const {
        return equals(x, p.x) && equals(y, p.y);
    }
};

// template<typename T=double>
// struct Point {
//     Point(const int& x, const int& y) : x(double(x)), y(double(y)) {}
// };

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

    bool operator==(const Line<T> &l) const {
        // Acho que a reta tem de estar normalizada
        return equals(a, l.a) && equals(b, l.b) && equals(c, l.c);
    }

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

template<typename T>
pair<int, Point<T>> intersections(const Line<T>& r, const Line<T>& s) {
    const int INF { -1 };
    
    auto det = r.a * s.b - r.b * s.a;

    if(equals(det, (decltype(det))0)) {        // Coincidentes ou paralelas
        return { (r == s) ? INF : 0, {}};
    } else {
        auto x = (-r.c * s.b + s.c * r.b) / det;
        auto y = (-s.c * r.a + r.c * s.a) / det;

        return { 1, { x, y } };
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

template<typename T>
struct Rectangle {
    Point<T> P, Q;
    T b, h;

    Rectangle(const Point<T>& p, const Point<T>& q) : P(p), Q(q) {
        b = max(p.x, q.x) - min(p.x, q.x);
        h = max(p.y, q.y) - min(p.y, q.y);
    }

    Rectangle(const T& base, const T& height) : b(base), h(height) {
        P = {0, 0};
        Q = {base, height};
    }

    T perimeter() const {
        return (b+h)*2;
    }

    T area() const {
        return b*h;
    }

    Rectangle intersection(const Rectangle& r) const {
        using interval = pair<T, T>;

        auto I = interval(min(P.x, Q.x), max(P.x, Q.x));
        auto U = interval(min(r.P.x, r.Q.x), max(r.P.x, r.Q.x));
        
        // maior dos menores
        auto a = max(I.ff, U.ff);
        // menor dos maiores
        auto b = min(I.ss, U.ss);

        if(b < a) {
            return {{-1, -1}, {-1, -1}};
        }

        I = interval(min(P.y, Q.y), max(P.y, Q.y));
        U = interval(min(r.P.y, r.Q.y), max(r.P.y, r.Q.y));
        
        auto c = max(I.ff, U.ff);
        auto d = min(I.ss, U.ss);

        if(d < c) {
            return {{-1, -1}, {-1, -1}};
        }

        return {{a, c}, {b, d}};
    }
};

template<typename T>
class Polygon {
private:
    vector<Point<T>> vs;
    int n;

public:
    Polygon(const vector<Point<T>>& ps) : vs(ps), n(vs.size()) {
        vs.pb(vs.front());
    }

private:
    T D(const Point<T>& P, const Point<T>& Q, const Point<T>& R) const {
        return (P.x * Q.y + P.y * R.x + Q.x * R.y) - (R.x * Q.y + R.y * P.x + Q.x * P.y);
    }

public:
    bool convex() const {
        if(n < 3) return false;

        int P = 0, N = 0, Z = 0;

        for(int i = 0; i < n; i++) {
            auto d = D(vs[i], vs[(i+1)%n], vs[(i+2)%n]);
            d ? (d > 0 ? P++ : N++) : Z++;

            return P == n || N == n;
        }
    }

    double perimeter() const {
        auto p = 0.0;
        forn(i, n) {
            p += distance(vs[i], vs[i+1]);
        }
        
        return p;
    }

    double area() const {
        auto a = 0.0;

        forn(i, n) {
            a += vs[i].x * vs[i+1].y;
            a -= vs[i+1].x * vs[i].y;
        }

        return 0.5 * fabs(a);
    }

private:
    // Ângulo APB em radianos
    double angle(const Point<T>& P, const Point<T>& A, const Point<T>& B) const {
        auto ux = P.x - A.x;
        auto uy = P.y - A.y;

        auto vx = P.x - B.x;
        auto vy = P.y - B.y;

        auto num = ux * vx + uy * vy;
        auto den = hypot(ux, uy) * hypot(vx, vy);

        // Caso especial: se den == 0, algum dos vetores é degenerado: os 
        // dois pontos são iguais. Neste caso, o ângulo não está definido 

        return acos(num/den);
    }

public:
    bool contains(const Point<T>& P) const {
        if (n < 3) return false;

        auto sum = 0.0;

        forn(i, n-1) {
            auto d = D(P, vs[i], vs[i+1]);
            auto a = angle(P, vs[i], vs[i+1]);
            sum += d > 0 ? a : -a;
        }

        return equals(fabs(sum), 2*PI);
    }

private:
    // Interseção entre a reta AB e o segmento de reta PQ
    Point<T> intersection(const Point<T>& P, const Point<T>& Q,
                          const Point<T>& A, const Point<T>& B) const {
        auto a = B.y - A.y;
        auto b = A.x - B.x;
        auto c = B.x * A.y - A.x * B.y;
        auto u = fabs(a * P.x + b * P.y + c);
        auto v = fabs(a * Q.x + b * Q.y + c);

        // Média ponderada pelas distâncias de P e Q até a reta AB
        return {(P.x * v + Q.x * u)/(u + v), (P.y * v + Q.y * u)/(u + v)};
    }

public:
    Polygon cut_polygon(const Point<T>& A, const Point<T>& B) const {
        vector<Point<T>> points;
    
        forn(i, n) {
            auto d1 = D(A, B, vs[i]);
            W(d1);
            auto d2 = D(A, B, vs[i+1]);
            W(d2);

            // Vértice à esquerda da reta
            if (d1 > -EPS) points.pb(vs[i]);

            // A aresta cruza a reta
            if (d1 * d2 < -EPS) points.pb(intersection(vs[i], vs[i+1], A, B));
        }

        W(points.size());
        return Polygon(points);
    }
};
