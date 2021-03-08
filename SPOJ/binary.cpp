/**
 * @file binary.cpp
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
#define vii vector<ii>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ii pair<int, int>
#define ff first
#define ss second

#define PRIMO 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vi a(n);    // array
    for (int i = 0; i < n; i++) cin >> a[i];    // putting elements in array.

    for (int i = 0; i < q; i++) {
        int ans = -1;
        int value;
        cin >> value;   // value to search.

        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (a[mid] == value) {  // if encounters the value.
                ans = mid;
                r = mid - 1;    // keeps making the binary search in the left half of the vector.
            } else {
                if (a[mid] < value) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }

        cout << ans << '\n';    // prints index of the first occurrence of the value.
    }

    return 0;
}