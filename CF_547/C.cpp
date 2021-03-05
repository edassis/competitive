#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vii vector<ii>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ii pair<int,int>
#define ff first
#define ss second

#define PRIME 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vi p(n+1, n);
    vi q(n);

    map<int, int> c;

    int start = 0;
    int min = 1e9;

    for (int i = 1; i < n; i++) {
        cin >> q[i];
        
        if (q[i] < min) {
            min = q[i];
            start = i;
        }
    }

    p[start] = n;

    for (int i = start - 1; i > 0; i--) {
        p[i] = p[i+1] - q[i];
    } 

    for (int i = start + 1; i <= n; i++) {
        p[i] = p[i-1] + q[i-1];
    }

    for (int i = 1; i <= n; i++) {
        if (p[i] > n || p[i] < 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << p[i] << ' ';
    }
    cout << endl;

    return 0;
}