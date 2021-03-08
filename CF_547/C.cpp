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

    vi p(n+1, 0);
    vi q(n);
    map<int, int> qtd;

    int x; cin >> x;
    int max = x, min = x;
    q[1] = x;
    qtd[x]++;
    for (int i = 2; i <= n-1; i++) {
        cin >> x;
        q[i] = x + q[i-1];
        
        qtd[q[i]]++;

        if (q[i] < min) min = q[i];
        if (q[i] > max) max = q[i];
    }
    
    for (auto e : qtd) if (e.ss > 1 || e.ff == 0) {
        cout << -1 << endl;
        return 0;
    }

    int i;
    for (i = 1; i <= n; i++) {
        p[1] = i;

        if(i+max <= n && i+min > 0) break;
    }

    if (i > n) {
        cout << -1 << endl;
        return 0;
    }

    for (i = 2; i <= n; i++) {
        p[i] = p[1] + q[i-1];
    }

    for (i = 1; i <= n; i++) {
        cout << p[i] << ' ';
    }
    cout << endl;

    return 0;
}