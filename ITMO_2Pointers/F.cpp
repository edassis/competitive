#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" \
                  << "\n";
#else
#define W(x)
#endif

using namespace std;

#define vi  vector<int>
#define vii vector<ii>
#define vll vector<ll>
#define ll  long long
#define pb  push_back
#define eb  emplace_back
#define mp  make_pair
#define ii  pair<int, int>
#define ff  first
#define ss  second

#define prime 1e9 + 7

struct myQueue {
    stack<ll> si, sr;
    stack<ll> mini, minr;
    stack<ll> maxi, maxr;

    void add(ll el) {
        si.push(el);

        if (mini.size()) {
            mini.push(min(el, mini.top()));
        } else {
            mini.push(el);
        }

        if (maxi.size()) {
            maxi.push(max(el, maxi.top()));
        } else {
            maxi.push(el);
        }
    }

    ll remove() {
        if (sr.empty()) {
            while (si.size()) {
                ll el = si.top();
                si.pop();
                mini.pop();
                maxi.pop();
                sr.push(el);

                if (minr.size()) {
                    minr.push(min(el, minr.top()));
                } else {
                    minr.push(el);
                }

                if (maxr.size()) {
                    maxr.push(max(el, maxr.top()));
                } else {
                    maxr.push(el);
                }
            }
        }

        ll el = LLONG_MAX;
        if (sr.size()) {
            el = sr.top();
            sr.pop();
            minr.pop();
            maxr.pop();
        }

        return el;
    }

    ll getMax() {
        ll ei = LLONG_MIN;
        ll er = LLONG_MIN;

        if (maxi.size()) ei = maxi.top();
        if (maxr.size()) er = maxr.top();

        return max(ei, er);
    }

    ll getMin() {
        ll ei = LLONG_MAX;
        ll er = LLONG_MAX;

        if (mini.size()) ei = mini.top();
        if (minr.size()) er = minr.top();

        return min(ei, er);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    ll k;
    cin >> k;
    vector<ll> els(n);
    for (int i = 0; i < n; i++) cin >> els[i];

    int     l = 0, r = 0;
    ll      ans = 0;
    myQueue q;
    for (r = 0; r < n; r++) {
        // add right el
        q.add(els[r]);
        ll emax = q.getMax();
        ll emin = q.getMin();

        while (emax - emin > k) {
            // remove left most element, increment left pointer
            q.remove();
            l++;

            emax = q.getMax();
            emin = q.getMin();
        }

        // calculate answer
        ans += r - l + 1;
    }

    cout << ans << endl;

    return 0;
}