/**
 * @file insertion2.cpp
 * @author Eduardo F. Assis (eduardoffassis@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-03-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */
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

/**
 * @brief Returns sorted \b vector from \p a, \p b.
 * 
 * @param a Vector to sort.
 * @param b Vector to sort.
 * @param swap Number of swaps.
 * @return vi Sorted vector.
 */
vi merge(vi &a, vi &b, ll &swap) {
    unsigned i = 0, j = 0;
    vi c;

    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) {
            c.eb(a[i]);
            i++;
        } else {
            c.eb(b[j]);
            j++;
            // If a > b, means that he needed to swap
            // (a.size() + j) len
            // minus c.size();
            swap += a.size() + j - c.size();    // calculates swaps
        }
    }

    while (i < a.size()) {
        c.eb(a[i++]);
    }

    while (j < b.size()) {
        c.eb(b[j++]);
    }

    return c;
}

/**
 * @brief Merge sort function.
 * 
 * @param a 
 * @param swap 
 * @return vi 
 */
vi mergesort(vi &a, ll &swap) {
    if (a.size() == 1) return a;

    vi l(a.begin(), a.begin() + (a.size() / 2));
    vi r(a.begin() + (a.size() / 2), a.end());

    l = mergesort(l, swap);
    r = mergesort(r, swap);

    a = merge(l, r, swap);

    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        vi a(n);

        for (int j = 0; j < n; j++) scanf("%d", &a[j]);

        ll swap = 0;    // swap can be greater than 10^9
        a = mergesort(a, swap);

        printf("%lld\n", swap);
    }

    return 0;
}